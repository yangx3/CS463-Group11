import os
import glob

path = '/home/ubuntu/Desktop/Program/'

if os.path.exists(path+'splitting/001.jpg'):
    os.chdir('splitting')
    os.remove('001.jpg')
    os.chdir('..')

if os.listdir(path +'classifier') != []:
    for f in glob.glob(path+'classifier/*'):
	    os.remove(f)
