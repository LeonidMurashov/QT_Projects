

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
static void help()
{
    cout << "\nThis program demonstrates circle finding with the Hough transform.\n"
        "Usage:\n"
        "./houghcircles <image_name>, Default is ../data/board.jpg\n" << endl;
}
int main(int argc, char** argv)
{
    VideoCapture cam(0);

    Mat img;
    for (;;)
    {
        cam >> img;


        Mat cimg;
        cvtColor(img, cimg, COLOR_BGR2GRAY);
        //GaussianBlur(cimg, cimg, Size(9, 9), 2, 2);

        vector<Vec3f> circles;
        HoughCircles(cimg, circles, HOUGH_GRADIENT, 1, 30,
            90, 50, 10, 100 // change the last two parameters
                           // (min_radius & max_radius) to detect larger circles
            );
        for (size_t i = 0; i < circles.size(); i++)
        {
            Vec3i c = circles[i];
            circle(cimg, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 3, LINE_AA);
            circle(cimg, Point(c[0], c[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);

            circle(img, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 3, LINE_AA);
            circle(img, Point(c[0], c[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);
        }
        imshow("detected circles", cimg);
        imshow("orignal", img);
        int key = waitKey(1);
        if (key == 27) break;
    }
    return 0;
}
