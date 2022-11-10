
#include "stack/includes/stack.h"

void sa(m_stack *a)
{
    int tmp;
    if (a->top == -1)
        return;
    tmp = a->data[a->top];
    a->data[a->top] = a->data[a->top-1];
    a->data[a->top-1] = tmp;
}

void sb(m_stack *b)
{
    int tmp;
    if (b->top == -1)
        return;
    tmp = b->data[b->top];
    b->data[b->top] = b->data[b->top-1];
    b->data[b->top-1] = tmp;
}

void ss(m_stack *b , m_stack *a)
{
    sa(a);
    sb(b);
}

void pa(m_stack *b , m_stack *a)
{
    if(is_empty(b))
        return;
    push(a, b->data[b->top]);
}

void pb(m_stack *b , m_stack *a)
{
    if(is_empty(a))
        return;
    push(b, a->data[a->top]);
}

void ra(m_stack *a)
{
    int index1 = a->top;
    while (index1)
    {
        int tmp;
        int index2 = index1 - 1;
        tmp = a->data[index1];
        a->data[index1] = a->data[index2];
        a->data[index2] = tmp;
        index1 = index2;
    }
}

void rb(m_stack *b)
{
    int index1 = b->top;
    while (index1)
    {
        int tmp;
        int index2 = index1 - 1;
        tmp = b->data[index1];
        b->data[index1] = b->data[index2];
        b->data[index2] = tmp;
        index1 = index2;
    }
}

void rr(m_stack *a, m_stack *b)
{
    ra(a);
    rb(b);
}

void rra(m_stack *a)
{
    int index1 = 0;
    int top = a->top;
    while (index1 < top)
    {
        int tmp;
        int index2 = index1 + 1;
        tmp = a->data[index1];
        a->data[index1] = a->data[index2];
        a->data[index2] = tmp;
        index1 = index2;
    }
}

void rrb(m_stack *b)
{
    int index1 = 0;
    int top = b->top;
    while (index1 < top)
    {
        int tmp;
        int index2 = index1 + 1;
        tmp = b->data[index1];
        b->data[index1] = b->data[index2];
        b->data[index2] = tmp;
        index1 = index2;
    }
}

void rrr(m_stack *a, m_stack *b)
{
    rra(a);
    rrb(b);
}