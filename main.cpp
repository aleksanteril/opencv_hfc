#include <opencv2/highgui.hpp> //Includes core
#include "dataprocess.hpp"
#include "camera.hpp"
#include <iostream>

//To develop:
// - image save filepath taken as a program argument from cmd!

using namespace cv;
int main(int argc, char** argv )
{
    //Init class and frames variables
    Mat frames[2];
    Mat flow; //The calculated flow image
    double index[10] = {0};
    double _mean;
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
    int i = 0;
    frames[0] = take_picture(cap);
    while (1) {

        waitKey(10); //Used as a delay for picture capping
        frames[1] = take_picture(cap);

        //Run the farneback flow algorithm to get flow image
        flow = calc_flow(frames[0], frames[1]);

        //Calculate the flow index from the flow image
        index[i] = calc_flow_index(flow);

        double _mean = mean(index, _countof(index));
        
        //If flow index is higher than noise, save the picture
        if (index[i] > _mean*2) {
            save_image(frames[1]);
        }

        //Loop to zero again when over array size
        i++;
        i = i % _countof(index);
    
        frames[0] = frames[1]; //Move next to prev place
    } //While
    
    return 0;
}
