import pyglet
from pyglet.gl import *
from objects import Cube, Polyhedron
import numpy as np

class World:
    def __init__(self):
        self.element = []

        points = np.random.rand(30, 3)
        self.addModel(Polyhedron(points))

    def update(self, delta_time):
        for obj in self.element:
            obj.update(delta_time)

    def addModel(self, model):
        self.element.append(model)

    def draw(self):
        for obj in self.element:
            obj.draw()

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        for obj in self.element:
            obj.on_mouse_drag(x,y,dx,dy,buttons,modifiers)

    def on_mouse_scroll(self, x, y, scroll_x, scroll_y):
        for obj in self.element:
            obj.on_mouse_scroll(x,y,scroll_x,scroll_y)