/*
 * populaton.c
 *
 *  Created on: Apr 19, 2018
 *      Author: Zeeshan
 *
 *      Write a function that accepts an int array and the array’s size as arguments.
 *      The func- tion should create a copy of the array,
 *      except that the element values should be reversed in the copy.
 *      The function should return a pointer to the new array.
 *      Demonstrate the function in a complete program.
 */




	#include <stdio.h>
	#include<stdlib.h>

	int* reverseArray(int arr[], int size){
	   int* result = (int*) malloc (sizeof (int)*size);
	   int i;
	   //read array
	   for(i = 0;i<size;i++){
		  result[i] = arr[size-i-1];
	   }
	   return result;
	}

	int main() {
	   int n,i;
	   int arr[200];
	   int * result;

	   printf("Enter size: ");
	   scanf("%d",& n);
	   printf("Enter %d numbers: ", n);
	   for(i = 0; i< n; i++){
		  scanf("%d", &arr[i]);
	   }

	   //print out reversed aray
	   result = reverseArray(arr, n);
	   printf("Reversed array is: ");
	   for(i = 0; i< n; i++){
		  printf("%d ",result[i]);
	   }
	   return 0;
	}
