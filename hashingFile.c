#include <stdio.h>
#define MAX 99
typedef struct EMP{
	char SSN[5], studentName[20], nDept[15];
} EMP;

EMP hashTable[MAX];

void initTable() {
	int i;
	for(i = 0; i < m; i++)
		hashTable[i].SSN[0] = �#�;
}

int hashAdd(char[] key) {
	int h = 0, i = 0;
	while (key[i] != '\0') {
		h += key[i];
		i++;
	}
	return (h % m);
}

void createHashTable() {
	char SSN[5], studentName[20], nDept[15];
	int home = 0, i, j, count = 0;
	if(count == MAX)
		printf("\nHash Table is full");
	else {
		printf("\nEnter SSN, Student Name and Department :");
		scanf("%s%s%s", SSN, studentName, mDept);
		
		home = hashAdd(SSN);
		if(hashTable[home].SSN[0] != '#') {
			printf("\n Collision : Resolve using Linear Probing");
			i = home + 1;
			j = 0;
			while(j != MAX) {
				if(hashTable[i].SSN[0]!= '#')
					i = (i + 1) % m;
				else {
					home = i; 
					break;
				}
			}
		}
		strcpy(hashTable[home].SSN, SSN);
		strcpy(hashTable[home].studentName, studentName);
		strcpy(hashTable[home].nDept, nDept);
		count++;
	}
}

void displayTable() {
	int i = 0;
	for(i = 0; i < m; i++) {
		if(hashTable[i].SSN[0] != '#')
			printf("\nSSN = %s \tName = %s \tDepartment = %s\n", hashTable[i].SSN, hashTable[i].studentName, hashTable[i].mDept);
		else
			printf("\n%s\n", hashTable[i].SSN);
	}
}

void main() {
	int ch;
	initTable();
	do {
		createHashTable();
		displayTable();
		printf("\nDo you want to Continue: Press (0 / 1)");
		scanf("%d", &ch);
	} while(ch == 1);
}

void writeToFile() {
	FILE *fp;
	int i;
	fp = fopen("hello.txt", "w");
	for(i = 0; i < MAX; i++) {
		if(hashTable[i].SSN[0]!='#')
			fprintf(fp, "%s, \t%s, \t%s\n", HT[i].SSN, HT[i].Name, HT[i].dept);
	}
}
