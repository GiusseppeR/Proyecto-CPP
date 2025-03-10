import pyglet
from pyglet.gl import *
import pyglet.window.mouse
from world import World
import numpy as np
import objects as obj
import re
import ast
import os

class Window(pyglet.window.Window):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        glEnable(GL_DEPTH_TEST)
        glDepthFunc(GL_LESS)
        self.input_text = ""
        self.input_active = False
        self.label = pyglet.text.Label('', font_name='Arial', font_size=24, x=10, y=30, anchor_x='left', anchor_y='center', color=(0, 0, 0, 255))
        self.logs = [pyglet.text.Label('Polyhedra:', font_name='Arial', font_size=10, x=10, y=self.height-30, anchor_x='left', anchor_y='center', color=(0, 0, 0, 255))]
        self.point_label = pyglet.text.Label('Points:', font_name='Arial', font_size=10, x=self.width-150, y=self.height-30, anchor_x='left', anchor_y='center', color=(0, 0, 0, 255))
        self.points_log = [self.point_label]

        self.world = World()
        self.rx,self.ry = 0,0
        self.zoom = 1

    def add_polyhedron_label(self):
        index = len(self.world.element) - 1
        height = self.logs[-1].y - 20
        log = pyglet.text.Label(f"Polyhedron {index}", font_name='Arial', font_size=10, x=10, y=height, anchor_x='left', anchor_y='center', color=(0, 0, 0, 255))
        self.logs.append(log)

    def update_point_label(self):
        self.points_log.clear()
        self.points_log.append(self.point_label)

        for point in self.world.points:
            height = self.points_log[-1].y - 20
            log = pyglet.text.Label(f"Point ({point[0]}, {point[1]}, {point[2]})", font_name='Arial', font_size=10, x=self.width-150, y=height, anchor_x='left', anchor_y='center', color=(0, 0, 0, 255))
            self.points_log.append(log)

    def on_resize(self, width, height):
        glViewport(0, 0, width, height)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        glOrtho(-10, 10, -10, 10, -10, 10)
        glMatrixMode(GL_MODELVIEW)
        return pyglet.event.EVENT_HANDLED

    def on_draw(self):
        glClearColor(1, 1, 1, 0.8)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        gluOrtho2D(0, self.width, 0, self.height)  
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()

        self.label.text = self.input_text
        self.label.draw()

        for log in self.logs:
            log.draw()
        for log in self.points_log:
            log.draw()

        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        gluPerspective(60, self.width / self.height, 0.1, 500)  
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
        gluLookAt(5, 5, 5,  # Camera position
                0, 0, 0,  # Look at the origin
                0, 1, 0)  # Up vector

        glScalef(self.zoom, self.zoom, 1)
        glRotatef(self.rx, 0, 1, 0)
        glRotatef(self.ry, -1, 0, 0)

        self.world.draw()
        
    def execute_command(self,string):
        add_point = r'^pt (-?\d*\.\d+|-?\d+),(-?\d*\.\d+|-?\d+),(-?\d*\.\d+|-?\d+)$'
        is_inside = r'^is\sinside (-?\d*\.\d+|-?\d+),(-?\d*\.\d+|-?\d+),(-?\d*\.\d+|-?\d+)$'
        cube = "cube"
        random_poly = "rd poly"
        move = r'^move (\d+) (-?\d*\.\d+|-?\d+),(-?\d*\.\d+|-?\d+),(-?\d*\.\d+|-?\d+)$'
        non_convex_test = "nonconvex poly"
        intersection = "intersect"
        union = "union"
        

        if re.match(add_point,string):
            x_str, y_str, z_str = re.match(add_point,string).groups()

            x = float(x_str)
            y = float(y_str)
            z = float(z_str)

            self.world.add_point((x,y,z))
            self.update_point_label()
            return
        
        if string == cube:
            self.world.addModel(obj.Cube(), 0)
            self.add_polyhedron_label()
            self.update_point_label()
            return

        if string == random_poly:
            points = np.random.uniform(-1, 1,(30,3))
            self.world.addModel(obj.ConvexPolyhedron(points))
            self.add_polyhedron_label()
            self.update_point_label()
            return
        
        if re.match(move,string):
            i_str, x_str, y_str, z_str = re.match(move,string).groups()

            i = int(i_str)

            x = float(x_str)
            y = float(y_str)
            z = float(z_str)

            self.world.move_element(i,(x,y,z))
            return
        
        if string == non_convex_test:
            self.world.addModel(obj.Polyhedron())
            self.add_polyhedron_label()
            self.update_point_label()
            return
        
        if string == intersection:
            dir_path = os.path.dirname(os.path.realpath(__file__))
            
            output = f"{dir_path}/intersect_api.txt"
            file = self.world.files
            os.system(f"cd {dir_path}/../cmake-build-release && Proyecto.exe intersect {dir_path}/{file[-1]} {dir_path}/{file[-2]} {output}")
            self.world.element = self.world.element[:-2]

            with open(output, 'r') as file:
                data = file.read()
            
            array = ast.literal_eval(data)
            points = np.array(array)
            points = np.unique(points, axis=0)
            self.world.addModel(obj.ConvexPolyhedron(points), 0)
            return

        if string == union:
            dir_path = os.path.dirname(os.path.realpath(__file__))
            
            output = f"{dir_path}/union_api.txt"
            file = self.world.files
            os.system(f"cd {dir_path}/../cmake-build-release && Proyecto.exe union {dir_path}/{file[-1]} {dir_path}/{file[-2]} {output}")
            self.world.element = self.world.element[:-2]

            with open(output, 'r') as file:
                data = file.read()
            
            array = ast.literal_eval(data)
            self.world.addModel(obj.Polyhedron(array), 0)
            return
        
        if string == "clear":
            self.world.element = []
            self.world.files = []
            return

        if string == "volume":
            dir_path = os.path.dirname(os.path.realpath(__file__))
            output = f"{dir_path}/volume.txt"
            file = self.world.files[-1]
            os.system(f"cd {dir_path}/../cmake-build-release && Proyecto.exe volume {dir_path}/{file} {output}")
            
            with open(output, 'r') as file:
                data = file.read()
            print(data)
            return
        
        if re.match(is_inside,string):
            x_str, y_str, z_str = re.match(is_inside,string).groups()

            dir_path = os.path.dirname(os.path.realpath(__file__))
            output = f"{dir_path}/inside.txt"
            file = self.world.files[-1]
            os.system(f"cd {dir_path}/../cmake-build-release && Proyecto.exe is_inside {dir_path}/{file} {x_str} {y_str} {z_str} {output}")

            with open(output, 'r') as file:
                data = file.read()
            if int(data):
                print("is inside")
            else:
                print("is outside")
            return



    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.rx += dx * 0.5
        self.ry += dy * 0.5
    
    def on_mouse_scroll(self, x, y, scroll_x, scroll_y):
        self.zoom += scroll_y * 0.1

    def on_text(self,text):
        if self.input_active and text != '  ':
            self.input_text += text

    def on_key_press(self,symbol, modifiers):
        if symbol == pyglet.window.key.TAB:
            self.input_active = not self.input_active
        if symbol == pyglet.window.key.BACKSPACE and self.input_text and self.input_active:
            self.input_text = self.input_text[:-1]
        if symbol == pyglet.window.key.ENTER and self.input_active:
            self.execute_command(self.input_text)
        if symbol == pyglet.window.key.SPACE and not self.input_active:
            self.world.consolidate_points()
            self.add_polyhedron_label()
            self.update_point_label()
        if symbol == pyglet.window.key.ESCAPE:
            self.close()
    
    def on_key_release(self, symbol, modifiers):
        if symbol == pyglet.window.key.ENTER and self.input_active:
            self.input_text = ""