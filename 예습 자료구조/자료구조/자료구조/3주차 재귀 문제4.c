//#pragma warning(disable:4996)
//#include <stdio.h>
//void max( int n[], int mx, int i, int N);
//int main() {
//	int N, n[20]={0}, i, mx;
//
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		scanf("%d", &n[i]);
//	}
//	mx = n[0];
//	i = 0;
//	
//	max( n, mx, i, N); //배열이름만!
//	return 0;
//}
//void max(int n[], int mx, int i, int N) {
//	if (i == N-1) {
//		if (n[i] > mx) 
//			mx = n[i];
//		printf("%d", mx);
//	}
//	else {
//		i += 1;
//		if (n[i] > mx)
//			mx = n[i];
//		max(n, mx, i, N);
//	}
//}
//
///*
//
//
//5
//4 1 8 3 7
//
//
//*/