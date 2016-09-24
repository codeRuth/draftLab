#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct data {
	char *name;
   char *USN;
   int semester;
   double phoneNumber;
   char *branchName;
}
typedef struct data DATA;

struct student {
	int key;
	DATA d;
   struct student *next;
};

struct student *head = NULL;
struct student *current = NULL;

void printList() {
   struct node *ptr = head;
   while(ptr != NULL) {        
      printf("%d", ptr->key); 
   	printf("%s", ptr->d.name);
     	printf("%s", ptr->d.USN);
  	 	printf("%d", ptr->d.semester);
   	printf("%.0f", ptr->d.phoneNumber);
   	printf("%c", ptr->d.branchName);
      	
      ptr = ptr->next;
      printf("\n");
   }
}

void insertFirst(int key, DATA d) {
   	struct node *link = (struct node*) malloc(sizeof(struct node));
	
   	link->key = key;
   	link->d = d;

   	link->next = head;
   	head = link;
}

struct node* deleteFirst() {
   struct node *tempLink = head;
   head = head->next;
   return tempLink;
}
 
int main() {

	DATA sample;

	sample.name = "Ruthvik";
	sample.USN = "1PE14IS086"; 
	sample.semester = 3;
	sample.phoneNumber = 8970464490;
	sample.branchName = "ISE";

	insertFirst(1, sample);
	insertFirst(2, sample);
	insertFirst(3, sample);
	insertFirst(4, sample);
	insertFirst(5, sample);
	insertFirst(6, sample);

	printf("The Records are - \n");
	printList();
}