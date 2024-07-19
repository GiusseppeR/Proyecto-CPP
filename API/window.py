import pyglet
from pyglet.gl import *
import pyglet.window.mouse
from world import World
import numpy as np
import objects as obj
import re

class Window(pyglet.window.Window):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        glEnable(GL_DEPTH_TEST)
        glDepthFunc(GL_LESS)
        self.input_text = ""
        self.input_active = False
        self.label = pyglet.text.Label('', font_name='Arial', font_size=24, x=10, y=30, anchor_x='left', anchor_y='center', color=(0, 0, 0, 255))

        self.world = World()
        self.rx,self.ry = 0,0
        self.zoom = 1

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

        # Set up the projection and modelview matrices
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        gluOrtho2D(0, self.width, 0, self.height)  # For 2D drawing
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()

        self.label.text = self.input_text
        self.label.draw()

        # Draw 3D world and other elements
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        gluPerspective(60, self.width / self.height, 0.1, 500)  # Perspective projection
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
        cube = "cube"
        random_poly = "rd poly"

        if re.match(add_point,string):
            x_str, y_str, z_str = re.match(add_point,string).groups()

            x = float(x_str)
            y = float(y_str)
            z = float(z_str)

            self.world.add_point((x,y,z))
            print(x,y,z)
        
        if string == cube:
            self.world.addModel(obj.Cube())

        if string == random_poly:
            points = np.random.uniform(-1, 1,(30,3))
            self.world.addModel(obj.Polyhedron(points))

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.rx += dx * 0.5
        self.ry += dy * 0.5
    
    def on_mouse_scroll(self, x, y, scroll_x, scroll_y):
        self.zoom += scroll_y * 0.1

    def on_text(self,text):
        if self.input_active:
            self.input_text += text

    def on_key_press(self,symbol, modifiers):
        if symbol == pyglet.window.key.TAB:
            self.input_active = not self.input_active
        if symbol == pyglet.window.key.BACKSPACE and self.input_text and self.input_active:
            self.input_text = self.input_text[:-1]
        if symbol == pyglet.window.key.ENTER and self.input_active:
            self.execute_command(self.input_text)
            self.input_text = ""
        if symbol == pyglet.window.key.SPACE and not self.input_active:
            self.world.consolidate_points()
