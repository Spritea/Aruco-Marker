#include "opencv2/opencv.hpp"
#include <opencv2/aruco.hpp>
using namespace cv;
using namespace aruco;
int main()
{
	Mat markerImage;
    Ptr<aruco::Dictionary> dictionary =getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    drawMarker( dictionary,27, 200, markerImage, 1);
    imwrite("t27.jpg",markerImage);
    imshow("marker",markerImage);
    waitKey(0);
    return 0;
}
