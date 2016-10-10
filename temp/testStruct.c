#include <stdio.h>

struct data {
	int a;
	char *b;
};

typedef struct data DATA;

int main() {
	DATA sample;
	printf("Enter the data:");
	scanf("%d", &sample.a);
	scanf("%s", sample.b);
	printf("%d, %s", sample.a, sample.b);
}
