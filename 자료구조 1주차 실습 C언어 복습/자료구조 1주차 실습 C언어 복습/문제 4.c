//#pragma warning(disable:4996)
//#include <stdio.h>
//
//int main() {
//	char str[100];
//
//	scanf("%s", str);
//
//	//printf("%d\n", strlen(str));//
//	//printf("%c\n", str[4]);
//
//	for (int i = 0; i < strlen(str); i++) {
//		printf("%s\n", str);
//		int tmp = str[0];
//		for (int j = 0; j < strlen(str); j++) { //strlen(str)값이 변하는 이유.../0문자까지 끌어들였기 때문
//			str[j] = str[j + 1];
//		}
//		//printf("%d\n", strlen(str));//
//		str[strlen(str)] = tmp;
//	}
//
//
//	return 0;
//}