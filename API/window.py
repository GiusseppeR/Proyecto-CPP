import pyglet
from pyglet.gl import *
from world import World

class Window(pyglet.window.Window):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        glEnable(GL_DEPTH_TEST)
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
        glClearColor(0.2, 0.2, 0.2, 0.8)
        self.clear()
        self.world.draw()
        self.fps_display.draw()

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.world.on_mouse_drag(x,y,dx,dy,buttons,modifiers)
    
    def on_mouse_scroll(self, x, y, scroll_x, scroll_y):
        self.world.on_mouse_scroll(x,y,scroll_x,scroll_y)
