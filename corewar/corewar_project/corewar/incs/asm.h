/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:31:58 by hivian            #+#    #+#             */
/*   Updated: 2017/04/28 15:48:54 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>

# define LINE "======================================"
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define REG_CHAR				'r'

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct					s_op
{
	char			*name;
	int				nbr_args;
	t_arg_type		args[3];
	int				op_code;
	int				nbr_cycle;
	char			*comment;
	int				codage_octal;
	int				idx;
}								t_op;

typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

typedef struct					s_node
{
	char						*name;
	struct s_node				*next;
}								t_node;

typedef struct					s_label
{
	t_node						*head;
}								t_label;

typedef struct					s_env
{
	int							fd_src;
	int							fd_dst;
	int							filesize;
	int							lines;
	char						*s_file;
	char						**a_file;
	bool						label_flag;
	bool						start_quote;
	bool						end_quote;
	char						*dot_name;
	char						*dot_comment;
	t_label						*labels;
	char						**a_tmp;

	char						*file_name;
	int							verbose;
	int							*off_limit;
	int							i;
	char						**op_list;
	int							offset;
	int							nb_instruction;
	int							progsize;
	int							**tab_instruction;
	int							nb_of_label;
	char						**label;
	int							*label_offset;
	int							nb_of_label_call;
	char						**label_sneak;
	int							**label_offset_sneak;

}								t_env;

void							print_error(char *msg, char *str);
void							open_file(char *arg, t_env *e);
void							save_file(t_env *e);
void							run_lexer_parser(t_env *e);
void							remove_comments(t_env *e);
void							check_n_c(t_env *e, char *str, char *tag);
void							check_tag(char *tag);
void							check_label(t_env *e);
char							**split_custom(char const *s, char c);
int								strchr_comment(const char *s);
char							*trim_quotes(char const *s);
int								ft_isnumber(char *arg);
int								label_exist(char *str, t_env *e);
void							check_first(char *s, t_env *e);
void							check_aff(char *s);
void							check_aox(char *s, t_env *e);
void							check_ld(char *s, t_env *e);
void							check_ldi(char *s, t_env *e);
void							check_as(char *s);
void							check_st(char *s, t_env *e);
void							check_sti(char *s, t_env *e);
void							check_dir(char *s, t_env *e);
void							check_ind(char *s, t_env *e);
void							check_reg(char *s);
void							check_commas(char *s, size_t max);
t_label							*create_list(void);
void							clear_list(t_label *list);
void							print_list(t_label *list);
void							list_push_back(t_label *list, char *data);
void							run_encoder(t_env *e);
void							ft_creat_header(t_env *e, char *av);
void							ft_write_file(t_env *e);
void							ft_write_size(t_env *e);
void							*reverse_bits(void *buff, int size);
void							ft_epur_from_comma(t_env *e, char c, int index);
char							*epur_str(char *s);
int								malloc_epured(char *str);
void							ft_init_tab(t_env *e, int nb_instruction);
void							ft_count_label_approx(t_env *e, int nb_instr);
void							ft_init_label_env(t_env *e, int nb_of_label);
int								ft_is_label(char *str);
void							ft_add_label(t_env *e, char *label_name);
void							ft_analyzer(t_env *e, char **tmp, int index);
int								is_reg(char *str);
int								is_direct(char *str);
int								is_indirect(char *str);
int								is_direct_label(char *str);
int								is_indirect_label(char *str);
void							ft_label_sneak(t_env *e, char *label_name,
	int nb_o, int *opcode_pos);
int								ft_sum_of_size(t_env *e, int offset);
int								which_op(char *str);
int								which_kind(char *str);
int								how_many_elem(char *str);
char							**ft_stronesplit(char const *s, char c);
void							ft_display_label_list(t_env *e);
void							ft_display_offset(t_env *e);
void							ft_display_informations(t_env *e);

extern					t_op g_op_tab[17];

#endif
