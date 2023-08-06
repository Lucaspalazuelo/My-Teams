# My-Teams

## About The Project

`My-Teams` is a Epitech second year project write in C, it's a server-client based collaborative communication platform, reminiscent of Microsoft Teams®. It allows users to manage various communication teams with organized discussions.

## Prerequisites

- Developed and tested primarily on x86-64/Linux.
- Uses TCP sockets for network communication.
- libraries: `libc`.

## Compilation

The program is written in `C` and comes with a `Makefile` that includes the following rules:

- `make`: Compile the program.
- `make re`: Recompile the program.
- `make clean`: Clean object files.
- `make fclean`: Clean object files and the binary.

After compilation, two binaries will be named `myteams_server` and `myteams_cli`.

## Usage
You have the documentation (`DOCUMENTATION.md`) to see all the different commands you can made.

Exemple :
```bash
make all

./myteams_server 8080
./myteams_cli 127.0.0.1 8080
