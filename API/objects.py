import pyglet
import numpy as np
from pyglet.gl import *
from models import Model
from scipy.spatial import ConvexHull
import os

class Cube(Model):
    def __init__(self):
        cube = (
            1, 1, 1,    #0
            -1, 1, 1,   #1
            -1, -1, 1,  #2
            1, -1, 1,   #3
            1, 1, -1,   #4
            -1, 1, -1,  #5
            -1, -1, -1, #6
            1, -1, -1   #7
        )

        color = (
            # Front face
            1, 0, 0,   # Red
            1, 0, 0,   # Red
            1, 0, 0,   # Red
            1, 0, 0,   # Red

            # Top face
            0, 1, 0,   # Green
            0, 1, 0,   # Green
            0, 1, 0,   # Green
            0, 1, 0,   # Green

            # Right face
            0, 0, 1,   # Blue
            0, 0, 1,   # Blue
            0, 0, 1,   # Blue
            0, 0, 1,   # Blue

            # Left face
            1, 1, 0,   # Yellow
            1, 1, 0,   # Yellow
            1, 1, 0,   # Yellow
            1, 1, 0,   # Yellow

            # Bottom face
            1, 0, 1,   # Magenta
            1, 0, 1,   # Magenta
            1, 0, 1,   # Magenta
            1, 0, 1,   # Magenta

            # Back face
            0, 1, 1,   # Cyan
            0, 1, 1,   # Cyan
            0, 1, 1,   # Cyan
            0, 1, 1    # Cyan
        )

        indices= (
            0, 1, 2,   0, 2, 3,  # front face
            0, 4, 5,   0, 5, 1,  # top face
            4, 0, 3,   4, 3, 7,  # right face
            1, 5, 6,   1, 6, 2,  # left face
            3, 2, 6,   3, 6, 7,  # bottom face
            4, 7, 6,   4, 6, 5   # back face
        )

        super().__init__(cube, color, indices)

class ConvexPolyhedron(Model):
    def __init__(self, points):
        self.points = points
        hull = ConvexHull(points)
        self.hull = hull

        vertices = []
        colors = []
        face_colors = [
            (1, 0, 0),  # Red
            (0, 1, 0),  # Green
            (0, 0, 1),  # Blue
            (1, 1, 0),  # Yellow
            (1, 0, 1),  # Magenta
            (0, 1, 1),  # Cyan
        ]

        for face_index, simplex in enumerate(hull.simplices):
            color = face_colors[face_index % len(face_colors)] 
            for vertex in simplex:
                vertices.append(points[vertex])
                colors.extend(color)

        vertices = tuple([float(coord) for vertex in vertices for coord in vertex])
        colors = tuple(colors)

        num_vertices = len(vertices) // 3  
        indices = tuple(range(num_vertices))

        super().__init__(vertices, colors, indices)

    def add_file(self, file_name):
        if len(file_name):
            dir_path = os.path.dirname(os.path.realpath(__file__))
            file = open(f"{dir_path}/{file_name}", "w")

            for s in self.hull.simplices:
                file.write(f"{self.points[s[0]]},{self.points[s[1]]},{self.points[s[2]]}\n")  
            file.close()

