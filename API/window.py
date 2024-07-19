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
        self.world.draw()
        self.fps_display.draw()
    
    def on_key_press(self, symbol, modifiers):
        if symbol == pyglet.window.key.SPACE:
            self.world.consolidate_points()

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.world.on_mouse_drag(x,y,dx,dy,buttons,modifiers)
    
    def on_mouse_scroll(self, x, y, scroll_x, scroll_y):
        self.world.on_mouse_scroll(x,y,scroll_x,scroll_y)

    def on_mouse_press(self, x, y, button, modifiers):
        if button == pyglet.window.mouse.RIGHT:
            world_coords = self.get_world_coords(x, y)
            if world_coords:
                self.world.add_point(world_coords)
            print(world_coords)
    
    def get_matrix(self,matrix_type):
        # Create a ctypes buffer
        matrix = (GLfloat * 16)()
        
        # Retrieve the matrix data from OpenGL
        glGetFloatv(matrix_type, matrix)
        
        # Convert the ctypes buffer to a NumPy array
        return np.array(matrix, dtype=np.float32).reshape(4, 4)
    
    def get_world_coords(self, x, y):
        width, height = self.width, self.height
        x_ndc = (2 * x / width) - 1
        y_ndc = 1 - (2 * y / height)
        z_ndc = 1  # Typically for selecting in the far plane, adjust as needed
        proj_matrix = self.get_matrix(GL_PROJECTION_MATRIX)
        view_matrix = self.get_matrix(GL_MODELVIEW_MATRIX)
        
        # Combine projection and view matrices
        proj_view_matrix = np.dot(proj_matrix, view_matrix)
        
        # Compute inverse of the combined matrix
        inv_proj_view_matrix = np.linalg.inv(proj_view_matrix)
        
        # Convert NDC to homogeneous clip coordinates
        clip_coords = np.array([x_ndc, y_ndc, z_ndc, 1.0], dtype=np.float32)
        
        # Transform to eye coordinates
        eye_coords = np.dot(inv_proj_view_matrix, clip_coords)
        eye_coords /= eye_coords[3]  

        return tuple(eye_coords[:3])
        
