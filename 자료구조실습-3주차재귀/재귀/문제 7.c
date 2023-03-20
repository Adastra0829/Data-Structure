#pragma warning(disable:4996)
#include <stdio.h>

void count(int i, char s[100], int cnt, int c, char x);

int main() {
	char s[101], x;
	int cnt=0, i=0, c=0;
	scanf(" %s", s);       //gets
	getchar();
	scanf("%c", &x);

	while (s[cnt] != '\0') {
		s[cnt++];
	}
	count(i, s, cnt, c, x);
	return 0;
}

void count(int i, char s[100], int cnt, int c, char x) {
	if (i == cnt) {//
		printf("%d", c);
	}
	else {
		if (s[i++] == x) c++;
		count(i, s, cnt, c, x);
	}
}//포인터 쓰면 좀 간단하고, !*s