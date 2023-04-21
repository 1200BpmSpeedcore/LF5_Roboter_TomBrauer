#include <ctype.h>

#include "inputChecker.h"

void CheckStringToUInt(char toCheck[], int* canConvert) {
	int i;
	for (i = 0; i < sizeof(toCheck); ++i) {
		if (!isdigit(toCheck[i])) {
			if (!(toCheck[i] == '\0' && i > 0)) {
				*canConvert = 0;
			}
			break;
		}
	}
	*canConvert = 1;
}

void FirstLetterYOrN(char toCheck[], int* isYesNo) {
	toCheck[0] = tolower(toCheck[0]);

	if (toCheck[0] == 'y' || toCheck[0] == 'n') {
		*isYesNo = 1;
	}
	else {
		*isYesNo = 0;
	}
}
