#pragma once
#ifndef HEADER_H
#define HEADER_H
class matrix {
	double A [4][4];
public:
	double get_A(int i, int j);
	void set_A(double R, int i, int j);
};
matrix multipl(matrix a, matrix b);
void input1(matrix A);
matrix triangle(matrix b[4], int k);
matrix inverse(matrix A);
#endif