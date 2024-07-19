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
        self.rx, self.ry = 0, 0
        self.zoom = 1
        self.position = None

    def update(self, dt):
        velocity = 100

    def draw(self):
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()

        glScalef(self.zoom,self.zoom,1)
        
        if self.position is not None:
            glTranslatef(*self.position)

        glRotatef(self.rx, 0, 1, 0)
        glRotatef(self.ry, -1, 0, 0)

        glEnableClientState(GL_VERTEX_ARRAY)
        glEnableClientState(GL_COLOR_ARRAY)

        glColorPointer(3, GL_FLOAT, 0, self.colorMatrix)
        glVertexPointer(3, GL_FLOAT, 0, self.vertices)
        glDrawElements(GL_TRIANGLES, len(self.indice), GL_UNSIGNED_INT, self.indice)

        glDisableClientState(GL_COLOR_ARRAY)
        glDisableClientState(GL_VERTEX_ARRAY)

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.rx += dx * 0.5
        self.ry += dy * 0.5
    
    def on_mouse_scroll(self, x, y, scroll_x, scroll_y):
        self.zoom += scroll_y * 0.5