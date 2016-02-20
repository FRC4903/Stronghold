#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0);  // open camera
    if (!cap.isOpened())
    {
        return -1;
    }

    Mat edges, frame;
    namedWindow("Edges", 1);  // This is temporary

    while (true)
    {
        for (;;)
        {
             cap >> frame;  // get new frame from camera
             cvtColor(frame, edges, COLOR_BGR2GRAY);
             GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
             Canny(edges, edges, 0, 30, 3);
             imshow("Edges", edges);  // display to screen, also temp
        }
    }

    return 0;
}