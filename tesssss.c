#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void ft_pp(void *lst)
{
	static int i = 1;

	printf("%d stroka === %s\n", i++, (char *)lst);
}


void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

// int main()
// {
// 	t_list  *begin_list;
// 	char s[6] = "hello\0";
// 	char s2[7] = "people\0";
// 	char s3[5] = "fuck\0";

// 	begin_list = (t_list *)malloc(sizeof(t_list));
// 	begin_list->data = strdup(s);
// 	begin_list->next = (t_list *)malloc(sizeof(t_list));
// 	begin_list->next->data = strdup(s2);
// 	begin_list->next->next = (t_list *)malloc(sizeof(t_list));
// 	begin_list->next->next->data = strdup(s3);
// 	begin_list->next->next->next = 0;
// 	ft_list_foreach(begin_list, &ft_pp);
// 	return (0);
// }

// ======== 


int main()
{
	t_list  *begin_list;
	t_list  *buf;
	char s[6] = "hello\0";
	char s2[7] = "people\0";
	char s3[5] = "fuck\0";

	begin_list = (t_list *)malloc(sizeof(t_list));
	buf = begin_list;
	begin_list->data = strdup(s);
	begin_list->next = (t_list *)malloc(sizeof(t_list));
	begin_list = begin_list->next;
	begin_list->data = strdup(s2);
	begin_list->next = (t_list *)malloc(sizeof(t_list));
	begin_list = begin_list->next;
	begin_list->data = strdup(s3);
	begin_list = begin_list->next;
	begin_list = 0;
	ft_list_foreach(buf, &ft_pp);
	return (0);
}
