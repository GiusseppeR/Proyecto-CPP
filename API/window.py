import pyglet
from pyglet.gl import *
from world import World
import numpy as np
from ctypes import pointer, c_double, c_float, c_int

class Window(pyglet.window.Window):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        glEnable(GL_DEPTH_TEST)
        glDepthFunc(GL_LESS)
        self.fps_display = pyglet.window.FPSDisplay(self)
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
        glClearColor(1,1,1, 0.8)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()

        glScalef(self.zoom,self.zoom,1)
        glRotatef(self.rx, 0, 1, 0)
        glRotatef(self.ry, -1, 0, 0)
        self.world.draw()
        self.fps_display.draw()
    
    def on_key_press(self, symbol, modifiers):
        if symbol == pyglet.window.key.SPACE:
            self.world.consolidate_points()

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.rx += dx * 0.5
        self.ry += dy * 0.5
    
    def on_mouse_scroll(self, x, y, scroll_x, scroll_y):
        self.zoom += scroll_y * 0.5

    def on_mouse_press(self, x, y, button, modifiers):
        if button == pyglet.window.mouse.RIGHT:
            world_coords = self.get_world_coords(x, y)
            if world_coords:
                self.world.add_point(world_coords)
            print(world_coords)
    
    def get_matrix(self,matrix_type):
        matrix = (GLfloat * 16)()
        glGetFloatv(matrix_type, matrix)
        return np.array(matrix, dtype=np.float32).reshape(4, 4)
    
    def get_world_coords(self, x, y):
        width, height = self.width, self.height
        x_ndc = (2 * x / width) - 1
        y_ndc = 1 - (2 * y / height)
        vector = np.array([x_ndc,-y_ndc,0.1,1])

        proj_matrix = self.get_matrix(GL_PROJECTION_MATRIX)
        view_matrix = self.get_matrix(GL_MODELVIEW_MATRIX)

        mat = np.matmul(view_matrix, np.linalg.inv(proj_matrix))
        direction = np.dot(np.transpose(mat),vector)
        direction /= mat[0][3] + mat[1][3] + mat[2][3] + mat[3][3]
        direction[2] -= 1
        
        return tuple(direction[:3])
        
