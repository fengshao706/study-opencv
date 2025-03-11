#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc ,char **argv) {
    cv::Mat img = cv::imread("/home/wjr/opencv_ws/images/read/test.jpg");//将其转换为灰度图像去读取
    if (img.empty()) {
        printf("can not read this image\n");
    }
    cv::Mat gray , hsv;
    namedWindow("input windows",cv::WINDOW_FREERATIO);
    namedWindow("gray",cv::WINDOW_FREERATIO);
    namedWindow("hsv",cv::WINDOW_FREERATIO);//创建3个显示窗口
    cvtColor(img,gray,cv::COLOR_BGR2GRAY);
    cvtColor(img,hsv,cv::COLOR_BGR2HSV);//将原显示窗口进行显示模式的变换
    imshow("input windows", img);
    imshow("gray",gray);
    imshow("hsv",hsv);//显示变换后的窗口以及原窗口

    cv::waitKey(0);//图片在屏幕上所停留的时间
    return 0;
}