#include <opencv2/videoio.hpp>

using namespace cv;
void init_camera(VideoCapture &cam)
{
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    // open selected camera using selected API
    //std::cout << "Connecting to default cam...\n";
    cam.open(deviceID, apiID);

    if (!cam.isOpened())
        throw std::runtime_error("Camera not found!");
}

Mat take_picture(VideoCapture &cam)
{   
    Mat frame;

    //Grab a frame from the camera
    //std::cout << "Grabbing a picture\n";
    cam.read(frame);

    if (frame.empty())
        throw std::runtime_error("Frame is empty!");
    return frame;
}
