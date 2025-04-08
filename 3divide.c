#include "apc.h"

void divide(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2, Dlist **head, Dlist **tail)
{
    int big = Who_big(head1, head2); // check which list is bigger
    if (big == 2)
    { // mean list 2 is bigger , so it give 0
        insert_first(head, tail, 0);
        return;
    }
    if (big == 3)
    { // mean both list are exact same , give 1
        insert_first(head, tail, 1);
        return;
    }
    // if list1 is bigger then list2

    if ((head1->data == 0 && head1->next == NULL) && head2->data != 0)
    { // when 0 is divide by no. ,gives 0
        insert_first(head, tail, 0);
        return;
    }

    if (head2->data == 0 && head2->next == NULL)
    {
        printf("ERROR: Dividing by zero\n");
        return;
    }
    if ((head1->data == 0 && head1->next == NULL) && (head2->data == 0 && head2->next == NULL))
    {
        insert_first(head,tail,0);
        return ;
    }
    // step1 copy list2
    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;
    Dlist *nhead = NULL;
    Dlist *ntail = NULL;
    Dlist *temp = head2;
    Dlist *ansH = NULL;
    Dlist *ansT = NULL;
    Dlist *fh = NULL;
    Dlist *ft = NULL;

    while (temp)
    {
        dl_insert_last(&head3, &tail3, temp->data);
        temp = temp->next;
    }
    Dlist *countH = malloc(sizeof(Dlist));
    Dlist *countT = countH;
    countH->data = 1;
    countH->next = NULL;
    countH->prev = NULL;

    int greater;
    while (1)
    {
        greater = 0;
        add(head2, head3, tail2, tail3, &nhead, &ntail);

        countH->data += 1;

        if (countH->data > 9)
        {
            greater = 1;
            add(ansH, countH, ansT, countT, &fh, &ft);

            dl_delete_list(&ansH, &ansT);
            ansH = NULL;
            ansT = NULL;
            copyList(fh, &ansH, &ansT);

            dl_delete_list(&fh, &ft);
            fh = NULL;
            ft = NULL;

            countH->data = 0;
        }
        if (Cmp(head1, nhead) == 0) break;

        dl_delete_list(&head3, &tail3);
        head3 = NULL;
        tail3 = NULL;
        copyList(nhead, &head3, &tail3);
        dl_delete_list(&nhead, &ntail);
        nhead = NULL;
        ntail = NULL;
    }
   
        if(!greater) countH->data--;
        add(countH,ansH,countT,ansT,head,tail);
      
    return;
}
