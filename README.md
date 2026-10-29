# pipex

> Re-creating the shell pipe mechanism.

## What's inside

- Processes with fork, pipe, dup2 and execve
- Input and output redirection
- Equivalent to a two-command shell pipeline with redirections

## Usage

```bash
make
./pipex infile "cmd1" "cmd2" outfile
```

---

*Project completed at [42 Paris](https://42.fr/en/campus/paris/).*
