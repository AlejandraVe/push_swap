#include "push_swap.h"

static void    check_b_position(Stack *a, Stack *b, Stack *cheapest)
{
    if (cheapest->target_node->above_median)
    {
        while (b != cheapest->target_node || a != cheapest)
        {
            if (b != cheapest->target_node && a == cheapest)
                rb(&b, true);
            else if (b == cheapest->target_node && a != cheapest)
                ra(&a, true);
        }
    }
    else if (!cheapest->target_node->above_median)
    {
        while (b != cheapest->target_node || a != cheapest)
        {
            if (b != cheapest->target_node && a == cheapest)
                rrb(&b, true);
            else if (b == cheapest->target_node && a != cheapest)
                rra(&a, true);
        }
    }
    check_index(a);
    check_index(b);
}

/*static void    check_b_position_reverse(Stack *a, Stack *b, Stack *cheapest)
{
    while (b != cheapest->target_node || a != cheapest)
    {
        if (b != cheapest->target_node && a == cheapest)
            rrb(&b, true);
        else if (b == cheapest->target_node && a != cheapest)
            rra(&a, true);
    }
    check_index(a);
    check_index(b);
}*/

void    check_rotation_both(Stack *a, Stack *b, Stack *cheapest)
{
    while (b != cheapest->target_node && a != cheapest)
        rr(&a, &b, true);
    /*while (1)
    {
        if (b == cheapest->target_node && a != cheapest)
            ra(&a, true);
        else if (b != cheapest->target_node && a == cheapest)
            rb(&b, true);
        else if (b == cheapest->target_node && a == cheapest)
            break;
    }*/
    check_b_position(a, b, cheapest);
}

void    check_rev_rotation_both(Stack *a, Stack *b, Stack *cheapest)
{
    while (b != cheapest->target_node && a != cheapest)
        rrr(&a, &b, true);
   /* while (1)
    {
        if (b == cheapest->target_node && a != cheapest)
            rra(&a, true);
        else if (b != cheapest->target_node && a == cheapest)
            rrb(&b, true);
        else if (b == cheapest->target_node && a == cheapest)
            break;
    }*/
    check_b_position(a, b, cheapest);
}
