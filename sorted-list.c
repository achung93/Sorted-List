#include <stdio.h>
#include "sorted-list.h"

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
	SortedListPtr list = malloc(sizeof(struct SortedList));
	list->head = NULL;
	list->cmp = cf;
	list->des = df;
	return list;
	}

	
int SLInsert(SortedListPtr list, void *newObj){
	struct Node *temp;
	struct Node *curr;
	struct Node *prev;
	void *tempr;
	int w;
	
	if(list==NULL){
		printf("list is null\n");
		return 0;
		}
	else if(list->head==NULL){
		
		list->head = malloc(sizeof(struct Node));
		list->head->data = newObj;
		list->head->next = NULL;
		}

	else if(list->head!=NULL && list->head->next==NULL){
		
		list->head->next = malloc(sizeof(struct Node));
		int q = list->cmp(newObj,list->head->data);
		
		
		if(q>0){
			tempr = list->head->data;
							/*create temp*/
			list->head->data = newObj;
							/*make new obj head of list*/
			(list->head->next)->data = tempr;	/*head is now next*/
			}
		else if(q<0){
			(list->head->next)->data = newObj;					/*newobj is less than curr obj*/
			
			}
		else{
			(list->head->next)->data = newObj;		/*duplicates*/
				}
			}
			
	else{
		
		prev = list->head;
		curr = list->head->next;
		
		while(prev!=NULL){
			
			
			w = list->cmp(newObj,prev->data);
			
			
			
			if(w>0){
				
				if(curr==NULL){	
					
					tempr = prev->data;
					
					curr = malloc(sizeof(struct Node));
					
					prev->data = newObj;
					curr->data = tempr;
					prev->next = curr;
					curr->next= NULL;
					
					break;
										/*newObj is greater than curr obj move forward*/
					
						}
					else{
						struct Node *x = malloc(sizeof(struct Node)); /*create new node*/
						temp = prev->next;
						x->data = prev->data;		/*put curr data into new node*/
						prev->data = newObj;		/*swap curr dataa with new data*/
						prev->next = x;			/*curr next is now the old curr*/
						x->next = temp;		
						break;
							}     /*newObj is greater than curr obj move forward*/
					}

			else if(w<0){
				
				if(curr==NULL){
					curr = malloc(sizeof(struct Node));	/*reached end of the list*/
					curr->data = newObj;
					prev->next = curr;
					curr->next = NULL;
					break;
						}
					else{
						prev = curr;
						curr = curr->next;
						}
					
						
					}
				else{
					return 0;
					}
	
					
				}
			}
			
			return 1;
		}

	int SLRemove(SortedListPtr list, void *newObj){
		
		struct Node *temp2 = list->head;
		struct Node *t3;
		if(list==NULL){
			return 0;
			}
		else{
			if(list->cmp(list->head->data,newObj)==0){
				t3 = list->head;			/*remove head of list*/
				list->head = list->head->next;		/*make heads next the head*/
				free(t3);
				}
			else{
				while(temp2->next!=NULL){
					if(list->cmp(temp2->next->data,newObj)==0){
						

						if(temp2->next->next==NULL){
							temp2->next = NULL;
							}
						else{
							temp2->next = temp2->next->next;
						}
						
						break;
							}
							temp2 = temp2->next;
						}
					}
				}
				return 1;
			}

	void SLDestroy(SortedListPtr list){
		struct Node *t4 = list->head;
		struct Node *t5;
			while(t4!=NULL){
				t5 = t4->next;
				list->des(t4);
				free(t4);
				t4 = t5;
				}

			list->head = NULL;
			free(list);
		}

	SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
			if(list==NULL){
				return NULL;
				}

			SortedListIteratorPtr p1 = malloc(sizeof(SortedListIteratorPtr));

			p1->head = list->head;
			return p1;
			}

	void * SLNextItem(SortedListIteratorPtr iter){
		void *t5;
		t5 = iter->head->data;
		iter->head = iter->head->next;
		return t5;
		}
			
		

			
