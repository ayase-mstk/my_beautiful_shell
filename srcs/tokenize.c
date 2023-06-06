#include "tokenize.h"
#include <stdlib.h>

t_token	*init_token()
{
	t_token	*head;
	t_token	*eof;

	head = (t_token *)malloc(sizeof(t_token));
	head->kind = TK_HEAD;
	head->val = 0;
	head->str = NULL;
	head->next = eof;
	eof = (t_token *)malloc(sizeof(t_token));
	eof->kind = TK_EOF;
	eof->val = 0;
	eof->str = NULL;
	eof->next = NULL;
}

void	new_token(t_token *head, int val, char *)
{
	t_token	*cur;

	cur = head;
	while (cur->next->kind != TK_EOF)
		cur = cur->next;
	cur->next = new;
	new->next = init_token();
}