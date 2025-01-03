
# pipex - Simplifying UNIX Pipelines  


*A project to recreate UNIX pipe functionality in C.*  
![pipex Banner](https://github.com/user-attachments/assets/1b8df109-0cd0-450c-8374-d46e7512f52d)


---

## Overview  

**pipex** is a project from the 1337 School curriculum that challenges students to recreate the behavior of the `pipe` operator in UNIX systems. The goal is to execute shell commands in sequence while ensuring data flows smoothly between processes through pipes. This project enhances your understanding of inter-process communication, file descriptors, and system calls like `pipe`, `dup2`, and `execve`.  

---

## Key Objectives  

- Master system calls such as `pipe`, `fork`, `dup2`, and `execve`.  
- Learn how to handle process creation and communication.  
- Implement a mini shell-like behavior with command piping.  
- Strengthen error management skills in low-level programming.  

---

## Features  

- Simulates the behavior of the following shell command:  
  ```bash  
  <file1 command1 | command2 >file2  
  ```  
- Executes two commands with input from a file and output to another file.  
- Supports multiple pipes and commands (Bonus).  
- Error handling for invalid commands, file access issues, and pipe creation failures.  

---

## Functionality  

The program must be executed as follows:  
```bash  
./pipex file1 "command1" "command2" file2  
```  
- `file1`: Input file for the first command.  
- `command1`: First shell command to execute.  
- `command2`: Second shell command to execute.  
- `file2`: Output file where the result of `command2` is stored.  

Example:  
```bash  
./pipex input.txt "cat -e" "wc -l" output.txt  
```  
This is equivalent to running:  
```bash  
cat -e < input.txt | wc -l > output.txt  
```  

---

## Getting Started  

### Prerequisites  

- A working C compiler, such as `gcc`.  
- A UNIX-like operating system (Linux, macOS).  

### Installation  

1. Clone the repository:  
   ```bash  
   git clone https://github.com/mkatfi/pipex.git  
   cd pipex  
   ```  

2. Build the program:  
   ```bash  
   make  
   ```  

   This will generate an executable named `pipex`.  

---

## Usage  

1. Run the program with valid arguments:  
   ```bash  
   ./pipex file1 "command1" "command2" file2  
   ```  

2. Example:  
   ```bash  
   ./pipex input.txt "grep 42" "wc -l" output.txt  
   ```  

3. Check the contents of `output.txt` for the result.  

---

## Project Structure  

| File                  | Description                                      |  
|-----------------------|--------------------------------------------------|  
| `pipex.c`             | Main program logic and process handling.         |  
| `pipex_utils.c`       | Utility functions for file and error management. |  
| `pipex.h`             | Header file with function prototypes.            |  
| `Makefile`            | Script to compile the program.                   |  

---

## Bonus Features  

- **Multiple Commands:** Handle multiple commands in a pipeline:  
  ```bash  
  ./pipex file1 "command1" "command2" "command3" file2  
  ```  
- **Here Document:** Support heredoc functionality for dynamic input:  
  ```bash  
  ./pipex here_doc "STOP" "command1" "command2" file2  
  ```  
- **Improved Error Handling:** Gracefully handle edge cases like empty files or invalid commands.  

---

## Testing  

### Run Basic Tests  
1. Create an input file:  
   ```bash  
   echo -e "Hello\nWorld\n42" > input.txt  
   ```  

2. Test the program:  
   ```bash  
   ./pipex input.txt "cat -e" "wc -l" output.txt  
   ```  

3. Check the output:  
   ```bash  
   cat output.txt  
   ```  
