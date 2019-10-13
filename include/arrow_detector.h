#include <iostream>
#include <stdio.h>
#include <dlib/svm_threaded.h>
#include <dlib/string.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_processing.h>
#include <dlib/data_io.h>
#include <dlib/cmd_line_parser.h>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>
#include <dlib/opencv/cv_image.h>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;
using namespace dlib;


typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type;

class Sign_Detector{

private:

    ifstream fin;
    object_detector<image_scanner_type> detector;
    cv::Rect DlibRectangleToOpenCV(dlib::rectangle r);

public:
    Sign_Detector(string path);    
    void detect_crossing_sub(string image_name);
};

