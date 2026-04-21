# minishell1

> A UNIX command interpreter built in C, based on TCSH. Handles command execution via PATH, environment management, and essential builtins.

![Language](https://img.shields.io/badge/Language-C-blue)
![Binary](https://img.shields.io/badge/Binary-mysh-gray)
![School](https://img.shields.io/badge/Epitech-project-purple)

---

## About

`mysh` displays a prompt, reads user input, resolves commands through the `PATH`, forks child processes via `execve`, and propagates exit codes correctly. The environment is copied and managed independently from the parent process.

---

## Builtins

| Command | Description |
|---------|-------------|
| `cd` | Change current directory |
| `env` | Display environment variables |
| `setenv` | Set an environment variable |
| `unsetenv` | Remove an environment variable |
| `exit` | Exit the shell |

---

## Features

- Command resolution via `PATH`
- Direct path execution (e.g. `/bin/ls`)
- Correct exit code propagation
- Error messages written to stderr
- Environment copy & restore

---

## Build & Run

```bash
# Build
make

# Interactive mode
./mysh

# Pipe mode
echo "ls -l" | ./mysh
```

---

## Demo

```
$> ./mysh
$> pwd
/home/user
$> cd /tmp
$> pwd
/tmp
$> setenv MY_VAR hello
$> env
...
MY_VAR=hello
$> exit
```

---

## Makefile rules

```bash
make        # build
make clean  # remove object files
make fclean # remove binary too
make re     # full rebuild
```

---

## Author

> Built with ❤️ as part of the Epitech curriculum.
