#include <opencv2/video.hpp>
#include <opencv2/imgproc.hpp>
#include "dataprocess.hpp"

using namespace cv;

// For visualising the data mainly for testing!
Mat visualize_flow(const Mat &flow)
{
    // visualization
    Mat flow_parts[2];
    split(flow, flow_parts);
    Mat magnitude, angle, magn_norm;
    cartToPolar(flow_parts[0], flow_parts[1], magnitude, angle, true);
    normalize(magnitude, magn_norm, 0.0f, 1.0f, NORM_MINMAX);
    angle *= ((1.f / 360.f) * (180.f / 255.f));

    //build hsv image
    Mat _hsv[3], hsv, hsv8, bgr;
    _hsv[0] = angle;
    _hsv[1] = Mat::ones(angle.size(), CV_32F);
    _hsv[2] = magn_norm;
    merge(_hsv, 3, hsv);
    hsv.convertTo(hsv8, CV_8U, 255.0);
    cvtColor(hsv8, bgr, COLOR_HSV2BGR);

    return bgr;
}

Mat calc_flow(const Mat &frame1, const Mat &frame2)
{
    Mat next;
    Mat prev;
    cvtColor(frame1, prev, COLOR_BGR2GRAY);
    cvtColor(frame2, next, COLOR_BGR2GRAY);

    Mat flow;
    calcOpticalFlowFarneback(prev, next, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
    return flow;
}


double calc_flow_index(const Mat &flow)
{
    Mat flow_parts[2];
    Mat vectors;
    split(flow, flow_parts);
    magnitude(flow_parts[0], flow_parts[1], vectors);
    double index = mean(vectors)[0];
    return index;
}
