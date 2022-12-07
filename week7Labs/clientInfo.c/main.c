// use fread() and fwrite()

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int account;
	int balance;
	char name[40];
} Customer;

int main() {

	Customer client;

	while (client.account != -1) {
		printf("\nEnter the account of the customer or -1 to finish:");
		scanf("%d", &client.account);

		if (client.account == -1) {
			return 0;
		}

		printf("\nEnter the name of the customer:");
		scanf("%s", &client.name);

		printf("\nEnter the balance of the customer:");
		scanf("%d", &client.balance);
	}


	return 0;

}



























