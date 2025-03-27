//
// Created by wjr on 25-3-15.
//
#include <iostream>
#include "opencv2/opencv.hpp"
int main() {
    std::cout<<"cvRound(2.4)"<<cvRound(2.4)<<std::endl;
    std::cout<<"cvRound(2.6)"<<cvRound(2.6)<<std::endl;//四舍五入
    std::cout<<"cvFloor(3.2)"<<cvFloor(3.2)<<std::endl;//向下取整
    std::cout<<"cvCeil(3.2)"<<cvCeil(3.2)<<std::endl;//向上取整
    std::cout<<"cvIsNaN(4.3)"<<cvIsNaN(4.3)<<std::endl;//判断是否是一个数
    std::cout<<"cvIsInf(5.6)"<<cvIsInf(5.6)<<std::endl;//判断是否无穷大
}