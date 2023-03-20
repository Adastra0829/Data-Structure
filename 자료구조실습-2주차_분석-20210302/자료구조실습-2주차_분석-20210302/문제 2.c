//#pragma warning(disable:4996)
//#include <stdio.h>
//
//int mostOnes(int A[][100], int n);
//
//int main() {
//	int n, arr[100][100];
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	printf("%d", mostOnes(arr, n));
//
//	return 0;
//}
//
//int mostOnes(int A[][100], int n) {//Áß¿ä
//	int row = 0, i=0,j=0;
//	while ((i < n) && (j < n)) {
//		if (A[i][j] == 0)
//			i++;
//		else {
//			row = i;
//			j++;
//		}
//	}
//
//	return row;
//}