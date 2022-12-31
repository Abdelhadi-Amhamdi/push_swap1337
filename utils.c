#include "push_swap.h"

void print_list(t_list *list)
{
	t_list *tmp;
	tmp = list;
	while (tmp)
	{
		printf("%d --", tmp->index);
		printf(" %d\n", tmp->list_data);
		tmp = tmp->next;
	}
}

void make_it_circular(t_stack *a)
{
	t_list *last = get_last_node(a->stack_data);
	last->next = a->top;
	a->top->prev = last;
}

t_list *get_min(t_list *list)
{
	t_list *tmp;
	t_list *min = 0;

	tmp = list;
	min = list;
	while(tmp)
	{
		if(tmp->list_data < min->list_data)
			min = tmp;
		tmp = tmp->next;
	}
	return min;
}

void make_it_not_circular(t_stack *a)
{
	if(a->top->prev)
	{
		a->top->prev->next = NULL;
		a->top->prev = NULL;
	}
}
void print_tab_int(int *tab)
{
	int index = 0;
	while (tab[index])
		printf("%d\n", tab[index++]);
}