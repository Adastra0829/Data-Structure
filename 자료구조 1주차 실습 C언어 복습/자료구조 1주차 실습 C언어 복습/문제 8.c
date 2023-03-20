//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h> //동적할당시 꼭 필요함 
//
//typedef struct student {
//	char name[8];
//	int kor;
//	int eng;
//	int math;
//	double avg;
//}student;
//
//int main() {
//	int N;
//	scanf("%d", &N);
//
//	student* p = (student*)malloc(sizeof(student) * N);
//
//	for (int i = 0; i < N; i++) {
//		scanf("%s %d %d %d", &(p + i)->name, &(p + i)->kor, &(p + i)->eng, &(p + i)->math);// &
//		(p + i)->avg = (double)((p + i)->kor + (p + i)->eng + (p + i)->math) / 3.0;
//	}
//
//	for (int i = 0; i < N; i++) {
//		printf("%s %.1lf ", (p + i)->name, (p + i)->avg);
//		if ((p + i)->kor >= 90 || (p + i)->eng >= 90 || (p + i)->math >= 90) printf("GREAT ");
//		if ((p + i)->kor <70  || (p + i)->eng < 70 || (p + i)->math < 70) printf("BAD");
//		printf("\n");
//	}
//
//
//	free(p);
//	return 0;
//}