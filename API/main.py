import sys
import pyglet
from window import Window
import json
import os



def main(*args, **kwargs):
        # Data to be written
    dictionary = {
        "name": "sathiyajith",
        "rollno": 56,
        "cgpa": 8.6,
        "phonenumber": "9976770500"
    }

    
    config = pyglet.gl.Config(double_buffer=True, depth_size=24)
    window = Window(fullscreen=False, vsync=True, resizable=True, 
                    height=600, width=600, caption="API", config= config)

    frames_per_second = 60.0
    pyglet.clock.schedule_interval(window.world.update, 1.0 / frames_per_second)
    pyglet.app.run()

if __name__ == "__main__":
    main(sys.argv)
