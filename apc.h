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

int len(Dlist*head,Dlist*head2);//find which is big , if 1 L1big , 2 L2big, 3 l1=l2 
int Who_big(Dlist *head1, Dlist*head2); //tells which is bigger return 1 for L1 , L2->2 , if L1 = l2 return 3
int opType(char*argv);// find out which operation to perform
int finalSign(int big, int res,int firstSign,int secondSign,int *fsign); //findout the final sign and operation for answer
int validate(int argc,char *argv[],int*firstSign,int*secondSign);
int stol(Dlist **head, Dlist **tail, char arr[]); //convert string to list
void dl_insert_last(Dlist **head, Dlist **tail, int data);
void insert_first(Dlist **head,Dlist**tail, int data);
void add(Dlist*head1, Dlist*head2,Dlist*tail1,Dlist*tail2, Dlist**head,Dlist**tail);
void sub(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2, Dlist **head, Dlist **tail);
void multiply(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2,  Dlist **head, Dlist **tail);
void divide(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2,  Dlist **head, Dlist **tail);
void printer(Dlist *head);
int dl_delete_list(Dlist **head, Dlist **tail); 
void digitxList(Dlist *tail1, int data, Dlist **head, Dlist **tail); // calculate multiplucation of list with single digit
void putZeros(Dlist **head, Dlist **tail, Dlist *zero); // append zeros in list
void copyList(Dlist *h1, Dlist **h2, Dlist **t2);  // copy one list1 in  list2
int Cmp(Dlist *head1, Dlist *head2);   //tell which list is bigger if l1 then return 1 else 0
void filterAns(Dlist **head,Dlist**tail);  //for removing trailing zeros