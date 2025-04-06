#include <stdio.h>
#include "apc.h"

int main(int argc , char*argv[]){
    Dlist*head = NULL;
    Dlist*tail = NULL;
    Dlist*head1 = NULL;
    Dlist*tail1= NULL;
    Dlist*head2= NULL;
    Dlist*tail2 = NULL;

    //for operand signs
    int firstSign,secondSign;
    
    if(validate(argc,argv,&firstSign,&secondSign)==SUCCESS){

        //make list1 and list2 from strings
        if(stol(&head1,&tail1,argv[1])) printf("SUCCESS: List1 successfully created!\n");
        if(stol(&head2,&tail2,argv[3]))printf("SUCCESS: List2 successfully created!\n");
         printer(head1);
         printer(head2);

         // check operation type
        int fsign = 1;   //final sign for result
        int res = opType(argv[2]);
        int big = Who_big(head1,head2);
        res = finalSign(big,res,firstSign,secondSign,&fsign);
        printf("Sign: %d\n",fsign);
        switch (res)
        {
        case 1:
            add(head1,head2,tail1 ,tail2 ,&head,&tail);
            filterAns(&head,&tail);
            printf("RESULT: ");
            printer(head);
            break;
        case 2:
             sub(head1, head2, tail1, tail2, &head, &tail);
             filterAns(&head, &tail);
             printf("RESULT: ");
             printer(head);
             break;
        case 3:
             multiply(head1, head2, tail1, tail2, &head, &tail);
             filterAns(&head, &tail);
             printf("RESULT: ");
             printer(head);
            break;
        case 4:
            divide(head1, head2, tail1, tail2, &head, &tail);
            filterAns(&head, &tail);
            printf("RESULT: ");
            printer(head);
            break;
        }
    }
    else{
        printf("ERROR: Validation Failed\n");
    }
}