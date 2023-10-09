#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    if ((*lst) -> next)
        ft_lstclear((*lst)-> next, del);
    (*del)((*lst) -> content);
    free(*lst);
}