#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc ,char **argv) {
    cv::Mat img = cv::imread("../images/read/test.jpg");//将其转换为灰度图像去读取
    if (img.empty()) {
        printf("can not read this image\n");
        return -1;
    }
    cv::Mat gray , hsv;
    namedWindow("input windows",cv::WINDOW_NORMAL);
    namedWindow("gray",cv::WINDOW_NORMAL);
    namedWindow("hsv",cv::WINDOW_NORMAL);//创建3个显示窗口
    cvtColor(img,gray,cv::COLOR_BGR2GRAY);
    cvtColor(img,hsv,cv::COLOR_BGR2HSV);//将原显示窗口进行显示模式的变换
    imshow("input windows", img);
    imshow("gray",gray);
    imshow("hsv",hsv);//显示变换后的窗口以及原窗口

    cv::waitKey(2000);//图片在屏幕上所停留的时间
    cv::Mat mat(1920,1080,CV_8UC3);
    mat=img;
    bool result=0;
    try {
        result = cv::imwrite("../images/write/learn_drive_car.png",mat);
    }catch (const cv::Exception &cv_exception) {
        std::cout<<"Exception occur"<<std::endl;
    }
    if (result == 1) {
        std::cout<<"Successfully save images"<<std::endl;
    }else {
        std::cout<<"Can't save images"<<std::endl;//判断是否保存成功
    }
    return 0;
}