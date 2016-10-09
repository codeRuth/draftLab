// Design, Develop and Implement a Program in C for the following operations on Strings
//	a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
// 	b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR
//	   with REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR

#include <stdio.h>

int strlen(char input[]) {
	int i;
	for(i=0; input[i]!='\0'; i++);
	return i;
}

int stcmp(char src[], char dest[]) {
	while(*src && (*src == *dest)) {
		src++, dest++;
	}
	return *(char*)src - *(char*)dest;
}

int main() {
	char senString[50], serString[20], repString[20], tempString[50], destString[50];
	int i, j, count = 0, senLength, serLength, repLength, l1 = 0, l;
	
	printf("Enter a Sentence: ");
	gets(senString);
	printf("Enter Search String: ");
	gets(serString);
	printf("Enter Replace String: ");
	gets(repString);

	senLength = strlen(senString);
	serLength = strlen(serString);
	repLength = strlen(repString);
	
	for(i=0;i<senLength;i++) {
		for(j=0; j<serLength; j++)
			tempString[j] = senString[i+j];
		tempString[j] = '\0';
		if (stcmp(tempString, serString) == 0) {
		 	count++;
		 	for(l=0; l<repLength; l++) {
		 		destString[l1] = repString[l];
		 		l1++;
		 	}
		 	i = i+(serLength-1);
		} else {
			destString[l1] = senString[i];
			l1++;
		}
	}

	destString[l1] = '\0';
	printf("The String has %d Occurrences.\n", count);
	printf("The Resultant String is : %s\n", destString);
	return 0;
}
