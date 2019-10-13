#include <arrow_detector.h>

int main(int argc, char** argv) {

    string file_name = argv[1];
    string image_name = argv[2];
    // argv[1] -- svm trained model file path
    // argv[2] -- image file path

    auto detect = make_shared<Sign_Detector>(file_name);
    detect->detect_crossing_sub(image_name);

    return 0;
}

