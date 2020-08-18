#include<stdio.h>
#include<math.h>

int main() {
	char input;
	double perimeter, area;
	scanf_s("%c", &input);
	//Circle
	if (input == 'C') {
		float R;
		scanf_s("%f", &R);
		area = 3.141591 * R * R;
		perimeter = 2 * 3.141592 * R;
	}
	//Square
	else if (input == 'S') {
		float D1, D2;
		scanf_s("%f%f", &D1, &D2);
		area = D1 * D2;
		perimeter = 2 * (D1 + D2);
	}
	//right angled triangle
	else if (input == 'T') {
		float H, B;
		scanf_s("%f%f", &B, &H);
		area = 0.5 * B * H;
		perimeter = (H + B) + (sqrt(B * B + H * H));
	}
	//Output
	if (input == 'S') {
		printf("Square\n");
	}
	else if (input == 'C') {
		printf("Circle\n");
	}
	else if (input == 'T') {
		printf("Triangle\n");
	}
	else {
		printf("No Data");
		return 0;
	}
	printf("Perimeter = %lf\n", perimeter);
	printf("Area = %f", area);
	return 0;
}