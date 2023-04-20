#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
  char position[255];
  char firstName[255];
  char lastName[255];
  int height;
};

void put_team (struct person *p, FILE *f){
    fscanf(f, " <person>");
    for(int i = 0; i < 4; ++i){
      char key[255], value[255];
      fscanf(f, " <%[^>]>%[^<]<%*[^>]>", key, value);
      if(!strcmp(key, "position")){
        strcpy(p->position, value);
      }else if(!strcmp(key, "firstName")){
        strcpy(p->firstName, value);
      }else if(!strcmp(key, "lastName")){
        strcpy(p->lastName, value);
      }else if(!strcmp(key, "height")){
        p->height = atoi(value);
      }
  }
  fscanf(f, " </person>");
}
void swap(struct person *p1, struct person *p2){
    struct person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void sort(struct person *players, int size) {
    for (int i = 3; i <= size; i++) {
        for (int j = i; j < size; j++) {
            if (players[i].height < players[j].height) {
                swap(&players[i], &players[j]);
            }
        }
    }
}

void printTeam(struct person *team){
  int j = 0;
  int s = 0;
  int y = 0;
  int counter = 4;
  for(; j < 17; j++){
    if(!strcmp(team[j].position,"coach")){
      printf("1) %s, %s, %s, %d\n", team[j].position, team[j].firstName, team[j].lastName, team[j].height);
      break;
    }
  }
  for(; s < 17; s++){
    if(!strcmp(team[s].position, "assistant coach")){
      printf("2) %s, %s, %s, %d\n", team[s].position, team[s].firstName, team[s].lastName, team[s].height);
      break;
    }
  }
  for(; y < 17; y++){
    if(!strcmp(team[y].position, "doctor")){
      printf("3) %s, %s, %s, %d\n", team[y].position, team[y].firstName, team[y].lastName, team[y].height);
      break;
    }
  }  
  swap(&team[0], &team[j]);
  swap(&team[1], &team[s]);
  swap(&team[2], &team[y]);
  sort(team, 17);
  for(int i = 3; i < 17 ; i++){
      printf("%d) %s, %s, %s, %d\n", counter, team[i].position, team[i].firstName, team[i].lastName, team[i].height);
      counter++;
  }
}

void change(char* fileName, struct person *p){
  FILE *f = fopen(fileName, "w");
  for(int i = 0; i < 17; i++){
    fprintf(f, "<person>\n");
    fprintf(f, "<position>%s</position>\n", p[i].position);
    fprintf(f, "<firstName>%s</firstName>\n", p[i].firstName);
    fprintf(f, "<lastName>%s</lastName>\n", p[i].lastName);
    fprintf(f, "<height>%d</height>\n", p[i].height);
    fprintf(f, "</person>\n");
  }
  fclose(f);
}

int main(void) {
  //First exercise
  printf("Enter file name: ");
  char fileName[255];
  scanf("%s", fileName);

  FILE *f = fopen(fileName, "r");
  struct person team [17];

  for(int counter = 0; counter < 17; counter++){
    put_team(&team[counter], f);
  }
  printTeam(team);

  fclose(f);
  //Second exercise
  char letter;
  int number;
  char firstName[255];
  char lastName[255];
  int height;
  printf("Enter letter r for replace or q for quit: ");
  while(1){
    scanf("%c", &letter);
    if(letter == 'r'){
      printf("Enter number: ");
      scanf("%d", &number);
      printf("Enter first name: ");
      scanf("%s", firstName);
      printf("Enter last name: ");
      scanf("%s", lastName);
      printf("Enter height: ");
      scanf("%d", &height);


      strcpy(team[number-1].firstName, firstName);
      strcpy(team[number-1].lastName, lastName);
      team[number-1].height = height;
      change(fileName, team);
      printf("\nNew file look:\n");
      printTeam(team);
      break;

      }else if(letter == 'q'){
      exit(-1);
      break;
    }
    }
  }
  