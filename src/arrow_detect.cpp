#include<arrow_detector.h>

cv::Rect Sign_Detector::DlibRectangleToOpenCV(dlib::rectangle r)
{
    return cv::Rect(cv::Point2i(r.left(), r.top() ), cv::Point2i(r.right() + 1, r.bottom() + 1) );

}

Sign_Detector::Sign_Detector(string path)
{
    fin.open(path, ios::binary);
    if (!fin)
    {
        cout << "Can't find a trained object detector file object_detector.svm. " << endl;
        exit(0);
    }

    deserialize(detector, fin);
}

void Sign_Detector::detect_crossing_sub(string image_name)
{

    Mat image = imread(image_name);
    dlib::cv_image<dlib::bgr_pixel> cimg(image);
    std::vector<dlib::rectangle> dets = detector(cimg);
    cout << "Number of detections: "<< dets.size() << endl;

    Rect crossing_rect_;

    if(dets.size() > 0){
        crossing_rect_ = DlibRectangleToOpenCV(dets[0]);
        int mid_pt_x  = (dets[0].left() + dets[0].right())/2;
        int mid_pt_y = (dets[0].top()+dets[0].bottom())/2;

        cv::rectangle(image, crossing_rect_, Scalar(255, 0, 0), 2);
        cv::circle(image, cv::Point2i(mid_pt_x, mid_pt_y), 1, Scalar(0,255,0), 3);
    }
    else
        cout<<"no detections made"<<endl;

    cv::namedWindow("abc", cv::WINDOW_AUTOSIZE);

    cv::imshow("abc",image);
    cv::waitKey(0);

}
