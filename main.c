#include <string.h>
#include <stdlib.h>
#include "sorted-list.c"


int compareInt(void *x, void*y){
	
	
	int i = *(int*)x;
	int p = *(int*)y;

	
	return i-p;
	}

int compareChar(void *x, void*y){
	
	
	char i = *(char*)x;
	char p = *(char*)y;

	
	return i-p;
	}

int compareString(void *x, void*y){
	
	
	char *i = x;
	char *p = y;

	
	return strcmp(i,p);
	}

int compareFloat(void *x, void*y){
	
	
	float i = *(float*)x;
	float p = *(float*)y;

	
	return i-p;
	}

void Destroy(void *p){
	return;
	}


	
int main(int argc, char *argv[]){
	int z = argc;
	if(z==1 || z==0 || z>2){
		printf("too few or many args");
			}
	char *qw = argv[1];					/*argv will pick the option*/
	
	if(strcmp(qw,"1")==0){						/*option 1 is int test*/
	int a = 5;
	int b = 10;
	int c = 7;
	int d = 12;
	int e = 2;
	int f = 9;
	int g = 9;
	int h = 23;
	int i = 50;
	CompareFuncT com = &compareInt;
	DestructFuncT des = &Destroy;
	SortedListPtr s1 = SLCreate(com,des);
	SLInsert(s1,(void*)&a);
	SLInsert(s1,(void*)&b);
	SLInsert(s1,(void*)&c);
	SLInsert(s1,(void*)&d);
	SLInsert(s1,(void*)&e);
	SLInsert(s1,(void*)&f);
	SLInsert(s1,(void*)&g);
	SLInsert(s1,(void*)&h);
	SLInsert(s1,(void*)&i);
	SLRemove(s1,(void*)&e);
	SLRemove(s1,(void*)&d);
	SLRemove(s1,(void*)&h);
	
	while(s1->head!=NULL){
		printf("%d\n",*(int*)s1->head->data);
		s1->head=s1->head->next;
			}
		}

	if(strcmp(qw,"2")==0){						/*option 2 is float test*/
		float ab = 5.21;
		float bc = 10.4;
		float cd = 7.2;
		float de = 12.6;
		float ef = 2.8;
	
	CompareFuncT com = &compareFloat;
	DestructFuncT des = &Destroy;
	SortedListPtr s2 = SLCreate(com,des);
	SLInsert(s2,(void*)&ab);
	SLInsert(s2,(void*)&bc);
	SLInsert(s2,(void*)&cd);
	SLInsert(s2,(void*)&de);
	SLInsert(s2,(void*)&ef);
	SLRemove(s2,(void*)&de);
	SLRemove(s2,(void*)&bc);
	
	while(s2->head!=NULL){
		printf("%.4f\n",*(float*)s2->head->data);
		s2->head=s2->head->next;
			}
		}
	
	

	if(strcmp(qw,"3")==0){						/*option 2 is float test*/
	char *ab = "hello";
	char *bc = "good";
	char *cd = "car";
	char *de = "bus";
	char *ef = "ocean";
	
	CompareFuncT com = &compareString;
	DestructFuncT des = &Destroy;
	SortedListPtr s1 = SLCreate(com,des);
	SLInsert(s1,(void*)ab);
	SLInsert(s1,(void*)bc);
	SLInsert(s1,(void*)cd);
	SLInsert(s1,(void*)de);
	SLInsert(s1,(void*)ef);
	SLRemove(s1,(void*)de);
	SLRemove(s1,(void*)bc);
	
	while(s1->head!=NULL){
		printf("%s\n",(char*)s1->head->data);
		s1->head=s1->head->next;
			}
		}


	if(strcmp(qw,"4")==0){						/*option 2 is float test*/
	char a = 'a';
	char b = 'b';
	char c = 'i';
	char d = 'h';
	char e = 'e';
	
	CompareFuncT com = &compareString;
	DestructFuncT des = &Destroy;
	SortedListPtr s1 = SLCreate(com,des);
	SLInsert(s1,(void*)&a);
	SLInsert(s1,(void*)&b);
	SLInsert(s1,(void*)&c);
	SLInsert(s1,(void*)&d);
	SLInsert(s1,(void*)&e);
	SLRemove(s1,(void*)&d);
	SLRemove(s1,(void*)&b);
	
	while(s1->head!=NULL){
		printf("%c\n",*(char*)s1->head->data);
		s1->head=s1->head->next;
			}
		}
	
	return 0;
		}
		
		 
