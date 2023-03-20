//#pragma warning(disable:4996)
//#include <stdio.h>
//
//void hanoigame(int n, char from, char to, char via);
//
//int main() {
//	int N;
//	scanf("%d", &N);
//	hanoigame(N, 'A', 'C', 'B');
//	return 0;
//}
//
//void hanoigame(int n, char from, char to, char via) {
//	if (n == 1) {
//		printf("%c %c\n", from, to);
//	}
//	else {
//		hanoigame(n - 1, from, via, to);
//		printf("%c %c\n", from, to);
//		hanoigame(n - 1, via, to, from);
//	}
//}