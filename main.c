#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "inputChecker.h"

int schritteGesamt;
int umdrehungen;

int main() {
	schritteGesamt = 0;
	umdrehungen = 0;
	bool stuhlErreicht = false;
	char userInput[10];

	while (!stuhlErreicht) {
		int schritteInDurchgang = 0;
		int validInput = 1;
		do {
			if (!validInput) {
				printf("UNZULAESSIGER INPUT!!!\n");
			}
			printf("\nLiegt der Stuhl auf dem Weg?\n");
			printf("y/n: ");
			scanf("%s", userInput);

			firstLetterYOrN(userInput, &validInput);
		} while (!validInput);

		do {
			if (!validInput) {
				printf("UNZULAESSIGER INPUT!!!\n");
				printf("Bitte gib eine positive Ganzzahl an!\n");
			}

			if (userInput[0] == 'y') {
				printf("\nWie viele Schritte bis zum Stuhl?\n");
			}
			else {
				printf("\nWie viele Schritte bis zur Wand?\n");
			}
			printf("Eingabe: ");
			scanf("%s", userInput);
			CheckStringToUInt(userInput, &validInput);
		} while (!validInput);
		//atoi = ASCII to integer
		schritteInDurchgang = atoi(userInput);

		schritteGesamt += schritteInDurchgang;

		int j = 1 + schritteGesamt - schritteInDurchgang;
		while (j <= schritteGesamt) {
			printf("%d. Schritt\n", j);
			j++;
		}

		if (userInput[0] == 'y') {
			stuhlErreicht = true;
			printf("STUHL ERREICHT \\(^.^)/\n");
		}
		else {
			umdrehungen++;
			printf("Wand erreicht\n");
			printf("%d. Linksdrehung\n", umdrehungen);
		}
	}

	printf("Anzahl Umdrehungen: %d\n", umdrehungen);
	printf("Anzahl Schritte: %d\n", schritteGesamt);

	return 0;
}
