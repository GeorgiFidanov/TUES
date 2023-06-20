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

void pipe_funk(int in, int out) { //gets data from one pipe to another
    char buffer[1024];
    int curr;

    while ((curr = read(in, buffer, sizeof(buffer))) > 0) {
        if (write(out, buffer, curr) != curr) {
            printf("Error writing to pipe.\n");
            close(in);
            close(out);
            exit(1);
        }
    }

    if (curr < 0) {
        printf("Error reading from pipe.\n");
        close(in);
        close(out);
        exit(1);
    }

    close(in);
    close(out);
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Wrong amount of arguments.\n");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf("Unable to open file.\n");
        exit(1);
    }

    char line[500];
    int line_index = 0;
    char character;

    int prev_pipe[2];
    int curr_pipe[2];

    while (read(fd, &character, 1) > 0) {
        if (character == '|') {
            line[line_index] = '\0';

            char *args[32];
            char *token = strtok(line, " ");
            int j = 0;

            while (token != NULL) {
                args[j++] = token;
                token = strtok(NULL, " ");
            }

            args[j] = NULL;
            
            int temp_pipe = pipe(curr_pipe);
            if (temp_pipe < 0) {
                printf("Unable to create pipe.\n");
                close(fd);
                exit(1);
            }

            int pid = fork();
            int in = STDIN_FILENO;
            int out = STDOUT_FILENO;

            if (pid < 0) {
                printf("Unable to fork.\n");
                close(fd);
                exit(1);

            } else if (pid == 0) {

                if (line_index > 0) {
                    int temp_dup2 = dup2(prev_pipe[0], in);
                    if (temp_dup2 < 0) {
                        printf("Unable to dup2.\n");
                        close(fd);
                        exit(1);
                    }
                    close(prev_pipe[0]);
                }

                int temp_curr_pipe = pipe(curr_pipe);
                if (temp_curr_pipe < 0) {
                    printf("Unable to create temp_curr_pipe.\n");
                    close(fd);
                    exit(1);
                }

                int temp_dump2 = dup2(curr_pipe[1], out);
                if (temp_dump2 < 0) {
                    printf("Unable to dup2.\n");
                    close(fd);
                    exit(1);
                }
    
                close(curr_pipe[0]); 

                pipe_funk(in, curr_pipe[0]);

                execvp(args[0], args);
                printf("Unable to exec(vp).\n");
                close(fd);
                exit(1);
            }

            if(line_index > 0){
                close(prev_pipe[0]);
                close(prev_pipe[1]);
            }

            prev_pipe[0] = curr_pipe[0];
            prev_pipe[1] = curr_pipe[1];
            line_index = 0;
            //printf("Prev Pipe: %d %d\n", prev_pipe[0], prev_pipe[1]);
            //printf("Curr Pipe: %d %d\n", curr_pipe[0], curr_pipe[1]);


        }else{
            line[line_index++] = character;
        }
    }

    //for the last read function
    if (line_index > 0) {
        line[line_index] = '\0';

        char *args[32];
        char *token = strtok(line, " ");
        int j = 0;

        while (token != NULL) {
            args[j++] = token;
            token = strtok(NULL, " ");
        }

        args[j] = NULL;
        int in = STDIN_FILENO;

        int temp_dup2 = dup2(prev_pipe[0], in);
        if(temp_dup2 < 0) {
            printf("Unable to dup2.\n");
            close(fd);
            exit(1);
        }

        close(prev_pipe[0]);
        close(prev_pipe[1]);

        execvp(args[0], args); 
        
        printf("Unable to exec(vp).\n");
        close(fd);
        exit(1);
    }

    close(fd);
    exit(0);
}