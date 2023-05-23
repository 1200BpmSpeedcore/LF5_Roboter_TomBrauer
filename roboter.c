#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void getStuhlInput();
void getAnzahlSchritte();
void printSchritte(int j, int schritteGesamt, int umdrehungen, bool* stuhlErreicht);

char input[];

int main() {
    int schritteGesamt = 0;
    int umdrehungen = 0;
    bool stuhlErreicht;

    do {
        getStuhlInput();

        getAnzahlSchritte();
        int schritteDurchgang = atoi(input);
        schritteGesamt += schritteDurchgang;
        printSchritte(1 + schritteGesamt - schritteInDurchgang, schritteGesamt, umdrehungen, *stuhlErreicht)
    } while (!stuhlErreicht);

    printf("Anzahl Umdrehungen: %d\n", umdrehungen);
	printf("Anzahl Schritte: %d\n", schritteGesamt);

    return 0;
}
