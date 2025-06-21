#include <opencv2/highgui.hpp> //Includes core
#include "dataprocess.hpp"
#include "camera.hpp"
#include <iostream>

using namespace cv;
int main(int argc, char** argv )
{
    //Init class and frames variables
    Mat frames[2];
    Mat flow; //The calculated flow image
    VideoCapture cap;

    //Activate camera
    try {
        init_camera(cap);
    } 
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1; //Exit if no success
    }

    //Start taking pictures and doing optical flow calculations
    frames[0] = take_picture(cap);
    while (waitKey(5) < 0) {
        frames[1] = take_picture(cap);
        flow = calc_flow(frames[0], frames[1]);
        imshow("Screen", visualize_flow(flow));
        frames[0] = frames[1]; //Move next to prev place
    } //While
    
    return 0;
}
