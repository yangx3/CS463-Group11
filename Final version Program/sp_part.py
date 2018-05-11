import os
import shutil
import glob
import subprocess

cap_path = '/home/ubuntu/Desktop/Program/capture'
spl_path = '/home/ubuntu/Desktop/Program/splitting'
cla_path = '/home/ubuntu/Desktop/Program/classifier'
jpg_file = cap_path + '/*.jpg'
png_file = spl_path + '/*.png'

def sp_get_image():
    cap_image_list = glob.glob(jpg_file)
    for files in cap_image_list:
        shutil.move(files, spl_path)
        print "get image from capture"

def sp_move_image():
    splitting_image_list = glob.glob(png_file)
    for files in splitting_image_list:
        shutil.move(files, cla_path)
        print "move " + files + "to classifier."
    if os.path.isfile(spl_path+'/001.jpg'):
        os.remove(spl_path+'/001.jpg')

def sp_call_splitting():
    #do splitting here
    os.chdir('splitting')
    proc = subprocess.Popen('./splitting') #ADD Splitting program here C++
    proc.wait()
    print "splitting"
    os.chdir('..')

def clean():
    for image in glob.glob(png_file):
        if os.path.getsize(image) < 10*1024:
            os.remove(image)
            print "clean small size file " + image


def sp_execute_splitting():
    print "execute splitting program"
    sp_get_image()
    sp_call_splitting()
    clean()
    sp_move_image()
