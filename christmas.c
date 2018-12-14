#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int lastWasSpecial = 0;

int getSymbols(int line) {
    return (line * 2) +1;
}

char getChar(int line) {
    int random = rand() % 100;
    if(line == 0) {
        if(random <= 50) {
            return '*';
        } else {
            return 'X';
        }
    }
    if (lastWasSpecial) {
        lastWasSpecial = 0;
        return '^';
    } else {
        if (random<= 40) {
            lastWasSpecial = 1;
            return 'o';
        } else {
            lastWasSpecial = 0;
            return '^';
        }
    }
}

void printTree() {

    char symbol;
    int maxNumberOfChars = getSymbols(SIZE);

    for(int line = 0; line <= SIZE; line++) {
        int numberOfSymbols = getSymbols(line);
        int numberOfWhiteSpaces = (maxNumberOfChars - numberOfSymbols) / 2;

        for (int i = 1; i <= maxNumberOfChars; i++) {
            if(i == numberOfWhiteSpaces + 1 || i == numberOfWhiteSpaces + numberOfSymbols) {
                if(line == 0) {
                    printf("*");
                } else {
                    printf("%c", '^');
                }
            } else if (i > numberOfWhiteSpaces && i <= numberOfWhiteSpaces + numberOfSymbols) {
                char symbol = getChar(line);
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(int j = 0; j <= (maxNumberOfChars/2)-2; j++) {
        printf(" ");
    }
    printf("| |");
    for(int k = 0; k <= maxNumberOfChars/2; k++) {
        printf(" ");
    }


}

int main() {
    srand(time(NULL));
    printTree();
    return 0;
}
