/*
 --------------------------------------------------------------------------------
 File:    main.c
 Description: Caesar's Cipher is a type of substitution cipher in which each 
 letter in the plaintext is replaced by a letter some fixed number of positions 
 down the alphabet
 Author:  William Mabia
 --------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Encoder
void encode(char file_name[], int key) {
	char message[1000];
	int i, length;
	FILE *outfile;
	
	//Open the file and get the get its contents.
	outfile = fopen(file_name, "r");
	fgets(message, 50, outfile);
	
	//Print the contents of the file.
	printf("Message: %s\n", message);

	length = strlen(message);
	
	//Ensure file is not empty
	if (length == 0) {
		printf("No message provided");
	}

	else if (length > 0) {
		//for loop goes through all characters in the message array (i didn't use "i<length" because message[i] goes through message array until final char
		for (i = 0; message[i]; i++) {  

			// for upper case letters
			if (message[i] >= 'A' && message[i] <= 'Z') {
				message[i] -= key;
				if (message[i] > 'Z') { // if key makes a character go over "Z"
					message[i] -= 26; // it uses the ascii value to make values over z go back and start at a
				}
			}
			//for lower case characters
			else if (message[i] >= 'a' && message[i] <= 'z') {
				message[i] += key;
				//This if statement ensure whenever the key makes the letter go over  z it goes to a
				if (message[i] > 'z') {
					message[i] -= 26;
				}
			}
		}
	}
	printf("\n");
	printf("Encryption: %s\n\n", message);

}
void decode(char file_name[], int key) {
	char message[1000];
	int i, length;
	FILE *outfile;
	outfile = fopen(file_name, "r");
	fgets(message, 50, outfile);

	printf("Encrypted Message: %s\n", message);

	length = strlen(message);
	
	//Ensure the file is not empty
	if (length == 0) {
		printf("No message provided");
	}

	else if (length > 0) {
		for (i = 0; message[i]; i++) { // for loops goes through all characters in the message array (i didn't use i<length because message[i] goes through message array until it's empty. rember i can also use message[i] != '\0' cause the end of array has '\0'

			// for capital letters
			if (message[i] >= 'A' && message[i] <= 'Z') {
				message[i] -= key;
				if (message[i] < 'A') { // if key makes a character go above a
					message[i] += 26; // it uses the ascii value to make values above go to z
				}
			}
			// this is the earlier if statement for lower case characters
			else if (message[i] >= 'a' && message[i] <= 'z') {
				message[i] -= key;
				if (message[i] < 'a') {
					message[i] += 26;
				}
			}
		}
	}
	printf("\n");
	printf("Encryption: %s\n\n", message);
}

int main() {
	
	//encode("textforencoding.txt", 5);
	//decode("textfordecoding.txt", 5);

}

