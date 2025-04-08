#include <stdio.h>
#include "apc.h"

int validate(int argc,char *argv[],int*firstSign,int*secondSign)
{
     if (argc != 4) {
          printf("ERROR: Invalid Command\nPass like: ./a.out X operator Y\n");
          return FAILURE;
     }
     else {
           //check operator
           if(strlen(argv[2])>1){
               printf("ERROR: Invalid operator\nPass anyone: + , - , * , /\n");
               return FAILURE;
           }

          // first op check
          char *ptr = argv[1];
          int i = 1;

          //store sign
          *firstSign = 1;
          if (!isdigit(ptr[1]))
          {
               printf("ERROR: Operands should contains digits only!\n");
               return FAILURE;
          }
          if(ptr[0]=='-'){ 
               
               *firstSign = -1;
               int i =0;
               while(ptr[i]){     //shift to discard sign
                    ptr[i] = ptr[i+1];
                    i++;
               }
           }
          else if(ptr[0]=='+') {*firstSign = 1;
               int i = 0;
               while (ptr[i]){
                    ptr[i] = ptr[i + 1];
                    i++;
               }
          }
          else if(!isdigit(ptr[0])){
               printf("ERROR: Operands should contains digits only!\n");
               return FAILURE;
          }

          while (ptr[i]){
               if (!isdigit(ptr[i])){
                    printf("ERROR: Operands should contains digits only!\n");
                    return FAILURE;
               }
               i++;
          }
          // second op check
          char *ptr2 = argv[3];
          if (!isdigit(ptr2[1]))
          {
               printf("ERROR: Operands should contains digits only!\n");
               return FAILURE;
          }
          i = 1;
          //store sign
          *secondSign = 1;
          if(ptr2[0]=='+'){ *secondSign = 1;
               int i = 0;
               while (ptr2[i]) {
                    ptr2[i] = ptr2[i + 1];
                    i++;
               }
          }
          else if(ptr2[0]=='-') {*secondSign=-1;
          int i = 0;
               while (ptr2[i]) {
                    ptr2[i] = ptr2[i + 1];
                    i++;
               }}
          else if(!isdigit(ptr2[0])){
               printf("ERROR: Operands should contains digits only!\n");
               return FAILURE;
          }

          while (ptr2[i]){
               if (!isdigit(ptr2[i])){
                    printf("ERROR: Operands should contains digits only!\n");
                    return FAILURE;
               }
               i++;
          }
     }
     return SUCCESS;
}

int opType(char *argv){
       int op;
     if (argv[0] == '+')
          op = 1;
     else if (argv[0] == '-')
          op = 2;
     else if (argv[0] == '*')
          op = 3;
     else if (argv[0] == '/')
          op = 4;
     return op;
}
int finalSign(int big, int op,int firstSign,int secondSign,int*fsign){
          //for multiplication
          if(op==3){
               if(firstSign ==-1 && secondSign ==-1) {
                    *fsign = 1;
                    return 3;
               }
               else if (firstSign == 1 && secondSign == 1)
               {
                    *fsign = 1;
                    return 3;
               }
               else{
                    *fsign = -1;
                    return 3;
               }
          }
          //for division
          if(op==4){
               if(firstSign==-1 && secondSign == -1){
                    *fsign = 1;
                    return 4;
               }else if(firstSign==1 && secondSign==1){
                    *fsign = 1;
                    return 4;
               }
               else{
                    *fsign = -1;
                    return 4;
               }
          }
          //addition
          if(op==1){
               if(firstSign==-1 && big ==1 && secondSign == 1 ){  //op add, 1st -ve, 2nd +ve
                    *fsign = -1;
                    return 2;   //substract
               }
               if (firstSign == -1 && big == 1 && secondSign == -1){
                    *fsign = -1;
                    return 1;   //add
               }
               if(firstSign==1 && big==1 && secondSign == -1){
                  *fsign = 1;
                  return 2;   //substract
               }
               if (firstSign == 1&& big == 1 && secondSign == 1){
                    *fsign = 1;
                    return 1;    //add
               }
               if (firstSign == -1 && big == 2 && secondSign == 1)
               { // op add, 1st -ve, 2nd +ve
                    *fsign = 1;
                    return 2; // substract
               }
               if (firstSign == -1 && big == 2 && secondSign == -1)
               {
                    *fsign = -1;
                    return 1; // add
               }
               if (firstSign == 1 && big == 2 && secondSign == -1)
               {
                    *fsign = -1;
                    return 2; // substract
               }
               if (firstSign == 1&& big == 2 && secondSign == 1)
               {
                    *fsign = 1;
                    return 1; // add
               }
               *fsign =1;
               return 1;
          }
          //substraction
          if(op==2){
               if (firstSign == -1 && big == 1 && secondSign == 1)
               { // op sub, 1st -ve, 2nd +ve
                    *fsign = -1;
                    return 1; // add
               }
               if (firstSign == -1 && big == 1 && secondSign == -1)
               {
                    *fsign = -1;
                    return 2; // sub
               }
               if (firstSign == 1 && big == 1 && secondSign == -1)
               {
                    *fsign = 1;
                    return 1; // add
               }
               if (firstSign == 1 &&big == 1 && secondSign == 1)
               {
                    *fsign = 1;
                    return 2; // sub
               }
               if (firstSign == -1 && big == 2 && secondSign == 1)
               { // op add, 1st -ve, 2nd +ve
                    *fsign = -1;
                    return 1; // add
               }
               if (firstSign == -1 && big == 2 && secondSign == -1)
               {
                    *fsign = 1;
                    return 2; // sub
               }
               if (firstSign == 1 && big == 2 && secondSign == -1)
               {
                    *fsign = 1;
                    return 1; // add
               }
               if (firstSign == 1&& big == 2 && secondSign == 1)
               {
                    *fsign = -1;
                    return 2; // sub
               }
               *fsign =1;
               return 2;
          }
}
int stol(Dlist**head,Dlist**tail,char arr[]){
     int i =0;
     while(arr[i]){
          dl_insert_last(head, tail, arr[i]-48);
          i++;
     }
     return SUCCESS;
}

