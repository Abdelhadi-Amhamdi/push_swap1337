
#include "stack/includes/stack.h"

int main(int ac, char **av)
{
    m_stack *a = NULL;
    m_stack *b = NULL;
    int i = 0;

    if (ac > 1)
    {
        a = creat_stack(10);
        while (i < ac - 1)
        {
            push(a, atoi(av[i]));
            i++;
        }
        printf("\n-------------------\n");
        while (a->top != -1)
        {
            printf("%d ,", peek(a));
            a->top--;
        }
        printf("\n---------------\n");
        b = creat_stack(10);
        sa(a);
        pb(b, a);
        pb(b, a);
        pb(b, a);
        rr(a, b);
        rrr(a, b);
        sa(a);
        pa(b, a);
        pa(b, a);
        pa(b, a);
    }
    // m_stack *a;

    // a = creat_stack(10);

    return 0;
    // rra(a);
    // printf("\n-------------------\n");
    // while (a->top != -1)
    // {
    //     printf("%d ,", peek(a));
    //     a->top--;
    // }
    // printf("\n---------------\n");
}