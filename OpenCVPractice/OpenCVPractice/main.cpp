#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

int main(int argc, char** argv) {

	if (argc < 1) {
		std::cout << "no cameras attached";
		return 1;
	}

	//camera setup
	cv::VideoCapture stream(0);

	//check that the camera stream is opened
	if (!stream.isOpened()) {
		std::cout << "cannot open camera";
		return 2;
	}

	//get the screen frame
	while (true) {
		cv::Mat cameraFrame;
		stream.read(cameraFrame);
		cv::imshow("cam", cameraFrame);
		if (cv::waitKey(30) >= 0)
			break;
	}

	return 0;
}