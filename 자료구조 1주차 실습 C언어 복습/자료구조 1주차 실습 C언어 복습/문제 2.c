//#pragma warning(disable:4996)
//#include <stdio.h>
//
//void ABC(int arr[], int k);
//
//int main() {
//	int arr[10], k=0;
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &arr[i]);
//	}
//
//	for (int k = 0; k < 9; k++)
//		ABC(arr, k);
//
//	for (int i = 0; i < 10; i++)
//		printf(" %d", arr[i]);
//
//	return 0;
//}
//
//void ABC(int arr[], int k) {
//	int max = arr[k], idx=k;
//	for (int i = k+1; i <= 9; i++) {
//		if (arr[i] > max) {
//			max = arr[i];
//			idx = i;
//		}
//	}
//	int tmp = arr[k];
//	arr[k] = arr[idx];
//	arr[idx] = tmp;
//}