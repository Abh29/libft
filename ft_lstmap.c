#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*root;

	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		ft_lstadd_front(&root, tmp);
		if (root == NULL)
			del(root);
		lst = lst->next;
	}
	return (root);
}
