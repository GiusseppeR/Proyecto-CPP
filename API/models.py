import pyglet
from pyglet.gl import *

def vector(type, *args):
    '''
        return a ctype array
        GLfloat
        GLuint
        ...
    '''
    return (type*len(args))(*args)

class Model:
    def __init__(self, vertices, colorMatrix, indice):
        self.vertices = vector(GLfloat, *vertices)
        self.colorMatrix = vector(GLfloat, *colorMatrix)
        self.indice = vector(GLuint, *indice)

    def draw(self):
        glEnableClientState(GL_VERTEX_ARRAY)
        glEnableClientState(GL_COLOR_ARRAY)

        glColorPointer(3, GL_FLOAT, 0, self.colorMatrix)
        glVertexPointer(3, GL_FLOAT, 0, self.vertices)
        glDrawElements(GL_TRIANGLES, len(self.indice), GL_UNSIGNED_INT, self.indice)

        glDisableClientState(GL_COLOR_ARRAY)
        glDisableClientState(GL_VERTEX_ARRAY)

    def move(self,vector):
        for i in range(len(self.vertices)):
            self.vertices[i] += vector[i % 3]
