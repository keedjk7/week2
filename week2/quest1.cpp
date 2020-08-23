#include<stdio.h>


int WASH(int cloath,bool C) {
	if (C == false) {
		printf("Use Washing Machine : %d\n",cloath / 20 + 1);
		return (30 * (cloath / 20 + 1));
	}
	else {
		printf("Use Washing Machine : %d\n", cloath / 20) ;
		return (30 * (cloath / 20 ));
	}
}

int DRY(int cloath,bool C) {
	if (C == false) {
		printf("Use Clothes dryer : %d\n", cloath / 30 + 1);
		return (50 * (cloath / 30 + 1));
	}
	else {
		printf("Use Clothes dryer : %d\n", cloath / 30);
		return (50 * (cloath / 30));
	}

}

int main() {
	char weather;
	int cloath, money = 0;
	printf("number of cloathes : ");
	scanf_s("%d", &cloath);
	printf("weather today : ");
	scanf_s(" %c", &weather);
	if (weather=='S'&&cloath>0) {
		if (cloath % 20 != 0) {
			money += WASH(cloath, 0);
		}
		else {
			money += WASH(cloath, 1);
		}
		printf("\nAll money is required : %d", money);
	}
	else if (weather=='R'&&cloath>0) {
		if (cloath % 20 != 0) {
			money+=WASH(cloath,0);
		}
		else {
			money += WASH(cloath, 1);
		}

		if (cloath % 30 != 0) {
			money += DRY(cloath, 0);
		}
		else {
			money += WASH(cloath, 1);
		}
		printf("\nAll money is required : %d Bath", money);
	}
	else{
		printf("No Cloathes For Washing");
	}
	return 0;
}