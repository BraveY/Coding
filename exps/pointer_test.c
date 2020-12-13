#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Malloc(char **p, int num) {
	*p = (char*)malloc(num * sizeof(char));
}

void MyTest() {
	char *s = NULL;
	Malloc(&s, 10);
	strcpy(s, "hello");
	printf("%s\n", s);
}

void Malloc1(char *p, int num) {
	printf("the address of p is %p\n", &p);
	printf("the value of p is %p\n", p);

	p = (char*)malloc(num * sizeof(char));// 传进来的地址值没有用到，没有使用解引用。
	printf("the value of p is %p\n", p);
}

void MyTest1() {
	char *s = NULL;
	printf("the value of s is %p\n", s);
	printf("the address of s is %p\n", &s);
	Malloc1(s, 10);
	strcpy(s, "hello");
	printf("%s\n", s);
}

void printAddr() {
	int a = 2;
	int *pa = &a;
	int **ppa = &pa;

	printf("the address of a is:%p\n", &a);
	printf("the address of a is:%p, which is also the value of pointer pa\n", pa);
	printf("the dereferenced value of pointer pa is:%d\n", *pa);

	printf("the address of pointer pa is:%p\n", &pa);
	printf("the address of pointer pa is:%p, which is also the value of pointer ppa\n", ppa);
	printf("the first dereferenced value of pointer ppa is:%p, which is also the address of a\n", *ppa);
	printf("the second dereferenced value of pointer ppa is:%d, which is also the value of a\n", **ppa);
}

int main() {
	printAddr();
	return 0;
}