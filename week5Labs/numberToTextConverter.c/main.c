#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	int firstDigit;
	int secondDigit;

	printf("Enter a number between 0-100: ");
	scanf("%d", &num);

	if ((num < 0) || (num >= 100)) {
		printf("Invalid, number. Number must be between 0-100");
		main();
	}

	secondDigit = num % 10;
	firstDigit = num-secondDigit;

	if ((num >= 10) && (num <20)){
		switch (num) {
		case 10:
			printf("Ten ");
			break;
		case 11:
			printf("Eleven");
			break;
		case 12:
			printf("Twelve");
			break;
		case 13:
			printf("Thirteen");
			break;
		case 14:
			printf("Fourteen");
			break;
		case 15:
			printf("Fifteen");
			break;
		case 16:
			printf("Sixteen");
			break;
		case 17:
			printf("Seventeen");
			break;
		case 18:
			printf("Eighteen");
			break;
		case 19:
			printf("Nineteen");
			break;
		}

	} else {

		switch(firstDigit){ 
		case 20:
			printf("Twenty ");
			break;
		case 30:
			printf("Thirty ");
			break;
		case 40:
			printf("Forty ");
			break;
		case 50:
			printf("Fifty ");
			break;
		case 60:
			printf("Sixty ");
			break;
		case 70:
			printf("Seventy ");
			break;
		case 80:
			printf("Eighty ");
			break;
		case 90:
			printf("Ninety ");
			break;
		}

		switch (secondDigit){
		case 1:
			printf("One");
			break;
		case 2:
			printf("Two");
			break;
		case 3:
			printf("Three");
			break;
		case 4:
			printf("Four");
			break;
		case 5:
			printf("Five");
			break;
		case 6:
			printf("Six");
			break;
		case 7:
			printf("Seven");
			break;
		case 8:
			printf("Eight");
			break;
		case 9:
			printf("Nine");
			break;
	}

	}



	return 0;
}






























