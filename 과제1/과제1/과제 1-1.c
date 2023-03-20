//#pragma warning(disable:4996)
//#include <stdio.h>
//
//int countOnesButSlow(int A[][100], int n );
//int countOnes(int A[][100], int n);
//
//int main() {
//	int n, A[100][100];
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++) 
//		for (int j = 0; j < n; j++) 
//			scanf("%d", &A[i][j]);
//	
//	printf("%d\n", countOnesButSlow(A, n));
//	printf("%d", countOnes(A, n));
//
//	return 0;
//}
//
//int countOnesButSlow(int A[][100], int n) {
//	int c = 0;
//	for (int i = 0; i < n; i++) {
//		int j = 0;
//		while ((j < n) && (A[i][j] == 1)) {
//			c++;
//			j++;
//		}
//	}
//	return c;
//}
//
//int countOnes(int A[][100], int n) {
//	int c = 0, i = 0, j = n-1;
//	while (i < n && j > -1) {
//		if (A[i][j] == 0) {
//			j--;
//		}
//		else {
//			c += (j + 1);
//			i++;
//		}
//	}
//	return c;
//}
//
///*
//
//8
//1 1 1 1 1 1 1 1
//1 1 1 1 1 1 0 0
//1 1 1 1 1 1 0 0
//1 1 1 1 1 0 0 0
//1 1 1 1 1 0 0 0
//1 1 1 1 1 0 0 0
//1 1 0 0 0 0 0 0
//0 0 0 0 0 0 0 0
//
//*/