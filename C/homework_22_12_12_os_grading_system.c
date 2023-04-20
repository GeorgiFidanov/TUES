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

int grading_system(int correct_answers){
    if(correct_answers > 12){
        if(correct_answers > 15){
            if(correct_answers > 18){
                if(correct_answers > 21){
                    return 6;
                }
                else{
                    return 5;
                }
            }
            else{
                return 4;
            }
        }
        else{
            return 3;
        }
    }else{
        return 2;
    }
}

int main(int argc, char* argv[]){

    char* fileName;
    if(argc == 1){
        printf("Expected more arguments.\n");
        exit(1);
    }

    int fd_correct = open(argv[2], O_RDONLY);
    if(fd_correct < 0){
        printf("Unable open file with answers.\n");
        return -1;
    }
    char correct_answers[25];
   
    for(int i=1; i<26; i++){
        int temp_read = read(fd_correct, &correct_answers[i], 1);
        if(temp_read < 0){
            printf("Unable read from file with answers.\n");
            return -1;
        }

        int temp_seek = lseek(fd_correct, 1,SEEK_CUR);
        if(temp_seek < 0){
            printf("Unable seek from file with answers.\n");
            return -1;
        }
    }
    close(fd_correct);
    for(int i=0; i<25; i++){
        char* buffer = malloc(strlen(argv[1]) + 3);
        sprintf(buffer, "%s%d'\0'", argv[1], i);
        int fd_curr = open(buffer, O_RDONLY);
        if(fd_curr < 0){
            printf("Unable to open directory '%s'\n", buffer);
            return -1;
        }

        char answer[25];
        int correct_answers_count = 0;
        for(int j=1; j<26; j++){
            int temp_read = read (fd_curr, &answer[j], 1);
            if(temp_read < 0){
                printf("Unable to read from file\n");
                return -1;
            }

            if(answer[j] == correct_answers[j]){
                correct_answers_count++;
            }
        }

        while(correct_answers_count >= 0){
            char* buffer_inside = malloc(strlen(argv[3]) + 3);
            sprintf(buffer_inside, "%s%d'\0'", argv[3], i);
            int fd_graded = open(buffer, O_WRONLY);
            if(fd_graded < 0){
                printf("Unable to open file with grade.\n");
                return -1;
            }

            int grade = grading_system(correct_answers_count);
            int temp_write = write(fd_graded, buffer_inside, grade);
            if(temp_write < 0){
                printf("Unable to write grade.\n");
                return -1;
            }

            free(buffer_inside);
            close(fd_graded);
        }
        
        free(buffer);
        close(fd_curr);
    }
 
    return 0;
};
