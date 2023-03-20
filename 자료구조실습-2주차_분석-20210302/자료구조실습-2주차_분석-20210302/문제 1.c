//#pragma warning(disable:4996)
//#include <stdio.h>
////#include <Windows.h>
//
//int modulo(int a, int b);
//
//int main() {
//	int a, b;
//	//LARGE_INTEGER ticksPerSec;
//	//LARGE_INTEGER start, end, diff;
//
//	//QueryPerformanceFrequency(&ticksPerSec);
//	//QueryPerformanceCounter(&start);
//
//	scanf("%d %d", &a, &b);
//	printf("%d", modulo(a, b));
//
//	//QueryPerformanceCounter(&end);
//	//diff.QuadPart = end.QuadPart - start.QuadPart;
//	//printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
//	
//
//	return 0;
//}
//
//int modulo(int a, int b) {
//	while (a >= b) {
//		a -= b;
//	}
//	return a;
//}