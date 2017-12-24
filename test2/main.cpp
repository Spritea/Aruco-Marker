#include "opencv2/opencv.hpp"
#include <opencv2/aruco.hpp>
#include<iostream>
using namespace std;
using namespace cv;
using namespace aruco;
int main()
{
	Mat image=imread("/home/ubuntu/aruco/t2.jpg");
    resize(image,image,Size(image.cols/5,image.rows/5));
    Mat imageCopy;
    image.copyTo(imageCopy);
    Ptr<aruco::Dictionary> dictionary =getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f> > corners;
    cv::aruco::detectMarkers(image, dictionary, corners, ids);
    // if at least one marker detected
    cout<<"num "<<ids.size()<<endl;
    if (ids.size() > 0)
    {
        cout<<"num "<<ids.size()<<endl;
        cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
    }

    cv::imshow("out", imageCopy);
    waitKey(0);
    return 0;
}
