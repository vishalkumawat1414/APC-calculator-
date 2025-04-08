#include "apc.h"

void sub(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2, Dlist **head, Dlist **tail)
{
    int big = Who_big(head1, head2);
    // if 2nd is big swap
    int sign = 1;
    if (big == 2)
    {
        sign = -1;
        Dlist *temp = tail1;
        tail1 = tail2;
        tail2 = temp;
    }

    int borrow = 0;
    while (tail1 && tail2)
    {
        if (borrow)
            tail1->data -= 1;
        
        if (tail1->data < tail2->data)
        {   Dlist *trav = tail1->prev;
            borrow = 1;
            while(trav->data==0){
                trav->data = 9;
                trav = trav->prev;
                borrow=0;
            }
           if(borrow==0) trav->data = trav->data-1;
            
            
            tail1->data += 10;
        }
        else
            borrow = 0;

        int ans = tail1->data - tail2->data;
        insert_first(head, tail, ans);
        tail1 = tail1->prev;
        tail2 = tail2->prev;
    }
    while (tail1)
    {   
        int ans = tail1->data - borrow;
        borrow = 0;
        insert_first(head, tail, ans);
        tail1 = tail1->prev;
    }
    while (tail2)
    {
        int ans = tail2->data - borrow;
        borrow =0;
        insert_first(head, tail, ans);
        tail2 = tail2->prev;
    }return ;
}