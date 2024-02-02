# 0x16. C - Simple Shell
*Just like in a terminal you have Bash, Zsh and other types of shell, this is a simple shell called `hsh` that performs basic shell commands.*

## Compilation
Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Files
- atoi.c
- calloc.c
- env.c
- free_grid.c
- memcpy.c
- printnum.c
- realloc_1.c
- simpleshell.c
- tokenize.c
- all_argv.c
- buffer.c
- cmd_checks.c
- error_msg.c
- parse.c
- printstr.c
- realloc_2.c
- signal.c
- unsetenv.c
- all_str_funcs.c
- builtin.c
- com_sc.c
- error_msg2.c
- getline.c
- path.c
- putchar.c
- setenv.c
- simpleshell.h
- unsetenv_check.c
- argv_funcs.c
- builtinerrors.c
- dir.c
- fork.c
- man_1_simple_shell
- printerr.c
- puterror.c
- setenv_check.c
- strcheck.c
- all_help.c
- AUTHORS

## To run the shell
`
($) ./hsh
(hsh)
`

## Testing the shell
```
(hsh) pwd
/home/ivan
(hsh) ls
Desktop    Downloads  Pictures  snap       Videos
Documents  Music      Public    Templates  W3C-Validator
(hsh) cd Desktop`
(hsh) pwd
/home/ivan/Desktop
```
