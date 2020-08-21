#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int number;

int RANDOM() {
	int N;

	N = rand() % 10;

	return N;
}

int main() {
	int first[6], second[5][6], near_first[2][6], third[10][6],fourth[50][6],fifth[100][6], lottery[10000][6], ticket[10000], C[1000] = {0};
	long int Price=0;
	int keep;
	bool Check_Price = false;
	printf("Number of Lotteries Purchased : ");
	scanf_s("%d", &number);	
	srand(time(0));

	char input[7];
	for (int i = 0; i < number; i++) {
		printf("Lottery numbers you want Ticket %d : ",i+1);
		scanf_s("%s", &input,7);
		for (int j = 0; j < 6; j++) {
			lottery[i][j]=input[j]-49;
		}
		printf("\tNumber of Tickets : ");
		scanf_s("%d", &ticket[i]);
	}
	printf("\nFirst Price : \n");
	for (int i = 0; i < 6; i++) {
		first[i] = RANDOM();
		if (i != 6) {
			near_first[0][i] = first[i];
			near_first[1][i] = first[i];
		}
		for (int k = 0; k < number; k++) {
			if (first[i]==lottery[k][i]) {
				C[k]++;
				if (C[k] == 6) {
					Price += ticket[k] * 5000000;
					C[k] = 0;
				}
			}
		}
		printf("%d", first[i]);
	}
	printf("\nNear The First Price : \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			bool Check = false;
			if (i == 0&&j==5) {
				while (Check != true) {
					near_first[0][5] = RANDOM();
					if (near_first[0][5] != first[5]) {
						Check = true;
					}
				}
			}
			else if(i==1&&j==5){
				while (Check != true) {
					near_first[1][5] = RANDOM();
					if (near_first[1][5] != first[5] && near_first[1][5] != near_first[0][5]) {
						Check = true;
					}
				}
			}
			printf("%d", near_first[i][j]);
			for (int k = 0; k < number; k++) {
				if (near_first[i][j] == lottery[k][i]) {
					C[k]++;
					if (C[k] == 3) {
						Price += ticket[k] * 100000;
						C[k] = 0;
					}
				}
			}
		}
		printf("\t");
	}

	printf("\nSecond Price : \n");
	for (int i = 0; i < 5; i++) {		
		for (int j = 0; j < 6; j++) {
			second[i][j] = RANDOM();
			printf("%d", second[i][j]);
			for (int k = 0; k < number; k++) {
				if (second[i][j] == lottery[k][i]) {
					C[k]++;
					if (C[k] == 6) {
						Price += ticket[k] * 200000;
						C[k] = 0;
					}
				}
			}
		}	
		printf("\t");
	}
	printf("\nThird Price : \n");
	for (int i = 0; i < 10; i++) {
		C[10] = { 0 };
		for (int j = 0; j < 6; j++) {
			third[i][j] = RANDOM();
			printf("%d", third[i][j]);
			for (int k = 0; k < number; k++) {
				if (third[i][j] == lottery[k][i]) {
					C[k]++;
					if (C[k] == 6) {
						Price += ticket[k] * 80000;
						C[k] = 0;
					}
				}
			}
		}
		printf("\t");
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	printf("\nFourth Price : \n");
	for (int i = 0; i < 50; i++) {
		C[10] = { 0 };
		for (int j = 0; j < 6; j++) {
			fourth[i][j] = RANDOM();
			printf("%d", fourth[i][j]);
			for (int k = 0; k < number; k++) {
				if (fourth[i][j] == lottery[k][i]) {
					C[k]++;
					if (C[k] == 6) {
						Price += ticket[k] * 80000;
						C[k] = 0;
					}
				}
			}
		}
		printf("\t");
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	printf("\nFifth Price : \n");
	for (int i = 0; i < 100; i++) {
			C[10] = { 0 };
			for (int j = 0; j < 6; j++) {
				fifth[i][j] = RANDOM();
				printf("%d", fifth[i][j]);
				for (int k = 0; k < number; k++) {
					if (fifth[i][j] == lottery[k][i]) {
						C[k]++;
						if (C[k] == 6) {
							Price += ticket[k] * 80000;
							C[k] = 0;
						}
					}
				}
			}
			printf("\t");
			if ((i + 1) % 10 == 0) {
				printf("\n");
			}
		}
	if (Check_Price == false) {
		printf("\nUnfortunately,You are not winning");
	}
	else {
		printf("\nCongratulation!! You won, received money %d Bath", Price);
	}
}