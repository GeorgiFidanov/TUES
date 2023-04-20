#include <unistd.h>
// open:
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
// printf:
#include<stdio.h>
// exit
#include<stdlib.h>
// name of file
#define FILE_NAME "pomosht.txt"

int count_the_new_lines(char* fileName){
    int fd = open(fileName, O_RDONLY);
    	if (-1 == fd){
		printf("File could not be opened :/\n");
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

void print (char* fileName){

    int fd = open(fileName, O_RDONLY);
    if (-1 == fd){
        printf("File could not be opened :/\n");
        exit(1);
    }

    char cursor; 
    int i = 0;
    while(i != -1){
        i = read(fd, &cursor, 1);
        printf("%c",cursor);
        if(i == 0){
            break;
        }
    }
    close(fd);
    exit(0);
}

int main(int argc, char * argv[]){
    int default_num = 10;
    if (*argv[2] == 'n'){
        if(argv[3] != NULL){
            default_num == *argv[3];
        }
    }
   
    int a = count_the_new_lines(FILE_NAME);
    if(a <= default_num){
        print(FILE_NAME);
        exit(0);
    }
    else{
        int fd = open(FILE_NAME, O_RDONLY);
        if (-1 == fd){
            printf("File could not be opened :/\n");
            exit(1);
        }

        char cursor; 
        int i = 0;
        int new_lines_limiter = 0;
        while(i != -1){
            i = read(fd, &cursor, 1);
            printf("%c",cursor);
            if(cursor == '\n'){
                new_lines_limiter +=1 ;
                if(new_lines_limiter == 10){
                    break;
                    exit(0);
                }
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
/*void tail(int command_line_argument, posiib 1){
// Open the file
// Check if file exists
    char* fileName;
    int fd = open(fileName, O_RDONLY);
    if (-1 == fd){
		printf("File could not be opened :/\n");
		exit(1);
	}
    int equalizer = 0;
    int count_of_new_lines  = count_the_new_lines(fileName);
    if(count_of_new_lines > 10){
        equalizer = count_of_new_lines - 10;
        //print s delay equalizer
    }
    else(count < 10){
    //print all
    }
// Close the file
}
 int file_descriptor = open("first_file", O_RDONLY);
	if ( -1 == file_descriptor ) {
		printf("Unable to open first_file");
		exit(1);
	}

	char symbol;
	int read_status = read(file_descriptor, &symbol, 1);
	if ( -1 == read_status) {
		printf("Read failed!");
		close(file_descriptor);
		exit(2);
	}
	if ( 0 == read_status ) {
		printf("Read was unable to read a byte from the file");
		close(file_descriptor);
		exit(3);
	}
	if ( 1 != read_status) {
		printf("We will never get here :)");
		exit(4);
	}

	// 1 = STDOUT.
	printf("Procheteniqt simvol e:\n");
	int write_status = write(1, &symbol, 1);
	printf("\n");
	if ( -1 == write_status ) {
		printf("Write failed!");
		exit(5);
	}
	if ( 0 == write_status ) {
		printf("Write could not wrtie to stdout");
		exit(6);
	}
	if ( 1 != write_status ) {
		printf("We will never get here :)");
		exit(7);
	}
	
	//NB! Release the dynamically allocated resources we no longer need.
	close(file_descriptor);
	exit(0);
}
*/

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

void print (char* fileName){

    int fd = open(fileName, O_RDONLY);
    if (-1 == fd){
        printf("File could not be opened - %s/\n", fileName);
        exit(1);
    }

    char cursor; 
    int i = 0;
    while(i != -1){
        i = read(fd, &cursor, 1);
        printf("%c",cursor);
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
    printf("lines_count is:%d\n", lines_count);
    equalizer = lines_count - lines_limit;
    printf("equalizer is:%d\n", equalizer);

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
         //   printf("her 1\n");
            i = read(fd, &buffer, 1);
                if(equalizer <= line_counter){
                    printf("%c", buffer);
                    printf("her 1\n");
                    if(lines_count == line_counter){
                         printf("her 4\n");
                        if(buffer == EOF){
                             printf("her 5\n");
                            break;
                            exit(0);
                        }
                    }
                }
                if(buffer == '\n'){
                    line_counter +=1;
                    printf("her %d\n", i);
                }
                if(i == 0){
                    printf("her 3\n");
                    break;
                    exit(0);
                }
            }
        close(fd);
        }
    return 0;
};