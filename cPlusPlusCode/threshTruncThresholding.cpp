#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int thresholdValue = 150;
int maxValue = 255;
Mat image, result;
Mat grayImage;

//Callback method for trackbar value change
void onTrackbarValueChange(int, void*){
    cout<<"threshold="<<thresholdValue<<endl;
    
    //apply the binary thresold
    threshold(image, result, thresholdValue, maxValue, THRESH_TRUNC);
    
    //show the result of the binary thresholding
    imshow("image", result);
}

int main(){
    //Read an image in gray scale
    image = imread("../assets/putin.jpg", IMREAD_GRAYSCALE);

    //create a window
    namedWindow("image", WINDOW_NORMAL);

    //Create track bar
    createTrackbar("Value", "image", &thresholdValue, maxValue, onTrackbarValueChange);

    //call method to initialize first time
    onTrackbarValueChange(0, 0);

    while(1){
        int k;

        //press esc button on keyboard to exit
        k=waitKey(10);
        if(k == 27){
            break;
        }
    }

    //close all the opened windows
    destroyAllWindows();

    return 0;
}