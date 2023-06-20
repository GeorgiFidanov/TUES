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
      //  printf("%d\n",prev_pipe[0]);
void pipe_funk(){}

int main(int argc, char *argv[]){

    if(argc > 2){
        printf("Too many arguments.\n");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        printf("Unable to open file.\n");
        exit(2);
    }

    char line[500];
    int line_index = 0;
    char character;

    while( read(fd, &character, 1) > 0){
        if(character == '|'){

          //  line[line_index] = '\0';
            char *args[32];
            char *token = strtok(line, " ");
            int j=0;

            while(token != NULL){
                args[j++] = token;
                token = strtok(NULL, " ");
            }

            args[j] = NULL;
            int pid = fork();

            if(pid < 0){
                printf("Unable to fork.\n");
                close(fd);
                exit(2);
            }
            else if(pid == 0){
                execvp(args[0], args);
                printf("Unable to exec(vp).\n");
                close(fd);
                exit(2);
            }

            int status = 0;
            int temp_wait = wait(&status);
            if(temp_wait < 0){
                printf("Unable to wait.\n");
                close(fd);
                exit(2);
            }
             
            
            if(WIFEXITED(status)){
                printf("\nCommand '%s' exited with status %d\n\n", args[0], WEXITSTATUS(status));
            }else{
                printf("Command '%s' terminated abnormally\n", args[0]);
            }
            //clear the line(var) so it can be overridden
            memset(line, 0, sizeof(line));
            line_index = 0;

        }else if(character == '\0'){
            pipe_funk();

        }
        
        else{
            line[line_index++] = character;
        }
    }

    if(read(fd, &character, 1) < 0){
        printf("Unable to read.\n");
        close(fd);
        exit(2);
    }
    
    close(fd);
    return 0;
}














int prev_pipe[2] = {-1, -1};

for (int i = 0; i < num_cmds; i++) {
    int curr_pipe[2];
    if (pipe(curr_pipe) < 0) {
        printf("Unable to create pipe.\n");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) { // child process
        // connect input to previous pipe
        if (prev_pipe[0] >= 0) {
            dup2(prev_pipe[0], STDIN_FILENO);
            close(prev_pipe[0]);
            close(prev_pipe[1]);
        }

        // connect output to current pipe
        dup2(curr_pipe[1], STDOUT_FILENO);
        close(curr_pipe[0]);
        close(curr_pipe[1]);

        // execute the command
        execvp(cmds[i][0], cmds[i]);

        // handle execvp error
        printf("Unable to execvp.\n");
        exit(1);
    } else if (pid < 0) { // fork error
        printf("Unable to fork.\n");
        exit(1);
    }

    // close previous pipe
    if (prev_pipe[0] >= 0) {
        close(prev_pipe[0]);
        close(prev_pipe[1]);
    }

    // save current pipe as previous pipe
    prev_pipe[0] = curr_pipe[0];
    prev_pipe[1] = curr_pipe[1];
}

// close last pipe
if (prev_pipe[0] >= 0) {
    close(prev_pipe[0]);
    close(prev_pipe[1]);
}

// wait for child processes to finish
while (wait(NULL) > 0);
