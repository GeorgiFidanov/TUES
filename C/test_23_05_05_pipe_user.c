//Напишете програма на С, която извежда колко са уникалните различни логин шелове 
//описани в /etc/passwd в рамките на вашата ОС.
//cut -d : -f 7 /etc/passwd | sort | uniq | wc -l

//exit, read, write, close, pipe
#include <unistd.h>
// open:
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
// printf:
#include<stdio.h>
// c without strings is a nightmare
#include<string.h>
// exit
#include<stdlib.h>
// wait
#include <sys/wait.h>

void execute_command(char* command) {
    int pipe_fd[2];
    int pid;

    // Create a pipe
    int temp_pipe = pipe(pipe_fd);
    if (temp_pipe < 0) {
        printf("Unable to create pipe.\n");
        exit(1);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        printf("Unable to fork.\n");
        exit(1);

    } else if (pid == 0) { // Child process

        // Duplicate the write end of the pipe to the stdout
        dup2(pipe_fd[1], STDOUT_FILENO);

        // Close unused file descriptors
        close(pipe_fd[0]);
        close(pipe_fd[1]);

        char* args[32];
        int arg_count = 0;
        char* token = strtok((char*)command, " ");
        while (token != NULL) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        // Open a temporary file to redirect the output
        int temp_file = open("temp_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (temp_file < 0) {
            printf("Unable to open temporary file.\n");
            exit(1);
        }

        // Redirect the output to the temporary file
        dup2(temp_file, STDOUT_FILENO);

        // Execute the command
        execvp(args[0], args);

        printf("Error: execvp() failed\n");
        exit(1);

    } else { // Parent process

        // Close the write end of the pipe
        close(pipe_fd[1]);

        // Wait for the child process to exit
        wait(NULL);

        // Open the temporary file for reading
        int temp_file = open("temp_file.txt", O_RDONLY);
        if (temp_file < 0) {
            printf("Unable to open temporary file.\n");
            exit(1);
        }

        char buffer[1024];
        int bytes_read;

        // Read the output from the temporary file
        while ((bytes_read = read(temp_file, buffer, sizeof(buffer))) > 0) {
            // Process the output by printing it to stdout
            write(STDOUT_FILENO, buffer, bytes_read);
        }

        // Close the temporary file
        close(temp_file);

        // Delete the temporary file
        unlink("temp_file.txt");

        // Close the read end of the pipe
        close(pipe_fd[0]);
    }
}

int main(int argc, char* argv[]) {
   
    if (argc != 2) {
        printf("Wrong amount of arguments.\n");
        exit(1);
    }

    char* input_string = argv[1];
    int input_length = strlen(input_string);

    char command[1024];
    memset(command, 0, sizeof(command));
    int command_index = 0;
    
    for (int i = 0; i < input_length; i++) {
        char character = input_string[i];
        if (character == '|') {
            command[command_index] = '\0';
            execute_command(command);
            memset(command, 0, sizeof(command));
            command_index = 0;

        } else {
            command[command_index++] = character;
        }
    }

    // Execute the command
    execute_command(command);

    return 0;
}
