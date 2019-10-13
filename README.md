# Arrow-SIgn-Detector

This is a piece of code written to detect arrow signs on an exit board. The model was trained using HOG and SVM using dlib library on 200 images.

#Usage
Go to the build folder and run the following command 
./arrow_detector  ../model/object_detector.svm ../test_images/FIRE-EXIT-ARROW-LEFT-UP-SIGN.jpg

General implementation is as follows
./arrow_detector  /path to svm model /path to image
