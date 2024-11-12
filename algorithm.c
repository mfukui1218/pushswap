void    ft_algorithm(t_stack *stack_a, t_stack *stack_b)
{
    size_t i;
    size_t d;
    size_t c;

    i = 0;
    d = 0;
    while(d < ft_max_bitlen(stack_a))
    {
        i = 0;
        while(i < stack_a->size)
        {
            if ((stack_a->top[i] & (1 << d)) == 0)
                ft_push(stack_a, stack_b);
            else
                ft_rotate(stack_a);
            i++;
        }
        d++;
        i = 0;
        c = 0;
        while(i < stack_b->size)
        {
            if ((stack_b->top[i] & (1 << d)) == 1)
            {
                ft_push(stack_b, stack_a);
                c++;
            }
            else
                ft_rotate(stack_b);
            i++;
        }
        i = 0;
        while(i < stack_a->size)
        {
            if(i < c)
            {
                ft_rotate(stack_a);
                i++; 
            }
            else
            {
                if((stack_a->top[i] & (1 << d)) == 0)
                    ft_push(stack_a, stack_b);
                else
                    ft_rotate(stack_b);
                i++;
            }
        }
    }
}