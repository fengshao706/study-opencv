#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc ,char **argv) {
    cv::Mat img = cv::imread("/home/wjr/opencv_ws/images/read/test.jpg",cv::ImreadModes::IMREAD_GRAYSCALE);//将其转换为灰度图像去读取
    if (img.empty()) {
        printf("can not read this image\n");
    }
    cv::namedWindow("input windows",cv::WINDOW_FREERATIO);
    cv::imshow("input windows", img);
    cv::waitKey(0);//图片在屏幕上所停留的时间
    return 0;
}