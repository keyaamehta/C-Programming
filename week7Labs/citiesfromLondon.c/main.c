#include <stdio.h>

int main () {

	FILE *cityPtr;
	FILE *newFilePtr;
	int miles;
	char city[20];
	int i;

	cityPtr = fopen("cities.txt", "r");
	newFilePtr = fopen("farCities.txt", "w");

	while (fscanf(cityPtr, "%d %s", &miles, city) != -1) {
		if (miles > 100) {
			fprintf(newFilePtr, "%d %s \n", miles, city);
		}
	}

	return 0;

}

































