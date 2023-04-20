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

int count_the_new_lines(char* fileName){
    int fd = open(fileName, O_RDONLY);
    	if (-1 == fd){
		printf("File could not be opened while searching for new lines- %s/\n", fileName);
		exit(1);
	}

	char chunk[16];
	int bytes_read;
	int new_lines_found = 0;
	while (sizeof(chunk) == (bytes_read = read(fd, chunk, sizeof(chunk)))) {
		for (int i = 0; i< *chunk; i++) {
			if ( chunk[i] == '\n' ) {
				new_lines_found += 1;
			}
		}
	}
	if (-1 == bytes_read){
		printf("Error while reading\n");
		close(fd);
		exit(1);
	}
	// Parse the last chunk :) този коментар е оставен с цел показване откъде е черпена креативност
	for (int i = 0; i < bytes_read; i++) {
		if ( chunk[i] == '\n' ) {
			new_lines_found += 1;
		}
		if ( chunk[i] == EOF ) {
			exit(0);
		}
	}
	close(fd);
    return new_lines_found;
}

int count_of_bytes(char* fileName){
    int fd = open(fileName, O_RDONLY);
    if (-1 == fd){
        printf("File could not be opened while checking for bytes- %s/\n", fileName);
        exit(1);
    }

    char buffer;
    int count = 0; 
    int i = 0;
    while(i != -1){
        i = read(fd, &buffer, 1);
        count++;
        if(i == 0){
            break;
        }
    }
    close(fd);
    return count;
}

int main(int argc, char* argv[]){
    char* fileName;
    int new_lines = 0;
    int bytes = 0;
    if(argc == 1){
        printf("Expected more arguments.\n");
        exit(1);
    }
    if((strcmp(argv[1],"-l") ==0) ||( strcmp(argv[1],"-c") ==0 )){
        if((strcmp(argv[2],"-l") ==0) ||( strcmp(argv[2],"-c") ==0 )){
            if(strcmp(argv[1], argv[2])==0){
                printf("Two arguments can't be the same!\n");
                exit(1);
            }
            if(argv[3]==0){
                printf("Missing argument!\n");
                exit(1);
            }
            else if((strcmp(argv[3],"-l") ==0) ||( strcmp(argv[3],"-c") ==0 )){
                printf("Wrong use of arguments!\n");
                exit(1);
            }
            else{
                fileName = strdup(argv[3]);
                new_lines = count_the_new_lines(fileName);
                bytes = count_of_bytes(fileName);
                printf("The count of new lines is:%d\n", new_lines);
                printf("The count of all bytes is:%d\n", bytes);
                exit(0);
            }
        }
        else if(argv[2]==0){
            printf("Missing argument!\n");
            exit(1);
        }
        else{
            fileName = strdup(argv[2]);
            if(strcmp(argv[1],"-l") ==0){
                new_lines = count_the_new_lines(fileName);
                printf("The count of new lines is:%d\n", new_lines);
                exit(0);
            }
            else{
                bytes = count_of_bytes(fileName);
                printf("The count of all bytes is:%d\n", bytes);
                exit(0);
            }
        }
    }
    else{
        fileName = strdup(argv[1]); 
        new_lines = count_the_new_lines(fileName);
        bytes = count_of_bytes(fileName);
        printf("The count of new lines is:%d\n", new_lines);
        printf("The count of all bytes is:%d\n", bytes);
        exit(0);
    }
    //хванати са грубо 13 случая
    return 0;
};