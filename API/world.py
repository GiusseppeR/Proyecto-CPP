import pyglet
from pyglet.gl import *
from objects import Cube, ConvexPolyhedron,Sphere,Axes
import numpy as np

class World:
    def __init__(self):
        self.element = []
        self.files = []
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

            
            convexpoly = ConvexPolyhedron(np.array(self.points))

            self.addModel(convexpoly)            
            self.points.clear()
            self.spheres.clear()

    def addModel(self, model, add_file = True):
        file_name = f"polyhedron_{len(self.element)}.txt"
        if add_file:
            model.add_file(file_name)
        self.element.append(model)
        self.files.append(file_name)

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

        