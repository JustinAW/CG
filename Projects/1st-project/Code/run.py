import subprocess

tmp = subprocess.call(["gcc", "weiglej-p1.c", "-lglut", "-lGLU", "-lGL"])
if(tmp == 0):
    subprocess.call("./a.out")
