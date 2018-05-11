import cv2


def main():
    cap = cv2.VideoCapture(0)
    cap.set(3, 1280)
    cap.set(4, 1024)
    
    ret, frame = cap.read()
    cv2.imwrite('001.jpg', frame)
    cap.release()
    cv2.destroyAllwindows


if __name__ == '__main__':
    main()
