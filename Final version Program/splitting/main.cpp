#include "opencv2/imgproc.hpp"//cvtColor
#include "opencv2/highgui.hpp"//imshow
#include "opencv2/core.hpp"//inRange
//#include "opencv2/features2d.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

bool segment(std::string, int);


int main (int argc, char** argv){
	
	bool segLoop = true;
	
	std::string inum = "001.jpg";
	int onum = 0;

	while(true == segLoop){
		
		segLoop = segment(inum, onum);


		switch(inum[2]){
			case '0':
				inum[2] = '1';
				break;
			case '1':
				inum[2] = '2';
				break;
			case '2':
				inum[2] = '3';
				break;
			case '3':
				inum[2] = '4';
				break;
			case '4':
				inum[2] = '5';
				break;
			case '5':
				inum[2] = '6';
				break;
			case '6':
				inum[2] = '7';
				break;
			case '7':
				inum[2] = '8';
				break;
			case '8':
				inum[2] = '9';
				break;
			case '9':
				inum[2] = '0';
				switch(inum[1]){
					case '0':
						inum[1] = '1';
						break;
					case '1':
						inum[1] = '2';
						break;
					case '2':
						inum[1] = '3';
						break;
					case '3':
						inum[1] = '4';
						break;
					case '4':
						inum[1] = '5';
						break;
					case '5':
						inum[1] = '6';
						break;
					case '6':
						inum[1] = '7';
						break;
					case '7':
						inum[1] = '8';
						break;
					case '8':
						inum[1] = '9';
						break;
					case '9':
						inum[1] = '0';
						switch(inum[0]){
							case '0':
								inum[0] = '1';
								break;
							case '1':
								inum[0] = '2';
								break;
							case '2':
								inum[0] = '3';
								break;
							case '3':
								inum[0] = '4';
								break;
							case '4':
								inum[0] = '5';
								break;
							case '5':
								inum[0] = '6';
								break;
							case '6':
								inum[0] = '7';
								break;
							case '7':
								inum[0] = '8';
								break;
							case '8':
								inum[0] = '9';
								break;
							case '9':
								inum[0] = '0';
								break;
							default:
								break;
						}
				break;
				}
		break;
		}

		
	}
	return 0;
}

bool segment(std::string pInput, int pOutput){

	cv::Rect box;
	cv::RotatedRect rotatedBox;

	int lowH = 0;  //low = 0
	int highH = 89; // max high =179 i think
	
	int lowS = 22;
	int highS = 255; //else high seams to be 255

	int lowV = 31;
	int highV = 145;

	std::ostringstream iName;

	cv::Mat image;
	cv::Mat hsvImage;
	cv::Mat thresholdImage;
	cv::Mat cr;

	std::vector<std::vector<cv::Point> > contours;
	
	std::vector<int> comParams;

		comParams.push_back(CV_IMWRITE_PNG_COMPRESSION);
		comParams.push_back(0);

		
//This part deals with getting the right immage for the input
//
//iname needs to be equal to XXX.JPG
//	jpeg is needing to be in caps
//	also X = num 0-9
//	current set starts at one


	

	image = cv::imread(pInput, CV_LOAD_IMAGE_COLOR);

	if(! image.data){
		std::cout<< "end of pics detected.\n Last pic processed was "<<pInput<<std::endl;
		return false;
	}

	
	//cv::waitKey(0);
	

	
	cv::cvtColor(image, hsvImage, CV_BGR2HSV);


////cv::waitKey(0);
////cv::imshow("Display window", hsvImage);
////cv::waitKey(0);

	cv::inRange(hsvImage, cv::Scalar(lowH, lowS, lowV), cv::Scalar(highH, highS, highV), thresholdImage);

	
////cv::imshow("Display window", thresholdImage);
////cv::waitKey(0);

	cv::dilate(thresholdImage, thresholdImage, cv::Mat(), cv::Point(-1,-1), 2);
	cv::erode(thresholdImage, thresholdImage, cv::Mat(), cv::Point(-1,-1), 4);
	cv::dilate(thresholdImage, thresholdImage, cv::Mat(), cv::Point(-1,-1), 6);
	
////cv::imshow("Display window", thresholdImage);
////cv::waitKey(0);
	
	cv::findContours(thresholdImage, contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
	
//////cv::drawContours(image, contours, -1, (0,0,255), 5);
////cv::imshow("Display window", image);
////cv::waitKey(0);

	
	
	for (int i = 0; i < contours.size(); i++){
		
		std::ostringstream imname;
		imname <<"img"<<pOutput<<".png";

		box = boundingRect(contours[i]);//minAreaRect(contours[i]);/
		cr = cv::Mat(image, box);
		
//////cv::rectangle(image, box, (255,0,0), 3, cv::LINE_8, 0);
		
////cv::imshow("Display window", image);
////cv::waitKey(0);
		
		cv::imwrite(imname.str(), cr, comParams);

		pOutput++;
	}
	//std::cout << contours << std::endl;

	return true;

}
