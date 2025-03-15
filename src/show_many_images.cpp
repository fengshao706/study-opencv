//
// Created by wjr on 25-3-15.
//
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui_c.h"
void showManyImages(const std::vector<cv::Mat>&images) {
    int theNumberOfImages=images.size();
    cv::Size theNumberOfWindows;
    if (theNumberOfImages>9) {
        std::cout<<"You can't input more than 9 images"<<std::endl;
        return;
    }
    switch (theNumberOfImages) {//确定窗口的横排和竖排的数量
        case 1:theNumberOfWindows=cv::Size(1,1);break;
        case 2:theNumberOfWindows=cv::Size(2,1);break;
        case 3:
        case 4:theNumberOfWindows=cv::Size(2,2);break;
        case 5:
        case 6:theNumberOfWindows=cv::Size(3,2);break;
        default:theNumberOfWindows=cv::Size(3,3);
    }
    int showImageSize=400;//设定单张图像的大小
    int splitLineSize=30;//设定图像之间的分割线的大小
    int aroundLineSize=10;//设定环绕图像的线的大小
    const int imageHeightSize=showImageSize * theNumberOfWindows.height+(theNumberOfWindows.height-1) * splitLineSize + aroundLineSize*2;//计算输出图像的高度
    const int imageWidthSize=showImageSize * theNumberOfWindows.width+(theNumberOfWindows.width-1) * splitLineSize + aroundLineSize*2;
    std::cout<<imageWidthSize<<"  "<<imageHeightSize<<std::endl;
    cv::Mat showManyImages(imageHeightSize,imageWidthSize,CV_8UC3,cv::Scalar(0,0,0));
    int posX=aroundLineSize;
    int posY=aroundLineSize;
    int tempPosX=posX;
    int tempPosY=posY;
    for (int i=0;i<theNumberOfImages;i++) {//当一行处理完后将坐标移到下一行的开始以便于处理下一行
        if ((i%theNumberOfWindows.width==0)&&tempPosX!=posX) {
            tempPosX=posX;
            tempPosY+=(showImageSize + splitLineSize);
        }
        cv::Mat tempImage=showManyImages(cv::Rect(tempPosX,tempPosY,showImageSize,showImageSize));
        cv::resize(images[i],tempImage,cv::Size(showImageSize,showImageSize));
        tempImage.copyTo(showManyImages(cv::Rect(tempPosX,  tempPosY, showImageSize, showImageSize)));
        tempPosX+=showImageSize+splitLineSize;
    }
    cv::imshow("showManyImages",showManyImages);
}

int main() {
    std::vector<cv::Mat>images;
    images.push_back(cv::imread("../images/read/brother.jpg"));
    images.push_back(cv::imread("../images/read/fish.jpg"));
    showManyImages(images);
    cv::waitKey(0);
}

