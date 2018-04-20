/*
 * geometry.c
 *
 *  Created on: Apr 15, 2018
 *      Author: Zeeshan
 *
 *
 *  Write a program that displays the following menu:
	Geometry Calculator
	1. Calculate the Area of a Circle
	2. Calculate the Area of a Rectangle
	3. Calculate the Area of a Triangle
	4. Quit
*/



 #include <stdio.h>
	double areaCircle(int radius);
	int areaRectangle(int length, int width);
	double areaTriangle(int base, int height);

	double areaCircle(int radius) {
	return 3.14159 * radius * radius;
	}

	int areaRectangle(int length, int width) {
		return length * width;
	}

	double areaTriangle(int base, int height) {
		return .5 * base * height;
	}

int main() {
		int areaInt, length, width;
		double areaDouble, radius, base, height;
		int choice;

		printf("Geometry Calculator");
		printf("\n\t1. Calculate the Area of a Circle\n");
		printf("\t2. Calculate the Area of a Rectangle\n");
		printf("\t3. Calculate the Area of a Triangle\n");
		printf("\t4. Quit\n");
		printf("\nEnter number from the menu (1-4): ");
		scanf("%d", & choice);

		switch(choice) {
		case 1:
			printf("Please enter the radius: ");
			scanf("%lf", & radius);
			areaDouble = areaCircle(radius);
			printf("\nThe area is %.2f", areaDouble);
			break;
		case 2:
			printf("Please enter the length: ");
			scanf("%d", &length);
			printf("\nPlease enter the width: ");
			scanf("%d", &width);
			areaInt = areaRectangle(length, width);
			printf("\nThe area is %d", areaInt);
			break;
		case 3:
			printf("Please enter the base: ");
			scanf("%lf", &base);
			printf("\nPlease enter the height: ");
			scanf("%lf", &height);
			areaDouble = areaTriangle(base, height);
			printf("\nThe area is %.2f", areaDouble);
			break;
		default:
			break;
		}

		return 0;
}
