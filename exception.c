void    ft_twosort(t_stack *stack_a)
{
    if(stack_a->top > stack_a->next)
        ft_swap(stack_a);
}

void    ft_threesort(t_stack *stack_a)
{
    if(stack_a->top == 1 && stack_a->top->next == 3 && stack_a->top->next->next == 2)
    {
        ft_rotate(stack_a);
        ft_swap(stack_a);
        ft_revercse_rotate(stack_a);
    }
    else if(stack_a->top == 2 && stack_a->top->next == 1 && stack_a->top->next->next == 3)
        ft_swap(stack_a);
    else if(stack_a->top == 2 && stack_a->top->next == 3 && stack_a->top->next->next == 1)
        ft_revercse_rotate(stack_a);
    else if(stack_a->top == 3 && stack_a->top->next == 1 && stack_a->top->next->next == 2)
        ft_rotate(stack_a);
    else if(stack_a->top == 3 && stack_a->top->next == 2 && stack_a->top->next->next == 1)
    {
        ft_swap(stack_a);
        ft_reverse_rotate(stack_a);
    }
}

void ft_fivesort(t_stack *stack_a, t_stack *stack_b)
{
    size_t i;

    i = 0;
    while(i < 5)
    {
        if((stack_a->top[i] & (1 << 1)) == 1)
            ft_push(stack_a, stack_b);
        else
            ft_rotate(stack_a);
        i++;
    }

}