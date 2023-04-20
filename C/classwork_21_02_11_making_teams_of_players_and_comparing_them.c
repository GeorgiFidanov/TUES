#include <stdio.h>
#include <string.h>
#define ARR_SIZE = 20
#define PLAYER_FORMAT "elo:%d,ranking:%d,firstName:%s,lastName:s\n"
enum field {fKey = -1, fValue = 1};
enum boolean {false, true};

/**
 * Struct describing our players.
 */
struct player {
    int ranking;
    int elo;
    char firstName[255];
    char lastName[255];
};

/**
 * Function to parse string to int
 */
int toInt(char *value) {
    int result = 0;

    for (char *c = value; *c != '\0'; *c++) {
        result = (result * 10) + (*c -'0');
    }

    return result;
}

/**
 * Assigns value to the specified field of the passed player.
 * E.g. key == "elo", value == "2000" => p.elo becomes 2000
 */
void assignKeyValue(struct player *p, char *key, char *value) {
    if (!strcmp(key, "ranking")) {
        p->ranking = toInt(value);
    } else if (!strcmp(key, "elo")) {
        p->elo = toInt(value);
    } else if (!strcmp(key, "firstName")) {
        strcpy(p->firstName, value);
    } else if (!strcmp(key, "lastName")) {
        strcpy(p->lastName, value);
    } else {
        printf("Error: Wrong key: %s", key);
    }
}

/**
 * Parses a line representing a player to a passed player struct.
 */
void parseLine(struct player *p, char *line) {
    char key[255] = "";
    char value[255] = "";
    int counter = 0;

    // Points to the string that we currently write data into.
    char *curr = key;
    enum field f = fKey;

    for (char *c = line; *c != '\0'; *c++) {
        if (*c == ':' || *c == ',' || *c == '\n') {
            // When we have encountered any of the symbols that split key from value
            // the string that data is written into is closed with a '\0', and the
            // reference is changed to the other string.
            f *= -1;
            curr[counter] = '\0';

            if (f == fKey) {
                curr = key;
                assignKeyValue(p, key, value);
            } else {
                curr = value;
            }

            counter = 0;
        } else {
            curr[counter++] = *c;
        }
    }
}

/**
 * Parses a whole file by name into a passed array of player structs.
 */
void parseFile(struct player *target, int size, char *fileName) {
    FILE *f = fopen(fileName, "r");

    if (!f) {
        printf("Error opening file!");
    }

    char buffer[255];

    for (int i = 0; i < size; i++) {
        if (!fgets(buffer, 255, f)) {
            break;
        }

        struct player p = {};

        parseLine(&p, buffer);

        target[i] = p;
    }

    fclose(f);
}

void swap (struct player *p1, struct player *p2) {
    struct player temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort(struct player *players, int size) {
    enum boolean sorted = true;
    for (int i = 0; i < size; i++) {
        if (&players[i] == NULL) {
            break;
        }
        for (int j = i; j < size; j++) {
            if (&players[j] == NULL) {
                break;
            }
            if (players[i].ranking > players[j].ranking) {
                sorted = false;
                swap(&players[i], &players[j]);
            }
        }

        if (sorted) {
            break;
        }

        sorted = true;
    }
}

enum boolean equal(struct player *p1, struct player *p2) {
    if (p1->elo != p2->elo) {
        return false;
    }

    if (p1->ranking != p2->ranking) {
        return false;
    }

    if (strcmp(p1->firstName, p2->firstName)) {
        return false;
    }

    if (strcmp(p1->firstName, p2->firstName)) {
        return false;
    }

    return true;
}

/**
 * Compares if the data written in two files is exactly the same.
 * The flow is as follows:
 * 1. Parse the two files to arrays of player structs
 * 2. Sort the two arrays.
 * 3. Compare each element from one array with the corresponding element from the other.
 */
enum boolean cmp (struct player, char *newFile) {


    for (int i = 0; i < 20; i++) {
        struct player *p1 = &oldPlayers[i];
        struct player *p2 = &newPlayers[i];

        // If both players are null and the arrays are sorted this means
        // there are no differences in the file.
        if (p1 == NULL && p2 == NULL) {
            return true;
        }

        // If both players are not null but one of them is and the file is sorted
        // then clearly there is data mismatch.
        if (p1 == NULL || p2 == NULL) {
            return false;
        }

        if (!equal(p1, p2)) {
            return false;
        }
    }

    return true;
}
void saveToFile(struct player *newPlayers, int size, char *fileName){
    FILE *f = fopen(fileName, "w");
    for (int i = 0; i<size; i++){
        struct player *p = &newPlayers[i];
        fprintf(f, PLAYER_FORMAT, p->elo, i + 1, p->firstName, p->lastName);
    }
    fclose(f);
}


}
int main()
    struct player oldPlayers[ARR_SIZE];
    struct player newPlayers[ARR_SIZE];
    parseFile(oldPlayers, ARR_SIZE, "players.txt");
    parseFile(newPlayers, ARR_SIZE, "players_scrambled.txt");

    sort(oldPlayers, ARR_SIZE);
    sort(newPlayers, ARR_SIZE);
{
    enum boolean equal = cmp("players.txt", "players_scrambled.txt");


    if (equal) {
        printf("Player lists are equal!");
    } else {
        printf("Player lists are not equal! Update player data!");
    }
    return 0;
}
