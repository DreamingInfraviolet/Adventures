#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define ITERATE_MAT_RGBA(mat, type, expression) \
{ \
  int dr = (mat).cols*4; \
  for(type* rowPtr = (type*)(mat).data; rowPtr<(type*)(mat).dataend; rowPtr+=dr) \
  {   \
      type* lim = rowPtr+(mat).cols*4; \
      for (type* px = rowPtr; px != lim; px+=4) \
	  {   \
	      type* b = px; \
          type* g = px + 1; \
          type* r = px + 2; \
          type* a = px + 3; \
          { \
              expression; \
          } \
	  }   \
  }   \
}

#define ITERATE_MAT_B(mat, type, expression) \
{ \
  for(type* rowPtr = (type*)(mat).data; rowPtr<(type*)(mat).dataend; rowPtr+=(mat).cols) \
  {   \
      type* lim = rowPtr+(mat).cols; \
      for (type* b = rowPtr; b != lim; ++b) \
	  {   \
          { \
              expression; \
          } \
	  }   \
  }   \
}

Mat canny(const Mat& m)
{
	int threshold = 9;
	Mat cannyMat, result;
	cvtColor(m, cannyMat, CV_BGRA2GRAY);
	cannyMat.convertTo(cannyMat, CV_8UC1, 255);
	Canny(cannyMat, result, threshold / 1.0, threshold * 3 / 1.0);
	result.convertTo(result, CV_8UC1);
	return result;
}

double noiseLevel(const Mat& m, const Mat* cannyImag=nullptr)
{
	Mat rst;
	const Mat* resultPtr;
	if (cannyImag == nullptr)
	{
		rst = canny(m);
		resultPtr = &rst;
	}
	else
		resultPtr = cannyImag;

	unsigned whitePixels = 0;
	ITERATE_MAT_B(*resultPtr, unsigned char,
		whitePixels += (int)(*b>128);
		);

	return (double)whitePixels / (resultPtr->cols*resultPtr->rows);
}

int main(int argc, char* argv[])
{
	VideoCapture cap(0); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		cvtColor(frame, frame, CV_BGR2BGRA);
		frame.convertTo(frame, CV_32FC4, 1.0/255.0);


		blur(frame, frame, Size(5,5));

		Mat c = canny(frame);
		cout << noiseLevel(frame, &c)<<"\n";

		imshow("MyVideo", c); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
}