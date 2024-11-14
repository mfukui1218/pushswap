#include "pushswap.h"

// t_stack	*init_stack(size_t s, size_t *values)
// {
// 	t_stack	*stack;
// 	t_node	*node;
// 	size_t	i;

// 	stack = (t_stack *)malloc(sizeof(t_stack));
// 	if (!stack)
// 		return (ft_error(4), NULL);
// 	stack->top = NULL;
//     stack->size = 0;
// 	i = 0;
// 	while(i < s)
// 	{
// 		node = (t_node *)malloc(sizeof(t_node));
// 		if (!node)
// 			return (ft_malloc_node(stack), NULL);
// 		node->data = values[i];
//         node->next = stack->top;
//         node->prev = NULL;
// 		if (stack->top)
//             stack->top->prev = node;
//         stack->top = node;
//         stack->size++;
// 		i++;
// 	}
// 	return (stack);
// }

void	ft_malloc_node(t_stack *stack)
{
	t_node	*current;

	while (stack->top)
	{
		current = stack->top;
		stack->top = stack->top->next;
		free(current);
	}
	free(stack);
	ft_error(4);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

t_stack *init_stack(size_t size, size_t *values)
{
    t_stack *stack;
    t_node *node;
    size_t i;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (ft_error(4), NULL);
    stack->top = NULL;
    stack->size = 0;
    i = 0;
    while (i < size)
    {
        node = (t_node *)malloc(sizeof(t_node));
        if (!node)
            return (free_stack(stack), NULL);
        node->data = values[i];
        node->next = stack->top;
        node->prev = NULL;
        if (stack->top)
            stack->top->prev = node;
        stack->top = node;
        stack->size++;
        i++;
    }
    return stack;
}
