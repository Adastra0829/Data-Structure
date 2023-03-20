//#pragma warning(disable:4996)
//#include <stdio.h>
//
//typedef struct info {
//	char name[10];
//	int score;
//}info;
//
//int main() {
//	info inf[5];
//	double avg=0;
//
//	for (int i = 0; i < 5; i++) {
//		scanf(" %s %d", &inf[i].name, &inf[i].score);
//	}
//
//	for (int i = 0; i < 5; i++) {
//		avg += (double)inf[i].score;
//	}
//	avg /= 5;
//
//	for (int i = 0; i < 5; i++) {
//		if ((double)inf[i].score <= avg)
//			printf("%s\n", inf[i].name);
//	}
//
//
//
//	return 0;
//}