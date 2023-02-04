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
			scanf("%s", stuhl);

			stuhl[0] = tolower(stuhl[0]);
			if (stuhl[0] == 'y' || stuhl[0] == 'n') {
				trashInput = false;
			}
			else {
				trashInput = true;
			}
		} while (trashInput);

		if (trashInput) {
			printf("UNZUL%cSSIGER INPUT!!!\n", AE);
		}

		if (stuhl[0] == 'y') {
			printf("Wie viele Schritte bis zum Stuhl?\n");
		}
		else {
			printf("Wie viele Schritte bis zur Wand?\n");
		}
		printf("Eingabe: ");
		scanf_s("%d", &schritteInput);
		schritteGesamt += schritteInput;

		int i;
		i = 1 + schritteGesamt - schritteInput;
		while (i <= schritteGesamt) {
			printf("%d. Schritt\n", i);
			i++;
		}
		if (stuhl[0] == 'y') {
			break;
		}
		umdrehungen++;
		printf("Wand erreicht\n");
		printf("%d. Linksdrehung\n", umdrehungen);
	}

	printf("\n");
	printf("STUHL ERREICHT \\(^.^)/\n");
	printf("Anzahl Umdrehungen: %d\n", umdrehungen);
	printf("Anzahl Schritte: %d\n", schritteGesamt);

	return 0;
}