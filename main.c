/*
 -------------------------------------
 File:    main.c
 Caesar's Cipher
 Author:  William Mabia
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Encoder

int main() {
	char message[1000];
	int i, key = 0, length, l = 10, j;

	//take input from character
	printf("Enter characters to encrypt: \n");
	gets(message);

	//Take input key
	printf("Enter key: ");
	scanf("%d", &key);

	length = strlen(message);

	if (length == 0) { // if statement that checks if input is empty
		printf("No message provided");
	}

	else if (length > 0) {
		for (i = 0; message[i]; i++) { // for loops goes through all characters in the message array (i didn't use i<length because message[i] goes through message array until it's empty. rember i can also use message[i] != '\0' cause the end of array has '\0'

			// for capital letters
			if (message[i] >= 'A' && message[i] <= 'Z') {
				message[i] -= key;
				if (message[i] > 'Z') { // if key makes a character go over z
					message[i] -= 26; // it uses the ascii value to make values over z go back and start at a
				}
			}
			// this is the earlier if statement for lower case characters
			else if (message[i] >= 'a' && message[i] <= 'z') {
				message[i] += key;
				if (message[i] > 'z') {
					message[i] -= 26;
				}
			}
		}
	}

	printf("%s\n", message);

}
