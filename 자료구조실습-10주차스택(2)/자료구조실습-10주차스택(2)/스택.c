//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct stack {
//    int top;
//    int* stack;
//    int size;
//} S;
//void fullStackException();
//void emptyStackException();
//int isEmpty(S* arr);
//void pop(S* arr);
//void push(S* arr, int tmp);
//void cal(S* arr, int tmp);
//S* initstack(int n);
//void clearstack(S* arr);
//int main() {
//
//    int n, plag = 0;
//    scanf("%d", &n);
//    char tmp[101];
//    char p[128] = { 0,1,2,3,3,4,4,5,5,6,6,6 };
//    //(,||,&&,<,>,-,+,/,*,[!,+,-] 단항연산자
//    // -A++B -> A-B++
//    p['('] = 0;
//    p['|'] = 1;
//    p['&'] = 2;
//    p['<'] = 3;
//    p['>'] = 3;
//    p['-'] = 4;
//    p['+'] = 4;
//    p['/'] = 5;
//    p['*'] = 5;
//    p['!'] = 6;
//    p['@'] = 6;//+
//    p['#'] = 6;//-
//    S* stack;
//    for (int i = 0; i < n; i++)
//    {
//        stack = initstack(101);
//        scanf("%s", tmp);
//        for (int j = 0; j < strlen(tmp); j++)// while(!endOfFile())
//        {
//            if (tmp[j] == '(')// (일때
//            {
//                push(stack, '(');
//            }
//            else if (tmp[j] == ')')// )일때
//            {
//                while (stack->stack[stack->top] != '(')
//                {
//                    switch (stack->stack[stack->top]) {//write
//                    case '&': {
//                        printf("&&");
//                        break;
//                    }
//                    case '|': {
//                        printf("||");
//                        break;
//                    }
//                    case '@': {
//                        printf("+");
//                        break;
//                    }
//                    case '#': {
//                        printf("-");
//                        break;
//                    }
//                    default: {
//                        printf("%c", stack->stack[stack->top]);
//                    }
//                    }
//                    pop(stack);
//                }
//                pop(stack);//(팝
//                if (stack->stack[stack->top] == '@')
//                {
//                    printf("+");
//                    pop(stack);
//                }
//                else if (stack->stack[stack->top] == '#')
//                {
//                    printf("-");
//                    pop(stack);
//                }
//            }
//            else if (tmp[j] >= 'A' && tmp[j] <= 'Z')//operand
//            {
//                printf("%c", tmp[j]);
//            }
//            else//operator
//            {
//                if (tmp[j] == '&')
//                    j++;
//                if (tmp[j] == '|')
//                    j++;
//                if (tmp[j] == '+' &&
//                    (j == 0 || ((tmp[j - 1] < 'A' || tmp[j - 1]>'Z') && tmp[j - 1] != ')' && (tmp[j + 1] >= 'A' && tmp[j + 1] <= 'Z'))))
//                    // 맨앞자리 거나 앞의 원소가 operator이고 앞의 operator가 )가 아니고 다음이 operand일때
//                {
//                    push(stack, '@');
//                    plag = 1;
//                    continue;
//                }
//                else if (tmp[j] == '-' &&
//                    (j == 0 || ((tmp[j - 1] < 'A' || tmp[j - 1]>'Z') && tmp[j - 1] != ')' && (tmp[j + 1] >= 'A' && tmp[j + 1] <= 'Z'))))
//                {
//                    push(stack, '#');
//                    plag = 1;
//                    continue;
//                }
//                while (!isEmpty(stack) && p[tmp[j]] <= p[stack->stack[stack->top]])
//                {
//                    switch (stack->stack[stack->top]) {
//                    case '&': {
//                        printf("&&");
//                        break;
//                    }
//                    case '|': {
//                        printf("||");
//                        break;
//                    }
//                    case '@': {
//                        printf("+");
//                        break;
//                    }
//                    case '#': {
//                        printf("-");
//                        break;
//                    }
//                    default: {
//                        printf("%c", stack->stack[stack->top]);
//                    }
//                    }
//                    pop(stack);
//                }
//                push(stack, tmp[j]);
//            }
//        }
//        while (!isEmpty(stack))
//        {
//            switch (stack->stack[stack->top]) {
//            case '&': {
//                printf("&&");
//                break;
//            }
//            case '|': {
//                printf("||");
//                break;
//            }
//            case '@': {
//                printf("+");
//                break;
//            }
//            case '#': {
//                printf("-");
//                break;
//            }
//            default: {
//                printf("%c", stack->stack[stack->top]);
//            }
//            }
//            pop(stack);
//        }
//        clearstack(stack);
//        printf("\n");
//    }
//
//    return 0;
//}
//S* initstack(int n)
//{
//    S* stack = (S*)malloc(sizeof(S));
//    stack->size = n;
//    stack->top = -1;
//    stack->stack = (int*)malloc(n * sizeof(int));
//
//    return stack;
//}
//void clearstack(S* arr)
//{
//    free(arr->stack);
//    free(arr);
//}
//int isEmpty(S* arr)
//{
//    return arr->top == -1;
//}
//void fullStackException()
//{
//    printf("Stack FULL\n");
//}
//void emptyStackException()
//{
//    printf("Stack Empty\n");
//}
//
//void pop(S* arr) {
//    if (isEmpty(arr))
//        emptyStackException();
//    else
//    {
//        arr->top -= 1;
//         *(arr->stack + (arr->top + 1));
//    }
//}
//void push(S* arr, int tmp) {
//    if (arr->top == arr->size - 1)
//        fullStackException();
//    else
//    {
//        arr->top += 1;
//        arr->stack[arr->top] = tmp;
//    }
//}