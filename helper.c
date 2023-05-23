#include <stdio.h>
#include <stdbool.h>

void checkIfJaNein(bool*);

extern char input[];

int mode;

void getStuhlInput() {
	bool validInput = true;
	do {
		if (!validInput) {
			printf("UNZULAESSIGER INPUT!!!\n");
			printf("Das erste Zeichen muss ein 'y' 'j' oder 'n' sein (case insensitive)");
		}

		printf("\nLiegt der Stuhl auf dem Weg?\n");
		printf("y/n: ");
		scanf("%s", input);

		checkIfJaNein(&validInput);
	} while(!validInput);
}

void getAnzahlSchritte() {
	bool validInput = true;
	do {
		if (!validInput) {
				printf("UNZULAESSIGER INPUT!!!\n");
				printf("Bitte gib eine positive Ganzzahl an!\n");
		}
		switch(mode) {
			case 1:
				printf("\nWie viele Schritte bis zum Stuhl?\n");
				break;
			case 2:
				printf("\nWie viele Schritte bis zur Wand?\n");
				break;
			default:
				printf("\n Ein Fehler ist aufgetreten! Bitte beende das Programm!");
				return;
		}
		printf("Eingabe: ");
		scanf("%s", input);

		int i;
		for (i = 0; i < sizeof(input); ++i) {
			if (!isdigit(input[i])) {
				if (!(input[i] == '\0' && i > 0)) {
					validInput = false;
					break;
				}
				validInput = true;
				break;
			}
		}
	} while (!validInput);
}

void printSchritte(int j, int schritteGesamt, int umdrehungen, bool* stuhlErreicht) {
	while (j <= schritteGesamt) {
			printf("%d. Schritt\n", j);
			j++;
	}
	
	switch(mode) {
		case 1:
			*stuhlErreicht = true;
			printf("STUHL ERREICHT \\(^.^)/\n");
			break;
		case 2:
			umdrehungen++;
			*stuhlErreicht = false;
			printf("Wand erreicht\n");
			printf("%d. Linksdrehung\n", umdrehungen);
			break;
		default:
			printf("\n Ein Fehler ist aufgetreten! Bitte beende das Programm!");
			return;
	}
}

void checkIfJaNein(bool* isValid) {
	switch (input[0]) {
		case 'y':
		case 'Y':
		case 'j':
		case 'J':
			mode = 1;
			*isValid = true;
			break;
		case 'n':
		case 'N':
			mode = 2;
			*isValid = true;
			break;
		default:
			mode = 0;
			*isValid = false;
			break;
	}
}