void dl_insert_last(Dlist **head, Dlist **tail, int data)
{
     // Allocating the memory for new node
     Dlist *new = malloc(sizeof(Dlist));

     new->data = data;
     new->prev = NULL;
     new->next = NULL;

     // If the list is empty then inserting the node as first node
     if (!*head && !*tail) {
          *head = *tail = new;
          return ;
     }
     new->prev = *tail;
     (*tail)->next = new;
     *tail = new;
     return;
}

void insert_first(Dlist **head,Dlist**tail, int data){
    
     Dlist *new = malloc(sizeof(Dlist));
     new->prev = NULL;
     new->data = data;
     new->next=NULL;

     if(*head == NULL && *tail==NULL){
          *head = new;
          *tail = new;
          return ;
     }
     new->next = *head;
     (*head)->prev = new;
     *head = new;
     return ;
}

void printer(Dlist*head){
     while(head){
          printf("%d",head->data);
          head = head->next;
     }
     printf("\n");
}

int len(Dlist *head){
        int count  = 0;
        while (head)
        {
           count++;
           head = head->next;
        }
        return count;
}
int Who_big(Dlist *head1, Dlist*head2){
     if(len(head1)==len(head2)) {
          while(head1->data==head2->data) {
              
               head1 = head1->next;
               head2 = head2->next;
               if (head1 == NULL && head2 == NULL)
                    return 3; // list same exactly
          }
          
          if(head1->data>head2->data) return 1;
          else if((head1->data<head2->data)) return 2;
         
     }
     if(len(head1)>len(head2)) return 1;
     if(len(head1)<len(head2)) return 2;
}

int Cmp(Dlist *head1, Dlist *head2)
{
     if (len(head1) == len(head2))
     {
          while (head1->data == head2->data)
          {

               head1 = head1->next;
               head2 = head2->next;
               if (head1 == NULL && head2 == NULL)
                    return 0; 
          }

          if (head1->data > head2->data)
               return 1;
          else if ((head1->data < head2->data))
               return 0;
     }
     if (len(head1) > len(head2))
          return 1;
     if (len(head1) < len(head2))
          return 0;
}

void copyList(Dlist*h1,Dlist**h2,Dlist**t2){
     while(h1){
          dl_insert_last(h2,t2,h1->data);
          h1 = h1->next;
     }
}

void digitxList(Dlist*tail1,int data,Dlist**head,Dlist**tail){
     int carry = 0;
     while(tail1){
     int ans = tail1->data * data + carry;
     if(ans >9){
          carry = ans/10;
          ans %=10;
     }else carry = 0;
     insert_first(head,tail,ans);
     tail1 = tail1->prev;
     } 
     return;
}

void putZeros(Dlist**head, Dlist**tail,Dlist*zero){
     if(!zero) return;
     Dlist*temp = zero;
     while(temp){
         dl_insert_last(head,tail,0);
         temp = temp->next;
     }
     return ;
}

void countList(Dlist**head, Dlist**tail,int data){
          int carry =0;
          while(*tail){
               int ans = (*tail)->data + carry +data;
               if(ans>9){
                    carry = 1;
                    ans-=10;
                    insert_first(head, tail, ans+carry);
               }else carry = 0;      
          }
}


int dl_delete_list(Dlist **head, Dlist **tail)
{
   if(*head == NULL) return FAILURE;
   
   if(*head == *tail) {
       free(*tail);
      *tail = NULL;
      *head = NULL;
       return SUCCESS;
   }

   while((*tail)!=*head){
        Dlist* temp = *tail;
        *tail = (*tail)->prev;
        free(temp);
        // temp = NULL;
   }
   free(*head );
   *head = NULL;
   return SUCCESS;
}

void filterAns(Dlist**head,Dlist**tail){ // funtion to remove trailing zeros
     Dlist*temp = *head;
     if(*head == *tail) return;
     
     while(temp->data == 0&&temp!=*tail){
          temp= temp->next;
     }
     *head = temp;
     (*head)->prev = NULL;
   
}