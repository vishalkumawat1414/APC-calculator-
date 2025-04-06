#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE -1

typedef struct list
{
   int data;
   struct list*prev;
   struct list*next;

}Dlist;

int len(Dlist*head);
int Who_big(Dlist *head1, Dlist*head2);
int opType(char*argv);
int finalSign(int big, int res,int firstSign,int secondSign,int *fsign);
int validate(int argc,char *argv[],int*firstSign,int*secondSign);
int stol(Dlist **head, Dlist **tail, char arr[]);
void dl_insert_last(Dlist **head, Dlist **tail, int data);
void insert_first(Dlist **head,Dlist**tail, int data);
void add(Dlist*head1, Dlist*head2,Dlist*tail1,Dlist*tail2, Dlist**head,Dlist**tail);
void sub(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2, Dlist **head, Dlist **tail);
void multiply(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2,  Dlist **head, Dlist **tail);
void divide(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2,  Dlist **head, Dlist **tail);
void printer(Dlist *head);
int dl_delete_list(Dlist **head, Dlist **tail);
void digitxList(Dlist *tail1, int data, Dlist **head, Dlist **tail);
void putZeros(Dlist **head, Dlist **tail, Dlist *zero);
void copyList(Dlist *h1, Dlist **h2, Dlist **t2);
int Cmp(Dlist *head1, Dlist *head2);
void filterAns(Dlist **head,Dlist**tail);