class Polyhedron(Model):
    vertex_test = [[(-0.5,-0.5,-0.5),(0.5,-0.5,-0.5),(0.5,0.5,-0.5)],
                    [(-0.5,-0.5,-0.5),(0.5,0.5,-0.5),(-0.5,0.5,-0.5)],
                    [(-0.5,-0.5,0.5),(0.5,-0.5,0.5),(0.5,0.5,0.5)],
                    [(-0.5,-0.5,0.5),(0.5,0.5,0.5),(-0.5,0.5,0.5)],
                    [(-0.5,-0.5,-0.5),(0.5,-0.5,-0.5),(0.5,-0.5,0.5)],
                    [(-0.5,-0.5,-0.5),(0.5,-0.5,0.5),(-0.5,-0.5,0.5)],
                    [(-0.5,0.5,-0.5),(0.5,0.5,-0.5),(0.5,0.5,0.5)],
                    [(-0.5,0.5,-0.5),(0.5,0.5,0.5),(-0.5,0.5,0.5)],
                    [(-0.5,-0.25,-0.25),(-0.5,-0.05,-0.25),(-0.5,-0.5,-0.5)],
                    [(-0.5,-0.05,-0.25),(-0.5,0.5,-0.5),(-0.5,-0.5,-0.5)],
                    [(-0.5,-0.05,-0.25),(-0.5,0.25,-0.25),(-0.5,-0.5,-0.5)],
                    [(-0.5,0.25,-0.25),(-0.5,0.5,-0.5),(-0.5,-0.5,-0.5)],
                    [(-0.5,0.5,-0.5),(-0.5,0.5,0.5),(-0.5,0.25,-0.25)],
                    [(-0.5,0.25,-0.25),(-0.5,0.25,-0.05),(-0.5,0.5,-0.5)],
                    [(-0.5,0.25,-0.05),(-0.5,0.5,0.5),(-0.5,0.5,-0.5)],
                    [(-0.5,0.25,-0.05),(-0.5,0.25,0.25),(-0.5,0.5,-0.5)],
                    [(-0.5,0.25,0.25),(-0.5,0.5,0.5),(-0.5,0.5,-0.5)],
                    [(-0.5,-0.25,0.25),(-0.5,-0.05,0.25),(-0.5,-0.5,0.5)],
                    [(-0.5,-0.05,0.25),(-0.5,0.5,0.5),(-0.5,-0.5,0.5)],
                    [(-0.5,-0.05,0.25),(-0.5,0.25,0.25),(-0.5,-0.5,0.5)],
                    [(-0.5,0.25,0.25),(-0.5,0.5,0.5),(-0.5,-0.5,0.5)],
                    [(-0.5,-0.25,-0.25),(-0.5,-0.25,-0.05),(-0.5,-0.5,-0.5)],
                    [(-0.5,-0.25,-0.05),(-0.5,-0.5,0.5),(-0.5,-0.5,-0.5)],
                    [(-0.5,-0.25,-0.05),(-0.5,-0.25,0.25),(-0.5,-0.5,-0.5)],
                    [(-0.5,-0.25,0.25),(-0.5,-0.5,0.5),(-0.5,-0.5,-0.5)],
                    [(-0.5,-0.5,0.5),(-0.5,0.5,0.5),(-0.5,-0.25,0.25)],
                    [(0.5,-0.25,-0.25),(0.5,0.05,-0.25),(0.5,-0.5,-0.5)],
                    [(0.5,0.05,-0.25),(0.5,0.5,-0.5),(0.5,-0.5,-0.5)],
                    [(0.5,0.05,-0.25),(0.5,0.25,-0.25),(0.5,-0.5,-0.5)],
                    [(0.5,0.25,-0.25),(0.5,0.5,-0.5),(0.5,-0.5,-0.5)],
                    [(0.5,0.5,-0.5),(0.5,0.5,0.5),(0.5,0.25,-0.25)],
                    [(0.5,0.25,-0.25),(0.5,0.25,0.05),(0.5,0.5,-0.5)],
                    [(0.5,0.25,0.05),(0.5,0.5,0.5),(0.5,0.5,-0.5)],
                    [(0.5,0.25,0.05),(0.5,0.25,0.25),(0.5,0.5,-0.5)],
                    [(0.5,0.25,0.25),(0.5,0.5,0.5),(0.5,0.5,-0.5)],
                    [(0.5,-0.25,0.25),(0.5,0.05,0.25),(0.5,-0.5,0.5)],
                    [(0.5,0.05,0.25),(0.5,0.5,0.5),(0.5,-0.5,0.5)],
                    [(0.5,0.05,0.25),(0.5,0.25,0.25),(0.5,-0.5,0.5)],
                    [(0.5,0.25,0.25),(0.5,0.5,0.5),(0.5,-0.5,0.5)],
                    [(0.5,-0.25,-0.25),(0.5,-0.25,0.05),(0.5,-0.5,-0.5)],
                    [(0.5,-0.25,0.05),(0.5,-0.5,0.5),(0.5,-0.5,-0.5)],
                    [(0.5,-0.25,0.05),(0.5,-0.25,0.25),(0.5,-0.5,-0.5)],
                    [(0.5,-0.25,0.25),(0.5,-0.5,0.5),(0.5,-0.5,-0.5)],
                    [(0.5,-0.5,0.5),(0.5,0.5,0.5),(0.5,-0.25,0.25)],
                    [(-0.5,-0.25,-0.25),(-0.5,-0.05,-0.25),(-2.5,-0.25,-0.25)],
                    [(0.5,-0.25,-0.25),(0.5,0.05,-0.25),(2.5,-0.25,-0.25)],
                    [(0.5,0.05,-0.25),(2.5,0.25,-0.25),(2.5,-0.25,-0.25)],
                    [(-0.5,-0.05,-0.25),(-0.5,0.25,-0.25),(-2.5,-0.25,-0.25)],
                    [(-0.5,0.25,-0.25),(-2.5,0.25,-0.25),(-2.5,-0.25,-0.25)],
                    [(0.5,0.05,-0.25),(0.5,0.25,-0.25),(2.5,0.25,-0.25)],
                    [(-0.5,-0.25,0.25),(-0.5,-0.05,0.25),(-2.5,-0.25,0.25)],
                    [(0.5,-0.25,0.25),(0.5,0.05,0.25),(2.5,-0.25,0.25)],
                    [(0.5,0.05,0.25),(2.5,0.25,0.25),(2.5,-0.25,0.25)],
                    [(-0.5,-0.05,0.25),(-0.5,0.25,0.25),(-2.5,-0.25,0.25)],
                    [(-0.5,0.25,0.25),(-2.5,0.25,0.25),(-2.5,-0.25,0.25)],
                    [(0.5,0.05,0.25),(0.5,0.25,0.25),(2.5,0.25,0.25)],
                    [(-0.5,-0.25,-0.25),(-0.5,-0.25,-0.05),(-2.5,-0.25,-0.25)],
                    [(0.5,-0.25,-0.25),(0.5,-0.25,0.05),(2.5,-0.25,-0.25)],
                    [(0.5,-0.25,0.05),(2.5,-0.25,0.25),(2.5,-0.25,-0.25)],
                    [(-0.5,-0.25,-0.05),(-0.5,-0.25,0.25),(-2.5,-0.25,-0.25)],
                    [(-0.5,-0.25,0.25),(-2.5,-0.25,0.25),(-2.5,-0.25,-0.25)],
                    [(0.5,-0.25,0.05),(0.5,-0.25,0.25),(2.5,-0.25,0.25)],
                    [(-0.5,0.25,-0.25),(-0.5,0.25,-0.05),(-2.5,0.25,-0.25)],
                    [(0.5,0.25,-0.25),(0.5,0.25,0.05),(2.5,0.25,-0.25)],
                    [(0.5,0.25,0.05),(2.5,0.25,0.25),(2.5,0.25,-0.25)],
                    [(-0.5,0.25,-0.05),(-0.5,0.25,0.25),(-2.5,0.25,-0.25)],
                    [(-0.5,0.25,0.25),(-2.5,0.25,0.25),(-2.5,0.25,-0.25)],
                    [(0.5,0.25,0.05),(0.5,0.25,0.25),(2.5,0.25,0.25)],
                    [(-2.5,-0.25,-0.25),(-2.5,0.25,-0.25),(-2.5,0.25,0.25)],
                    [(-2.5,-0.25,-0.25),(-2.5,0.25,0.25),(-2.5,-0.25,0.25)],
                    [(2.5,-0.25,-0.25),(2.5,0.25,-0.25),(2.5,0.25,0.25)],
                    [(2.5,-0.25,-0.25),(2.5,0.25,0.25),(2.5,-0.25,0.25)]]
    def __init__(self, triangles = vertex_test):
        vertices = []
        colors = []
        face_colors = [
            (1, 0, 0),  # Red
            (0, 1, 0),  # Green
            (0, 0, 1),  # Blue
            (1, 1, 0),  # Yellow
            (1, 0, 1),  # Magenta
            (0, 1, 1),  # Cyan
        ]

        for face_index, triangle in enumerate(triangles):
            color = face_colors[face_index % len(face_colors)]
            for vertex in triangle:
                vertices.extend(vertex)
                colors.extend(color)

        colors = tuple(colors)
        num_vertices = len(vertices) // 3  
        indices = tuple(range(num_vertices))
        super().__init__(vertices, colors, indices)

