import pyglet
from pyglet.gl import *
from objects import Cube, ConvexPolyhedron,Sphere,Axes
import numpy as np

class World:
    def __init__(self):
        self.element = []
        self.points = []
        self.spheres = []
        self.axes = Axes()
    
    def update(self,dt):
        pass

    def add_point(self, point):
        self.points.append(point)
        self.spheres.append(Sphere(point))

    def consolidate_points(self):
        if len(self.points) > 3:
            self.element.append(ConvexPolyhedron(np.array(self.points)))
            self.points.clear()
            self.spheres.clear()

    def addModel(self, model):
        self.element.append(model)

    def draw(self):
        self.axes.draw()
        for obj in self.element:
            obj.draw()
        for p in self.spheres:
            p.draw()

    def move_element(self,index,vector):
        if index not in range(len(self.element)):
            return
        self.element[index].move(vector)

        