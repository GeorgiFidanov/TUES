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
    }
    else{
        return 2;
    }
}

int main(int argc, char* argv[]){

    if(argc < 4){
        printf("Expected more arguments.\n");
        exit(1);
    }

    int fd_correct = open(argv[2], O_RDONLY);
    if(fd_correct < 0){
        printf("Unable to open file with answers.\n");
        exit(2);
    }
    char correct_answers[26];
   
    for(int i=1; i<26; i++){
        int temp_read = read(fd_correct, &correct_answers[i], 1);
        if(temp_read < 0){
            printf("Unable to read from file with answers.\n");
	    close(fd_correct);
            exit(2);
        }

        int temp_seek = lseek(fd_correct,1,SEEK_CUR);
        if(temp_seek < 0){
            printf("Unable to seek from file with answers.\n");
	    close(fd_correct);
            exit(2);
        }
    }
    close(fd_correct);

    for(int i=1; i<26; i++){
        char* buffer = malloc(strlen(argv[1]) + 3);
	if(buffer == NULL){
	    printf("Unable to malloc memory.\n");
	    exit(2);
	}
        int temp_sprintf = sprintf(buffer, "%s%d\0", argv[1], i);
	if(temp_sprintf < 0){
	    printf("Unable to print in buffer.\n");
	    free(buffer);
	    exit(2);
	}

        int fd_curr = open(buffer, O_RDONLY);
        if(fd_curr < 0){
            printf("Unable to open directory: '%s'\n", buffer);
	    free(buffer);
            exit(2);
        }

        char answer[26];
        int correct_answers_count = 0;
        for(int j=1; j<26; j++){
            int temp_read = read (fd_curr, &answer[j], 1);
            if(temp_read < 0){
                printf("Unable to read from file.\n");
		close(fd_curr);
		free(buffer);
                exit(2);
            }
            int temp_seek = lseek(fd_correct,1,SEEK_CUR);
            if(temp_seek < 0){
                printf("Unable to seek from file with answers.\n");
		close(fd_curr);
		free(buffer);
                exit(2);
            }

            if(answer[j] == correct_answers[j]){
                correct_answers_count++;
            }
        }
	free(buffer);
	close(fd_curr);

        if(correct_answers_count >= 0){
            char* buffer_inside = malloc(strlen(argv[3]) + 3);
            if(buffer_inside == NULL){
	        printf("Unable to malloc memory (inside).\n");
	        exit(2);
	    }
	    
	    int temp_inside_sprintf = sprintf(buffer_inside, "%s%d\0", argv[3], i);
	    if(temp_inside_sprintf < 0){
		printf("Unable to print in buffer_inside.\n");
		free(buffer_inside);
		exit(2);
	    }

            int grade = grading_system(correct_answers_count);
            char grade_buffer[3];
            int temp_grade_sprintf = sprintf(grade_buffer, "%d\0",grade);
	    if(temp_grade_sprintf < 0){
		printf("Unable to print grade inside grade_buffer.\n");
		free(buffer_inside);
		exit(2);
	    }

            int fd_graded = open(buffer_inside, O_WRONLY);
            if(fd_graded < 0){
                printf("Unable to open file with grade.\n");
                free(buffer_inside);
		exit(2);
            }
	    free(buffer_inside);

            int temp_write = write(fd_graded, grade_buffer , 1);
            if(temp_write < 0){
                printf("Unable to write grade.\n");
                close(fd_graded);
		exit(2);
            }            
            close(fd_graded);
        }
    }
 
    return 0;
};
