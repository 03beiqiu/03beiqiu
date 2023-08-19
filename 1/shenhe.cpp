#define GLUT_DISABLE_ATEXIT_HACK
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10 
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

#include "stdio.h"
#include "malloc.h"
#include <stdlib.h>

typedef int status;
typedef char SelemType;
typedef struct {
	SelemType* base;
	SelemType* top;
	int stacksize;
}SqStack;

status InitStack(SqStack& S) {
	S.base = (SelemType*)malloc(STACK_INIT_SIZE * sizeof(SelemType));
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

status Push(SqStack& S, SelemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (SelemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SelemType));
		if (!S.base)
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

status Pop(SqStack& S, SelemType& e) {
	if (S.top == S.base)	return ERROR;
	e = *--S.top;
	return OK;
}

status StackEmpty(SqStack S) {
	if (S.top == S.base)
		return TURE;
	else
		return FALSE;
}

void conversion() {
	SqStack S;
	int N, d, ys;
	SelemType x, e;
	InitStack(S);
	while (1) {
		printf("������һ���Ǹ�ʮ��������0��������");
		scanf_s("%d", &N);
		if (N == 0)break;
		printf("������Ҫת���Ľ���:");
		scanf_s("%d", &d);
		while (N) {
			ys = N % d;
			if (ys <= 9)
				x = ys + '0';
			else
				x = ys - 10 + 'A';
			Push(S, x);
			N = N / d;
		}
		printf("ת������%d������Ϊ��", d);
		while (!StackEmpty(S)) {
			Pop(S, e);
			printf("%c", e);
		}
		printf("\n");
	}
}

void main() {
	conversion();
}




