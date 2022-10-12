/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:14:57 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:31:16 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <limits.h>

# define OP_COUNT 16
# define COUNT g_vm.cycle.count

# define STR_PLAYER "* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n"
# define STR_WINNER "Contestant %i, \"%s\", has won !\n"
# define STR_LIVE "un processus dit que le joueur %d(%s) est en vie\n"
# define LDI "%d: Player %d process %d: [LDI] loaded PC + %d in reg %d\n"
# define LLDI "%d: Player %d process %d: [LLDI] loaded PC + %d in reg %d\n"
# define LLD "%d: Player %d process %d: [LLD] write %d in reg %d\n"
# define ST "%d: Player %d process %d: [ST] write reg %d data at PC + %d\n"
# define ST2 "%d: Player %d process %d: [ST] write reg %d data in reg %d\n"
# define STI "%d Player %d process %d: [STI] write reg %d data at PC + %d\n"
# define ADD "%d: Player %d process %d: [%s] write %d in reg %d\n"
# define FORK "%d: Player %d process %d: [%s] at %d\n"
# define ZJMP "%d: Player %d process %d: [ZJMP] jump at PC + %d\n"
# define LIVE "%d: Player %d process %d: [LIVE]\n"
# define AFF "%d: Player %d process %d: Aff: %c\n"

typedef char		t_reg[REG_SIZE];

typedef struct		s_op
{
	char			*name;
	int				nbr_args;
	t_arg_type		args[3];
	int				op_code;
	int				nbr_cycle;
	char			*comment;
	int				codage_octal;
	int				idx;
}					t_op;

typedef struct		s_op_arg
{
	char			*arg;
	size_t			size;
	int				value;
	t_arg_type		type;
}					t_op_arg;

typedef struct		s_option
{
	int				aff;
	int				dump_cycle;
	int				hide;
	int				sdump;
	int				number;
	int				verbose;
	int				sound;
}					t_option;

typedef struct		s_cycle
{
	int				last_live;
	unsigned int	count;
	unsigned int	cycle_to_die;
	unsigned int	cycle_to_check;
	unsigned int	count_checks;
}					t_cycle;

typedef struct		s_proc
{
	t_reg			reg[REG_NUMBER];
	char			*pc;
	t_op			*op;
	int				carry;
	int				live;
	int				wait;
	unsigned int	id;
	unsigned int	nb;
}					t_proc;

typedef struct		s_player
{
	int				number;
	char			*name;
	char			*comment;
	char			*bytecode;
	int				prog_size;
	int				current_live;
	int				last_live;
	char			*pc;
	int				forced_number;
}					t_player;

typedef struct		s_vm
{
	t_player		*player;
	t_cycle			cycle;
	t_proc			*process;
	int				process_count;
	t_option		option;
	char			*map;
	int				player_count;
	int				reg_error;
	int				sound[4];
}					t_vm;

extern	t_vm		g_vm;
extern	t_op		g_op_tab[17];

void				error(char *file, char *str);

void				parse_vm(int ac, char **av, t_option *opt);

t_player			*find_player(int id);
void				read_player(char *file);

void				swap_position(t_player *player);

void				rev_cpy(char *dst, char *src, size_t type_size);
t_reg				*get_register(t_reg *registers, int value);
void				push_register(t_reg reg[REG_SIZE], char *value);
void				pull_register(t_reg reg[REG_SIZE], char *value);
void				copy_register(t_reg r1[REG_SIZE], t_reg r2[REG_SIZE]);

void				lunch_vm(void);

int					handle_cycle(t_cycle *cycle);

t_proc				*create_process(char *pc, t_proc *parent, int nb);
void				kill_process(int count);
char				get_byte_index(char *address);
char				*go_next_op(t_proc *process, int offset);
void				lunch_process(void);

int					lunch_do_op(t_proc *process);
int					get_value(t_proc *proc, t_op_arg *arg, int i, int long_op);

size_t				get_argument_op(t_proc *process, int opcode,
					t_op_arg args[3]);

void				write_on_map(char *src, char *pc, size_t size);
void				read_on_map(char *dst, char *pc, size_t range);

void				ft_live(t_proc *proc, t_op_arg args[3]);
void				ft_ld(t_proc *proc, t_op_arg args[3]);
void				ft_st(t_proc *process, t_op_arg args[3]);
void				ft_add(t_proc *process, t_op_arg args[3]);
void				ft_sub(t_proc *process, t_op_arg args[3]);
void				ft_and(t_proc *process, t_op_arg args[3]);
void				ft_or(t_proc *process, t_op_arg args[3]);
void				ft_xor(t_proc *process, t_op_arg args[3]);
void				ft_zjmp(t_proc *process, t_op_arg args[3]);
void				ft_ldi(t_proc *process, t_op_arg qrgs[3]);
void				ft_sti(t_proc *process, t_op_arg arg[3]);
void				ft_fork(t_proc *process, t_op_arg args[3]);
void				ft_lld(t_proc *process, t_op_arg args[3]);
void				ft_lldi(t_proc *process, t_op_arg args[3]);
void				ft_lfork(t_proc *process, t_op_arg args[3]);
void				ft_aff(t_proc *process, t_op_arg args[3]);

#endif
