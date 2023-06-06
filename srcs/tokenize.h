#ifndef TOKENIZE_H
# define TOKENIZE_H

typedef enum s_tokenkind
{
	TK_HEAD,
	TK_RESERVED,
	TK_NUM,
	TK_EOF,
}	t_tokenkind;

typedef struct s_token
{
	t_tokenkind		kind;
	struct s_token	*next;
	int				val;
	char			*str;
}	t_token;

#endif