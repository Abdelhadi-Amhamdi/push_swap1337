#include "push_swap.h"

void print_list(t_list *list)
{
	t_list *tmp;
	int top;
	if(list)
	{
		tmp = list;
		top = tmp->prev->list_data;
		printf("index ");
		printf("less ");
		printf("long ");
		printf("data\n");
		while (tmp)
		{
			printf("%d -----", tmp->index);
			printf("%d -----", tmp->less_than);
			printf("%d -----", tmp->is_longest);
			printf(" %d\n", tmp->list_data);
			if(tmp->list_data == top)
				break;
			tmp = tmp->next;
		}
	}
}

void reindex_list(t_list *list)
{

	int top = list->list_data;
	int index = 0;


	while (list)
	{
		list->less_than = index;
		list = list->next;
		if(list->list_data == top)
			break;
		index++;
	}
}

void index_by_sort(t_list *list, int size)
{
	t_list *fmin = get_next_min(list , NULL);
	int index = 0;

	while(1)
	{
		fmin->index = index;
		fmin = get_next_min(list, fmin);
		index++;
		if(index == size)
			break;
	}
}

t_list *get_next_min(t_list *list, t_list *fmin)
{
	t_list *min = NULL;
	int top;

	top = list->list_data;

	if(!fmin)
		return(get_min(list));
	while(list)
	{
		if(!min && list->list_data > fmin->list_data)
			min = list;
		if(list->list_data > fmin->list_data && list->list_data < min->list_data)
			min = list;
		list = list->next;
		if(list->list_data == top)
			break;
	}
	return min;
}

void make_list_circular(t_stack *a)
{
	if(a->stack_data)
	{
		t_list *last = get_last_node(a->stack_data);
		last->next = a->top;
		a->top->prev = last;
	}
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

int ft_search(t_list *list, int index)
{
	t_list *tmp;
	int top;

	tmp = list;
	top = tmp->list_data;
	while(1)
	{
		if(tmp->index > index)
			return (tmp->less_than);
		tmp = tmp->next;
		if(tmp->list_data == top)
			return -1;
	}
	return -1;
}

t_list *get_max(t_list *list)
{
	t_list *tmp;
	t_list *max;
	int max_index;

	max_index = list->less_than;
	max = list->next;
	tmp = max->next;

	while(1)
	{
		if(tmp->less_than >= max_index)
			break;
		if(tmp->less_than > max->less_than && tmp->less_than < max_index && tmp->less_than)
		{
			max = tmp;
		}
		tmp = tmp->next;
	}
	return max;
}	

void make_list_not_circular(t_stack *a)
{
	if(a->stack_data)
	{
		a->top->prev->next = NULL;
		a->top->prev = NULL;
	}
}


t_list *get_last_node(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while(tmp->next)
		tmp =tmp->next;
	return tmp;
}