#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int countOnesButSlow(int A[][3000], int n);
int countOnes(int A[][3000], int n);
int A[3000][3000];

int main() {
	srand(time(NULL));
	int n=0, i = 0, j = 0, c=0, ktotal=0, ones;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	//n=3000 빠른버전
	n = 3000, i = 0, j = 0, c = n, ktotal=0;
	for (i = 0; i < n; i++) {
		j = 0;   
		while (j < c * 9/10) {
			A[i][j++] = 1;
		}
		int k = 0;
		while (j < c) {
			A[i][j] = rand() % 2;
			if (A[i][j] == 0) {
				while (j < n)
					A[i][j++] == 0;
			}
			else k++, j++;
		}
		if (j!=n && A[i][j-1] == 1) {
			while (j < n)
				A[i][j++] == 0;
		}
		c = c * 9 / 10 + k;
		ktotal += c;
	}

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnes(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12f \n\n",ktotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	
	///////초기화
	for (i = 0; i < 3000; i++) {
		for (j = 0; j < 3000; j++) {
			A[i][j] = 0;
		}
	}

			
    //n=1000 빠른버전
	n = 1000, i = 0, j = 0, c = n, ktotal = 0;
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < c * 9 / 10) {
			A[i][j++] = 1;
		}
		int k = 0;
		while (j < c) {
			A[i][j] = rand() % 2;
			if (A[i][j] == 0) {
				while (j < n)
					A[i][j++] == 0;
			}
			else k++, j++;
		}
		if (j != n && A[i][j - 1] == 1) {
			while (j < n)
				A[i][j++] == 0;
		}
		c = c * 9 / 10 + k;
		ktotal += c;
	}
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnes(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12f \n\n", ktotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	///////초기화
	for (i = 0; i < 3000; i++) {
		for (j = 0; j < 3000; j++) {
			A[i][j] = 0;
		}
	}
	
	//n=2000 빠른버전
	n = 2000, i = 0, j = 0, c = n, ktotal = 0;
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < c * 9 / 10) {
			A[i][j++] = 1;
		}
		int k = 0;
		while (j < c) {
			A[i][j] = rand() % 2;
			if (A[i][j] == 0) {
				while (j < n)
					A[i][j++] == 0;
			}
			else k++, j++;
		}
		if (j != n && A[i][j - 1] == 1) {
			while (j < n)
				A[i][j++] == 0;
		}
		c = c * 9 / 10 + k;
		ktotal += c;
	}
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnes(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12f \n\n", ktotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	///////초기화
	for (i = 0; i < 3000; i++) {
		for (j = 0; j < 3000; j++) {
			A[i][j] = 0;
		}
	}

	//n=3000 느린버전
	n = 3000, i = 0, j = 0, c = n, ktotal = 0;
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < c * 9 / 10) {
			A[i][j++] = 1;
		}
		int k = 0;
		while (j < c) {
			A[i][j] = rand() % 2;
			if (A[i][j] == 0) {
				while (j < n)
					A[i][j++] == 0;
			}
			else k++, j++;
		}
		if (j != n && A[i][j - 1] == 1) {
			while (j < n)
				A[i][j++] == 0;
		}
		c = c * 9 / 10 + k;
		ktotal += c;
	}
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12f \n\n", ktotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));


	///////초기화
	for (i = 0; i < 3000; i++) {
		for (j = 0; j < 3000; j++) {
			A[i][j] = 0;
		}
	}

	//n=1000 느린버전
	n = 1000, i = 0, j = 0, c = n, ktotal = 0;
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < c * 9 / 10) {
			A[i][j++] = 1;
		}
		int k = 0;
		while (j < c) {
			A[i][j] = rand() % 2;
			if (A[i][j] == 0) {
				while (j < n)
					A[i][j++] == 0;
			}
			else k++, j++;
		}
		if (j != n && A[i][j - 1] == 1) {
			while (j < n)
				A[i][j++] == 0;
		}
		c = c * 9 / 10 + k;
		ktotal += c;
	}
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12f \n\n", ktotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	///////초기화
	for (i = 0; i < 3000; i++) {
		for (j = 0; j < 3000; j++) {
			A[i][j] = 0;
		}
	}

	//n=2000 느린버전
	n = 2000, i = 0, j = 0, c = n, ktotal = 0;
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < c * 9 / 10) {
			A[i][j++] = 1;
		}
		int k = 0;
		while (j < c) {
			A[i][j] = rand() % 2;
			if (A[i][j] == 0) {
				while (j < n)
					A[i][j++] == 0;
			}
			else k++, j++;
		}
		if (j != n && A[i][j - 1] == 1) {
			while (j < n)
				A[i][j++] == 0;
		}
		c = c * 9 / 10 + k;
		ktotal += c;
	}
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12f \n\n", ktotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	return 0;
}

int countOnesButSlow(int A[][3000], int n) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while ((j < n) && (A[i][j] == 1)) {
			c++;
			j++;
		}
	}
	return c;
}

int countOnes(int A[][3000], int n) {
	int c = 0, i = 0, j = n - 1;
	while (i < n && j > -1) {
		if (A[i][j] == 0) {
			j--;
		}
		else {
			c += (j + 1);
			i++;
		}
	}
	return c;
}

