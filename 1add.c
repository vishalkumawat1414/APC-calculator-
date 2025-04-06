#include "apc.h"

void add(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2, Dlist **head, Dlist **tail)
{
    int carry = 0;
    while (tail1 && tail2)
    {
        int ans = tail1->data + tail2->data + carry;
        if (ans > 9)
        {
            carry = 1;
            ans -= 10;
        }
        else
            carry = 0;
        insert_first(head, tail, ans);
        tail1 = tail1->prev;
        tail2 = tail2->prev;
    }

    while (tail1)
    {
        int ans = tail1->data + carry;
        if (ans > 9)
        {
            carry = 1;
            ans -= 10;
        }
        else
            carry = 0;
        insert_first(head, tail, ans);
        tail1 = tail1->prev;
    }
    while (tail2)
    {
        int ans = tail2->data + carry;
        if (ans > 9)
        {
            carry = 1;
            ans -= 10;
        }
        else
            carry = 0;
        insert_first(head, tail, ans);
        tail2 = tail2->prev;
    }
    if (carry)
        insert_first(head, tail, carry);
    return;
}