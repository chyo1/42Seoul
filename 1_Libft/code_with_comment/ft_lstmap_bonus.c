/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:07:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/10/14 20:35:14 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_null(t_list *lst, void *(*f)(void *))
{
	void	*con;

	// 빈 문자열이라면 해당 노드의 content를 바라보게 해 Seg fault 발생시킴
	if (!lst)
		con = f(lst->content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*node;
	void	*con;

	ans = 0;
	// 입력받은 list가 NULL인지 확인
	// why? 이 경우 해당 함수에서 오류 처리를 해주어 다음 함수로 안 넘어가게 처리
	check_null(lst, f);
	while (lst)
	{
		// f 함수 실행 오류
		// f 함수의 반환형이 void *이므로 해당 함수 내에서 동적할당이 이루어짐
		// content의 값만 바꾼다면 반환형이 void였을 것
		con = f(lst->content);
		if (!con)
		{
			ft_lstclear(&ans, del);
			return (0);
		}
		// node 생성 오류
		node = ft_lstnew(con);
		if (!node)
		{
			// 현재까지 생성한 리스트 할당 해제
			ft_lstclear(&ans, del);
			// content를 담고 있는 노드도 할당 해제
			del(con);
			return (0);
		}
		// content, node 모두 정상적으로 할당됐다면 list의 끝에 붙여줌
		ft_lstadd_back(&ans, node);
		
		// 입력받은 list를 탐색
		lst = lst->next;
	}
	return (ans);
}
