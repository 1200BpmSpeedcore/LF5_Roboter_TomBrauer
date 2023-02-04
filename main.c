#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define AE (char)142

int main() {
	int schritteGesamt = 0;
	int umdrehungen = 0;
	bool trashInput = false;

	char stuhl[2];
	int schritteInput;

	while (true) {
		do {
			if (trashInput) {
				printf("UNZUL%cSSIGER INPUT!!!\n", AE);
			}
			printf("Liegt der Stuhl auf dem Weg?\n");
			printf("y/n: ");
			scanf_s("%s", stuhl);

			stuhl[0] = tolower(stuhl[0]);
			if (stuhl[0] == 'y' || stuhl[0] == 'n') {
				trashInput = false;
			}
			else {
				trashInput = true;
			}
		} while (trashInput);

		if (stuhl[0] == 'n') {
			do {
				if (trashInput) {
					printf("UNZUL%cSSIGER INPUT!!!\n", AE);
				}
				printf("Wie viele Schritte bis zur Wand?\n");
				printf("Eingabe: ");
				scanf_s("%d", &schritteInput);
				// TODO:
				// Bug fixen
				if (schritteInput < 0) {
					trashInput = false;

					schritteGesamt += schritteInput;

					int i;
					i = 1 + schritteGesamt - schritteInput;
					while (i <= schritteGesamt) {
						printf("%d. Schritt\n", i);
						i++;
					}
					printf("Wand erreicht\n");
					umdrehungen++;
					printf("%d. Linksdrehung\n", umdrehungen);
				}
				else {
					trashInput = true;
				}
			} while (trashInput);
		}
		else {
			do {
				do {
					if (trashInput) {
						printf("UNZUL%cSSIGER INPUT!!!\n", AE);
					}
					printf("Ist der Stuhl da?\n");
					printf("y/n: ");
					scanf_s("%s", stuhl);

					stuhl[0] = tolower(stuhl[0]);
					if (stuhl[0] == 'y' || stuhl[0] == 'n') {
						trashInput = false;
					}
					else {
						trashInput = true;
					}
				} while (trashInput);

				if (stuhl[0] == 'n') {
					schritteGesamt++;
					printf("%d. Schritt\n", schritteGesamt);
				}
			} while (stuhl[0] != 'y');
			break;
		}
	}

	printf("STUHL ERREICHT \\(^.^)/\n");
	printf("Anzahl Umdrehungen: %d\n", umdrehungen);
	printf("Anzahl Schritte: %d\n", schritteGesamt);
	return 0;
}