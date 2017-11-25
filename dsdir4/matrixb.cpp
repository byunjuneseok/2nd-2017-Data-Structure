#include "matrixb.h"
Matrix::Matrix(int a, int b, int c, int d, int e, int f, int g, int h, int ii)  
{
	m[0][0] = a;
	m[0][1] = b;
	m[0][2] = c;
	m[1][0] = d;
	m[1][1] = e;
	m[1][2] = f;
	m[2][0] = g;
	m[2][1] = h;
	m[2][2] = ii;
}
Matrix Matrix::Transpose()
{	
	Matrix c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c.m[j][i] = m[i][j];
			}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = c.m[i][j];
		}
	}
}
Matrix Matrix::operator+(const Matrix &a) {
	Matrix c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c.m[i][j] = m[i][j] + a.m[i][j];
		}
	}
	return c;
}
Matrix Matrix::operator-(const Matrix &a) {
	Matrix c;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				c.m[i][j] = m[i][j] - a.m[i][j];
			}
		}
		return c;
	}
Matrix Matrix::operator*(const Matrix &a) {
	Matrix c;
	

	for(int i = 0; i< 3 ; i++){
		for (int j = 0 ; j<3;j++){
			for (int x = 0; x < 3; x++) {
				c.m[i][j] += (m[i][x] * a.m[x][j]);
			}
		}
	}
	return c;
	}

void Matrix::operator=(const Matrix &a) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
			m[i][j] = a.m[i][j];
			}
		}
	}
void Matrix::ShowMatrix(){
	for (int i = 0; i < 3; i++) {
		std::cout << m[i][0] << " " << m[i][1] << " " << m[i][2] << std::endl;
		}
}