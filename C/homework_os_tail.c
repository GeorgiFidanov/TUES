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
		printf("File could not be opened - %s/\n", fileName);
		exit(1);
	}

	char chunk[16];
	int bytes_read;
	int new_lines_found = 0;
	while (sizeof(chunk) == (bytes_read = read(fd, chunk, sizeof(chunk)))){
		for (int i = 0; i< *chunk; i++) {
			if ( chunk[i] == '\n' ){
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

void print (char* fileName){

    int fd = open(fileName, O_RDONLY);
    if (-1 == fd){
        printf("File could not be opened - %s/\n", fileName);
        exit(1);
    }

    char buffer; 
    int i = 0;
    while(i != -1){
        i = read(fd, &buffer, 1);
        printf("%c",buffer);
        if(i == 0){
            break;
        }
    }
    close(fd);
    exit(0);
}

int main(int argc, char* argv[]){
    int equalizer = 0;
    int lines_limit = 10;
    char* fileName;
    if(argc == 1){
        printf("Expected more arguments.\n");
        exit(1);
    }
    if(strcmp(argv[1],"-n") ==0){
        
        if(argc < 4){
            printf("More arguments expected.\n");
            exit(1);
        }
        lines_limit = atoi(argv[2]);
        fileName = strdup(argv[3]); 
    }
    else{
        fileName = strdup(argv[1]);
    }  
    int lines_count = count_the_new_lines(fileName);
    equalizer = lines_count - lines_limit;
    if(equalizer < 0){
        printf("Not enough new lines in -: %s/\n", fileName);
        exit(1);
    }

    if(lines_count <= lines_limit){
        print(fileName);
        exit(0);
    }
    else{
        int fd = open(fileName, O_RDONLY);
        if (-1 == fd){
            printf("File could not be opened -: %s/\n", fileName);
            exit(1);
        }
        char buffer; 
        int i = 0;
        int line_counter = 0;
        while(i != -1){
            i = read(fd, &buffer, 1);
            if(equalizer <= line_counter){
                printf("%c", buffer);
                if(lines_count == line_counter){
                    if(buffer == EOF){
                        break;
                        exit(0);
                    }
                }
            }
            if(buffer == '\n'){
                line_counter +=1;
            }
            if(i == 0){
                break;
                exit(0);
            }
        }
        close(fd);
    }
    return 0;
};