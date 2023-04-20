#include <unistd.h>

// open:
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>

// printf:
#include<stdio.h>
// exit
#include<stdlib.h>

void read_line(char *fileName){
    char buffer;

    malloc(buffer * (sizeof(char)));

}

void wc(int command_line_argument, posiib 1, posiib 2){}
// Open the file
// Check if file exists
// Close the file
void head(int command_line_argument, posiib 1){
    // Open the file
    int f = open("pesho.txt", O_RDONLY);
    // Check if file exists
    if(f == -1){
        printf("\nerror while openingn");
    }
    char cache**;
    for(int i=1;; i++){
        int r = read(f, &cache, i);
        if(r == -1){
            printf("\nerror while reading");
        }
        if(r==1){
            printf("success reading");
        }
        if(r==0){
            printf("success");
        }
        
        if (cache == '\n'){
        count = count + 1;
        }
    }
    if(count => 10){
        //print 10
    }
    else(count < 10){
        //print all
    }
    close(f);
}

void print (char* fileName, int from){

    if(from => 1){
      // off_t lseek(fileName, from, );
    };
    else{
// Open the file
// Check if file exists
    char* fileName;
    int fd = open(fileName, O_RDONLY);
    if (-1 == fd){
		printf("File could not be opened :/\n");
		exit(1);
	}
    char cursor[];
    int i =1;
    while(cursor[] != EOF){
        cursor[] = write(fileName, i, 1);
    }
    }
}

int count_the_new_lines(char* fileName){
    int fd = open(fileName, O_RDONLY);
    	if (-1 == fd){
		printf("File could not be opened :/\n");
		exit(1);
	}

	char chunk[16];
	int bytes_read;
	int new_lines_found = 0;//                 s koi fail asociiarame fail, pamet za 16b i tuk razmer 26b
	while (sizeof(chunk) == (bytes_read = read(fd, chunk, sizeof(chunk)))) {
		for (int i = 0; i< chunk; i++) {
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
	// Parse the last chunk :)
	for (int i = 0; i < bytes_read; i++) {
		if ( chunk[i] == '\n' ) {
			new_lines_found += 1;
		}
	}
	//printf("New lines: %d\n", new_lines_found);
	close(fd);
	exit(0);
    return new_lines_found;
 }       
// Close the file
void tail(int command_line_argument, posiib 1){
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
int main(int argc, char * argv[]){
/*
    int f = open("pesho.txt", O_RDONLY);

    if(f == -1){
        printf("\nerror while openingn");
    }
    char cache[5];
    int r = read(f, &cache, 5);
    if(r == -1){
        printf("\nerror while reading\n");
    }
    if(r==1){
        printf("success");
    }
    if(r==0){
        printf("success");
    }
    printf("\n%c", cache);
    close(f);
    exit(1);*/
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

/*
char* fgets(char* s, int n, FILE *iop)
{
    register int c;
    register char* cs;
    cs = s;

    while(--n > 0 && (c = getc(iop)) != EOF)
    {
    // put the input char into the current pointer position, then increment it
    // if a newline entered, break
    if((*cs++ = c) == '\n')
        break;          
    }

    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}*/