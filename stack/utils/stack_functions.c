
#include "../includes/stack.h"

m_stack *creat_stack(unsigned int capacity)
{
    m_stack *stack;

    stack = (m_stack *)malloc(sizeof(m_stack));
    if (!stack)
        return 0;
    stack->top = -1;
    stack->opacity = capacity;
    stack->data = (int *)malloc(capacity * sizeof(int));
    return stack;
}

int is_full(m_stack *stack)
{
    return (stack->top == ((int)stack->opacity) - 1);
}

int is_empty(m_stack *stack)
{
    return (stack->top == -1);
}

void push(m_stack *stack, int data)
{
    if (is_full(stack))
        return;
    stack->data[++stack->top] = data;
}

int pop(m_stack *stack)
{
    if (is_empty(stack))
        return -1;
    return stack->data[stack->top--];
}

int peek(m_stack *stack)
{
    if (is_empty(stack))
        return -1;
    return stack->data[stack->top];
}
