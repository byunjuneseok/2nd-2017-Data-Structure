#include "matrixa.h"
Matrix::Matrix(int a, int b, int c, int d)  
{
	m[0][0] = a;
	m[0][1] = b;
	m[1][0] = c;
	m[1][1] = d;
}
Matrix Matrix::Transpose()
{	
	Matrix c;
	Matrix result;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c.m[j][i] = m[i][j];
			}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m[i][j] = c.m[i][j];
		}
	}
	return (*this);
}
Matrix Matrix::operator+(const Matrix &a) {
	Matrix c;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c.m[i][j] = m[i][j] + a.m[i][j];
		}
	}
	return c;
}
Matrix Matrix::operator-(const Matrix &a) {
	Matrix c;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c.m[i][j] = m[i][j] - a.m[i][j];
			}
		}
		return c;
	}
Matrix Matrix::operator*(const Matrix &a) {
	Matrix c;
	

	for(int i = 0; i< 2 ; i++){
		for (int j = 0 ; j<2;j++){
			for (int x = 0; x < 2; x++) {
				c.m[i][j] += (m[i][x] * a.m[x][j]);
			}
		}
	}
	return c;
	}

void Matrix::operator=(const Matrix &a) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
			m[i][j] = a.m[i][j];
			}
		}
	}
void Matrix::ShowMatrix(){
	for (int i = 0; i < 2; i++) {
		std::cout << m[i][0] << " " << m[i][1] << std::endl;
		}
}