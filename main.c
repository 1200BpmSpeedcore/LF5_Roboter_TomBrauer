#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
	int schritteGesamt = 0;
	int umdrehungen = 0;
	bool stuhlErreicht = false;
	char stuhl[2];
	char schritteInput[10];

	while (!stuhlErreicht) {
		int schritteInDurchgang = 0;
		bool trashInput = false;
		do {
			if (trashInput) {
				printf("UNZULAESSIGER INPUT!!!\n");
			}
			printf("\nLiegt der Stuhl auf dem Weg?\n");
			printf("y/n: ");
			scanf("%s", stuhl);

			stuhl[0] = tolower(stuhl[0]);
			if (stuhl[0] == 'y' || stuhl[0] == 'n') {
				trashInput = false;
			}
			else {
				trashInput = true;
			}
		} while (trashInput);

		do {
			if (trashInput) {
				printf("UNZULAESSIGER INPUT!!!\n");
				printf("Bitte gib eine positive Ganzzahl an!\n");
			}

			if (stuhl[0] == 'y') {
				printf("\nWie viele Schritte bis zum Stuhl?\n");
			}
			else {
				printf("\nWie viele Schritte bis zur Wand?\n");
			}
			printf("Eingabe: ");
			scanf("%s", schritteInput);
			trashInput = false;
			int i;
			for (i = 0; i < sizeof(schritteInput); ++i) {
				if (!isdigit(schritteInput[i])) {
					if (!(schritteInput[i] == '\0' && i > 0)) {
						trashInput = true;
					}
					break;
				}
			}
		} while (trashInput);
		//atoi = ASCII to integer
		schritteInDurchgang = atoi(schritteInput);

		schritteGesamt += schritteInDurchgang;

		int j = 1 + schritteGesamt - schritteInDurchgang;
		while (j <= schritteGesamt) {
			printf("%d. Schritt\n", j);
			j++;
		}

		if (stuhl[0] == 'y') {
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