#include <stdio.h>

#define DECK_SIZE 52
#define MAX_POINTS 3

enum cardSuit {Clubs, Diamonds, Hearts, Spades};
enum cardFace {Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
enum boolean {false, true};

struct card {
    enum cardSuit suit;
    enum cardFace face;
};

void printCard(struct card *c) {
    switch (c->face) {
        case Two:
        case Three:
        case Four:
        case Five:
        case Six:
        case Seven:
        case Eight:
        case Nine:
        case Ten:
            printf("%d", c->face);
            break;
        case Jack:
            printf("Jack");
            break;
        case Queen:
            printf("Queen");
            break;
        case King:
            printf("King");
            break;
        case Ace:
            printf("Ace");
            break;
    }

    switch(c->suit) {
        case Diamonds:
            printf(" of Diamonds.");
            break;
        case Hearts:
            printf(" of Hearts.");
            break;
        case Clubs:
            printf(" of Clubs.");
            break;
        case Spades:
            printf(" of Spades.");
            break;
    }

    printf("\n");
}

enum boolean isStronger(struct card *c1, struct card *c2) {
    if (c1->suit > c2->suit) {
        return true;
    }

    if (c1->suit < c2->suit) {
        return false;
    }

    if (c1->face > c2->face) {
        return true;
    }

    return false;
}
void print(struct card *deck){
    for(int i = 0; i<DECK_SIZE; i++){
        printCard(&deck[i]);
    }
}
void swap(struct card *card1, struct card *card2){
    struct card temp = {card1->suit, card1->face};
    *card1 = *card2;
    *card2 = temp;
}
void shuffle(struct card *deck, int rounds){
    for(int i = 0; i < rounds; i++){
        for(int j = 0; j<DECK_SIZE; j++){
            swap(&deck[j], &deck[rand() % 52]);
        }
    }
}
int main()
{
    struct card deck[DECK_SIZE];
    int deckSize = 0;

    time_t t;
    srand((unsigned) time(&t));

    for (enum cardSuit suit = Clubs; suit <= Spades; suit++) {
        for (enum cardFace face = Two; face <= Ace; face++) {
            struct card c = {suit, face};
            deck[deckSize++] = c;
        }
    }
    shuffle(deck, 7);
    print(deck);
    return 0;
}
