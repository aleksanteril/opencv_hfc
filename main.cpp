#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace cv;



void init_camera(VideoCapture &cam)
{
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    // open selected camera using selected API
    std::cout << "Connecting to default cam...\n";
    cam.open(deviceID, apiID);

    if (!cam.isOpened())
        throw std::runtime_error("Camera not found!");
}



void take_picture(VideoCapture &cam, Mat &frame)
{   
    //Grab a frame from the camera
    std::cout << "Grabbing a picture\n";
    cam.read(frame);

    if (frame.empty())
        throw std::runtime_error("Frame is empty!");
}



int main(int argc, char** argv )
{
    //Init class and frames variables
    Mat frames[2];
    VideoCapture cap;

    //Activate camera
    try {
        init_camera(cap);
    } 
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    //Grab a frame from the camera
    try {
        take_picture(cap, frames[0]);
    } 
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }  

    imshow("Display Image", frames[0]);
    waitKey(0);
    return 0;
}
