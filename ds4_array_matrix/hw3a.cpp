#include "matrixa.h"
#include <iostream>
int main()
{
    Matrix matrix1(1,2,3,4);
    Matrix matrix2(1,1,1,1);
    Matrix matrix3;
    std::cout<<"----------------"<<std::endl;
    std::cout<<"Matrix Traspose"<<std::endl;
    std::cout<<"----------------"<<std::endl;
    matrix1.Transpose();
    matrix1.ShowMatrix();
    matrix1.Transpose();
	std::cout << "----------------" << std::endl;
    std::cout<<"Matrix Add"<<std::endl;
    std::cout<<"----------------"<<std::endl;
    matrix3=matrix1+matrix2;
    matrix3.ShowMatrix();
    std::cout<<"----------------"<<std::endl;
    std::cout<<"Matrix Sub"<<std::endl;
    std::cout<<"----------------"<<std::endl;
    matrix3=matrix1-matrix2;
    matrix3.ShowMatrix();
    std::cout<<"----------------"<<std::endl;
    std::cout<<"Matrix Multi"<<std::endl;
    std::cout<<"----------------"<<std::endl;
    matrix3=matrix1*matrix2;
    matrix3.ShowMatrix();
    std::cout<<"----------------"<<std::endl;
    return 0;
}