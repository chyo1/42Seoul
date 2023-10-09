#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    int     size;
    t_list  *ans;

    size = ft_lstsize(lst);
    ans = (t_list *) malloc (sizeof(t_list) * size);
    if (ans == NULL)
        return (NULL);
    ans = lst;

    return (ans);
}

/// when shoud I using del func?