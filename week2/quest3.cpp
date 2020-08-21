#include<stdio.h>

int main() {
	int input;
	scanf_s("%d", &input);
	for (int i = 0; i < input * 2 + 3; i++) {
		for (int j = 0; j < input * 2 + 3; j++) {
			//up
			if (i < input && input < j &&j< (input * 2) - i+1) {
				printf("*");
			}
			//left
			else if (2 <= i && i < input + 2 && j < i - 1) {
				printf("*");
			}
			//right
			else if (input < i && i < input * 2 + 1 && i + 1 < j) {
				printf("*");
			}
			//down
			else if (input+2<i&&(input*2)-i+3<j&&j<input+2) {
				printf("*");
			}
			//core 
			else if ((i == input || i == input + 2) && j == input + 1) {
				printf("*");
			}
			else if (i == input + 1 && input <= j && j <= input + 2) {
				if (j != i) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
