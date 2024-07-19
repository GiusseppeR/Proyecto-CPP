import pyglet
from pyglet.gl import *
from objects import Cube, Polyhedron,Sphere
import numpy as np

class World:
    def __init__(self):
        self.element = []
        self.points = []
        self.spheres = []
        self.rx,self.ry = 0, 0
        self.zoom = 1

    def update(self, delta_time):
        for obj in self.element:
            obj.update(delta_time)
    
    def add_point(self, point):
        self.points.append(point)
        self.element.append(Sphere(point))

    def consolidate_points(self):
        if len(self.points) > 3:
            self.element.append(Polyhedron(np.array(self.points)))
            self.points.clear()

    def addModel(self, model):
        self.element.append(model)

    def draw(self):
        self.draw_axes()
        for obj in self.element:
            obj.draw()

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.rx += dx * 0.5
        self.ry += dy * 0.5
        for obj in self.element:
            obj.on_mouse_drag(x,y,dx,dy,buttons,modifiers)

    def on_mouse_scroll(self, x, y, scroll_x, scroll_y):
        self.zoom += scroll_y * 0.5
        for obj in self.element:
            obj.on_mouse_scroll(x,y,scroll_x,scroll_y)
    
    def draw_axes(self):
        glBegin(GL_LINES)

        # X axis in red
        glColor3f(1, 0, 0)
        glVertex3f(-10, 0, 0)
        glVertex3f(10, 0, 0)
        
        # Y axis in green
        glColor3f(0, 1, 0)
        glVertex3f(0, -10, 0)
        glVertex3f(0, 10, 0)
        
        # Z axis in blue
        glColor3f(0, 0, 1)
        glVertex3f(0, 0, -10)
        glVertex3f(0, 0, 10)

        glEnd()
        