import os
import sp_part
import cla_part
import sys
import shutil
import glob

program_path = '/home/ubuntu/Desktop/Program/'

def main():
    sp_part.sp_execute_splitting()
    cla_part.cla_call()

def debug():
    if sys.argv[1] == "s":
        single_mode()
    elif sys.argv[1] == "m":
        multi_mode()
    else:
        print "unclear debug mode. run single mode instead."
        single_mode()

def single_mode():
    shutil.copyfile(program_path + 'debug/001.jpg', program_path +'capture/001.jpg')
    main()

def multi_mode():
    image_list = glob.glob(program_path+'debug/*.jpg')
    for image in image_list:
        shutil.move(image, program_path+'capture/001.jpg')
        main()



if __name__ == '__main__':
    if len(sys.argv) > 1:
        debug()
    else:
        print "capture is not supported right now. Run single mode instead."
        single_mode()
