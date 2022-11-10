
#ifndef STACK_H
#define STACK_H
#include "libc.h"

typedef struct stack
{
    int top;
    int *data;
    unsigned opacity;

} m_stack;

m_stack *creat_stack(unsigned int capacity);
void push(m_stack *stack, int data);
int is_empty(m_stack *stack);
int is_full(m_stack *stack);
int pop(m_stack *stack);
int peek(m_stack *stack);
void sa(m_stack *a);
void sb(m_stack *b);
void ss(m_stack *b , m_stack *a);
void pa(m_stack *b , m_stack *a);
void pb(m_stack *b , m_stack *a);
void ra(m_stack *a);
void rb(m_stack *b);
void rr(m_stack *a, m_stack *b);
void rra(m_stack *a);
void rrb(m_stack *b);
void rrr(m_stack *a, m_stack *b);
#endif