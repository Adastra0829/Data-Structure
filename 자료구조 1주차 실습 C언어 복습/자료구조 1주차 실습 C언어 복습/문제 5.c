//#pragma warning(disable:4996)
//#include <stdio.h>
//
//typedef struct time {
//	int hour;
//	int min;
//	int sec;
//}time;
//
//int main() {
//	time x, y, result;
//	scanf("%02d %02d %02d", &x.hour, &x.min, &x.sec);
//	scanf("%02d %02d %02d", &y.hour, &y.min, &y.sec);
//
//	if (y.sec - x.sec >= 0) result.sec = y.sec - x.sec;
//	else result.sec = 60 - x.sec + y.sec, y.min--;
//
//	if (y.min - x.min >= 0) result.min = y.min - x.min;
//	else result.min = 60 - x.min + y.min, y.hour--;
//
//	result.hour = y.hour - x.hour;
//
//	printf("%d %d %d", result.hour, result.min, result.sec);
//
//
//	return 0;
//}