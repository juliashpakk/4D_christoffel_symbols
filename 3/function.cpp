#include <iostream>
#include <windows.h>
#include <math.h>
#include "Header.h"

using namespace std;


double matrix:: get_A(int i, int j) {
	return A[i][j];
}

void matrix:: set_A(double R, int i, int j) {
	A[i][j] = R;
}

matrix multipl(matrix a, matrix b) {
	matrix S;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			double SS = 0;
			for (int p = 0; p < 4; p++) {
				SS += a.get_A(i,p) * b.get_A(p, j);
			}
			S.set_A(SS, i, j);
		}
	}
	return S;
}

void input1(matrix A) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << A.get_A(i, j)<<" ";
		}
		cout << endl;
	}
}

matrix triangle(matrix b[4], int k) {
	matrix R;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			double RR = 0.5 * (b[k].get_A(i, j) - b[i].get_A(j, k) + b[j].get_A(k, i));
			R.set_A(RR, i, j);
		}
	}
	return R;
}

matrix inverse(matrix A) {
	matrix R, E;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				E.set_A(1, i, j);
			else
				E.set_A(0, i, j);
		}
	}
	double arr[4][8];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = A.get_A(i, j);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 4; j < 8; j++) {
			arr[i][j] = E.get_A(i, j-4);
		}
	}
	
	for (int i = 0; i < 4; i++) {
		double buf = arr[i][i];
		for (int j = 0; j < 8; j++)
			arr[i][j] /= buf;
		for (int k = 0; k < 4; k++) {
			if (k != i) {
				buf = arr[k][i];
				for (int d = 0; d < 8; d++)
					arr[k][d] -= arr[i][d] * buf;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		for (int j = 4; j < 8; j++)
			R.set_A(arr[i][j], i, j - 4);
	return R;
}