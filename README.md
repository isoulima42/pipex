*This project has been created as part of the 42 curriculum by isoulima.*

# pipex

<img src="score.png" width="150" alt="Score 100/100">

![Language](https://img.shields.io/badge/Language-C-blue)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen)

## Description

pipex reproduces the behavior of the shell pipe: `< file1 cmd1 | cmd2 > file2`.
It creates two child processes with `fork()`, connects them with a `pipe()`, and runs
each command with `execve()` after resolving its path through the `PATH` variable.
The project introduces concurrent programming: it is the first 42 project where
two processes run at the same time. The exit code returned is the one of `cmd2`.

---

## Instructions

### Compilation

```bash
make
```

A `pipex` executable is generated.

```bash
make clean    # removes the .o files
make fclean   # removes the .o files and pipex
make re       # rebuilds everything
```

### Usage

```bash
./pipex file1 "cmd1" "cmd2" file2
```

Shell equivalent:

```bash
< file1 cmd1 | cmd2 > file2
```

Concrete example:

```bash
./pipex /etc/passwd "grep root" "wc -l" out.txt
```

---

## Features

- Automatic command resolution through `PATH`
- Commands with arguments (`"grep -i pattern"`, `"sort -r"`)
- Absolute paths accepted (`"/bin/cat"`)
- Missing `file1`: error on stderr, `cmd2` receives an empty input
- Command not found: `perror` on stderr, `exit(127)`
- `file2` created if it does not exist, truncated if it does (`O_TRUNC`)
- Exit code = exit code of `cmd2`

---

## Technical choices

- **Two sequential forks** — `child_one` and `child_two` are launched from the parent,
  which then closes both ends of the pipe before waiting for the children.
- **`/dev/null` fallback** on a missing `file1` — lets `cmd2` run with an empty input
  instead of aborting the whole command.
- **PATH resolution**: `get_env_path` extracts the `PATH` variable from `env[]`,
  `ft_split` splits it on `:`, `try_paths` tests each directory with `access(X_OK)`.
- **libft dependency**: `ft_split`, `ft_strjoin`, `ft_strdup`, `ft_strncmp`, `ft_putstr_fd`.

---

## Resources

- `man 2 pipe`
- `man 2 fork`
- `man 2 execve`
- `man 2 dup2`
- `man 2 waitpid`
- `man 2 access`
- Official 42 subject

---

## AI usage

AI was used only to:
- clarify how `pipe()`, `fork()` and `execve()` work
- structure this README

The implementation, the logic and the understanding of the code were done manually.

---

## Author

42 Lausanne
Login: isoulima
