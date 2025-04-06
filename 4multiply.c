#include "apc.h"

void multiply(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2, Dlist **head, Dlist **tail)
{
    Dlist *t2 = tail2;

    Dlist *ansH = NULL;
    Dlist *ansT = NULL;

    Dlist *zeroH = NULL;
    Dlist *zeroT = NULL;

    Dlist *singleH = NULL;
    Dlist *singleT = NULL;

    Dlist *fh = NULL;
    Dlist *ft = NULL;

    while (t2)
    {

        digitxList(tail1, t2->data, &singleH, &singleT); // multiply single digit with L1
        putZeros(&singleH, &singleT, zeroH);             // It will append zero's node at end

        dl_delete_list(&fh, &ft);
        fh = NULL;
        ft = NULL;

        add(ansH, singleH, ansT, singleT, &fh, &ft);
        dl_delete_list(&ansH, &ansT);
        ansH = NULL;
        ansT = NULL;

        copyList(fh, &ansH, &ansT);

        insert_first(&zeroH, &zeroT, 0);

        dl_delete_list(&singleH, &singleT);
        singleH = NULL;
        singleT = NULL;
        t2 = t2->prev;
    }
    // free memory
    dl_delete_list(&zeroH, &zeroT);
    dl_delete_list(&singleH, &singleT);
    dl_delete_list(&ansH, &ansT);

    *head = fh;
    *tail = ft;
    printf("<-------------------SUCCESS: Multiplication Successfull!--------------------->\n");
    return;
}