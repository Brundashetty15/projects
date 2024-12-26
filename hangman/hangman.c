#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool checkIfCharPresentInPuzzleWord(char guessedChar, char puzzleWord[]) {
	int sizeOfPuzzleWord = strlen(puzzleWord);
	int i;
	for (i = 0 ; i < sizeOfPuzzleWord ; i++) {
		if (puzzleWord[i] == guessedChar) {
			return 1;
		}
	}
		
	return 0;
}

bool isCharGuessedAlready(char guessedChar, char* guessedWord) {
	int sizeOfGuessedWord = strlen(guessedWord);
	int i;
	for (i = 0 ; i < sizeOfGuessedWord ; i++) {
		if (guessedWord[i] == guessedChar) {
			return 1;
		}
	}
		
	return 0;
}

bool checkGuesserIsWon(char guessedWord[], char puzzleWord[]) {
	int sizeOfPuzzleWord = strlen(puzzleWord), i;
	for (i = 0 ; i < sizeOfPuzzleWord ; i++) {
		if (guessedWord[i] != puzzleWord[i]) {
			return 0;
		}
	}
	
	return 1;
}

void updateGuessedWord(char guessedChar, char *guessedWord, char *puzzleWord) {
	int sizeOfPuzzleWord = strlen(puzzleWord), i;
	for (i = 0 ; i < sizeOfPuzzleWord ; i++) {
		if(puzzleWord[i] == guessedChar) {
			guessedWord[i] = guessedChar;
		}
	}
}

void showHangMan(int attempts) {
	switch (attempts) {
        case 0:
            printf("  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n");
            break;
        case 1:
            printf("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n");
            break;
        case 2:
            printf("  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n");
            break;
        case 3:
            printf("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n");
            break;
        case 4:
            printf("  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n");
            break;
        case 5:
            printf("  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n");
            break;
        case 6:
            printf("  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n");
            break;
    }
}



void startGame() 
{
	//varibales declaration
	char puzzleHolderName[30], puzzleGuesserName[30], puzzleWord[30], guessedWord[30];
	int noOfWrongAttemptsAllowed = 6, noOfWrongAttemptsMade = 0;
	
	// take the players input
	printf("Enter the Puzzle Holder's Name : \n");
	scanf("%s", puzzleHolderName);
	printf("Enter the Puzzle word\n");
	scanf("%s", puzzleWord);
	
	// clears the screen since the puzzle word must not be visible to puzzle guesser
	system("cls");	
	
	// prepare the guessed word
	int sizeOfPuzzleWord = strlen(puzzleWord), i;
	for(i = 0 ; i < sizeOfPuzzleWord ; i++) {
		guessedWord[i] = '_';
	}
	guessedWord[sizeOfPuzzleWord] = '\0';
	
	printf("Enter the Puzzle Guesser's Name : \n");
	scanf("%s", puzzleGuesserName);	
	
	showHangMan(noOfWrongAttemptsMade);
	
	while(noOfWrongAttemptsMade < noOfWrongAttemptsAllowed) {
		printf("\nThe Guessed word is %s", guessedWord);
		char guessedChar;
		printf("\n\nplease enter your guessed letter : ");
		scanf(" %c", &guessedChar);
		// check if this guessed char is already guessed or not
		if(isCharGuessedAlready(guessedChar, guessedWord)) {
			printf("\n\n Enter the char that is not guessed before\n");	
			continue;
		}
		// check for char is present in the puzzle word
		if(checkIfCharPresentInPuzzleWord(guessedChar, puzzleWord)) {
			updateGuessedWord(guessedChar, guessedWord, puzzleWord);
			if(checkGuesserIsWon(guessedWord, puzzleWord)) {
				printf("\nThe Puzzle guesser %s has won the game Congratulations!", puzzleGuesserName);
				exit(0);
			}
			
		} else {
			printf("\nThe guessed char %c is not present\n\n", guessedChar);
			noOfWrongAttemptsMade++;
			showHangMan(noOfWrongAttemptsMade);
			printf("\n");
		}
	}
	
	printf ("\n\nPuzzle holder %s has won the game Congratulations!", puzzleHolderName);
}


int main() 
{
	startGame();
}
	

