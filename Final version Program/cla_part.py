import os
import shutil
import glob
import subprocess


cap_path = '/home/ubuntu/Desktop/Program/capture'
spl_path = '/home/ubuntu/Desktop/Program/splitting'
cla_path = '/home/ubuntu/Desktop/Program/classifier'
jpg_file = cap_path + '/*.jpg'
png_file = cla_path + '/*.png'


def cla_loop():
    imagelist = glob.glob(png_file)
    for image in imagelist:
        cla_execute(image)
        print "classify " + image + " complete"
        os.remove(image)


def cla_execute(image):
    os.chdir('keras-transfer-learning')
    proc = subprocess.call(['python', 'predict.py','--path', image, '--model=resnet50'])
    os.chdir('..')
    if proc == 1:
        print "Memory crashing!"
        exit(1)

def cla_call():
    cla_loop()