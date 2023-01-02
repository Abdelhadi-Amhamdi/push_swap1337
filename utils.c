#include "push_swap.h"

void print_list(t_list *list)
{
	t_list *tmp;
	int top = list->prev->list_data;
	tmp = list;
	while (tmp)
	{
		printf("%d --", tmp->index);
		printf(" %d\n", tmp->list_data);
		if(tmp->list_data == top)
			break;
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
	t_list  *min;

	min = list;

	while(list)
	{
		list = list->next;
		if(list == min)
			break;
		if(list->list_data < min->list_data)
			min = list;
	}
	return min;
}

void make_it_not_circular(t_stack *a)
{
	a->top->prev->next = NULL;
	a->top->prev = NULL;
}
void print_tab_int(int *tab)
{
	int index = 0;
	while (tab[index])
		printf("%d\n", tab[index++]);
}