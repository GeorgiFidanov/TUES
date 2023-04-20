//exit, read, write, close
#include <unistd.h>
// open:
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
// printf:
#include<stdio.h>
//c without strings is a nightmare
#include<string.h>
// exit
#include<stdlib.h>
//wait
#include <sys/wait.h>

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

    char line[256];
    int line_index = 0;
    char character;

    while( read(fd, &character, 1) > 0){
        if(character == '\n'){

            line[line_index] = '\0';
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

        }else{
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