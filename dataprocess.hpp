using namespace cv;
Mat calc_flow(const Mat &frame1, const Mat &frame2);
Mat visualize_flow(const Mat &flow);
double calc_flow_index(const Mat &flow);
double mean(double array[], int length);
void save_image(Mat &frame);