class Sphere(Model):
    def __init__(self, position, radius=0.05, slices=16, stacks=16):
        self.vertices, self.indices = self.generate_sphere(position, radius, slices, stacks)
        self.colors = [(0, 0, 0) for _ in self.vertices]  # Black color for all vertices
        flat_vertices = [coord for vertex in self.vertices for coord in vertex]
        flat_colors = [color for c in self.colors for color in c]
        super().__init__(tuple(flat_vertices), tuple(flat_colors), tuple(self.indices))

    def generate_sphere(self, position, radius, slices, stacks):
        vertices = []
        indices = []

        for i in range(stacks + 1):
            lat = np.pi / 2 - i * np.pi / stacks  # latitude
            for j in range(slices + 1):
                lon = 2 * np.pi * j / slices  # longitude
                x = position[0] + radius * np.cos(lat) * np.cos(lon)
                y = position[1] + radius * np.cos(lat) * np.sin(lon)
                z = position[2] + radius * np.sin(lat)
                vertices.append((x, y, z))

        for i in range(stacks):
            for j in range(slices):
                first = i * (slices + 1) + j
                second = first + slices + 1
                indices.append(first)
                indices.append(second)
                indices.append(first + 1)

                indices.append(second)
                indices.append(second + 1)
                indices.append(first + 1)

        return vertices, indices

class Axes:
    def draw(self):
        glBegin(GL_LINES)

        glColor3f(1, 0, 0)
        glVertex3f(-10, 0, 0)
        glVertex3f(10, 0, 0)
        
        glColor3f(0, 1, 0)
        glVertex3f(0, -10, 0)
        glVertex3f(0, 10, 0)

        glColor3f(0, 0, 1)
        glVertex3f(0, 0, -10)
        glVertex3f(0, 0, 10)

        glEnd()