/*
 * populaton.c
 *
 *  Created on: Apr 17, 2018
 *      Author: Zeeshan
 *
 *
	 *      Population
	In a population, the birth rate is the percentage increase of the population due to births,
	and the death rate is the percentage decrease of the population due to deaths.
	Write a program that displays the size of a population for any number of years.
 */


#include <stdio.h>
#include <stdlib.h>

double calculatePopulationYear(int P, double B, double D){
	double newPopulation = (P + B*P - D*P);
	return newPopulation;
}

int main(){

	int originalSize, numOfYears;
	double birthRate,deathRate;
	//
	printf("Please enter the starting size of population\n");
	scanf("%d", &originalSize);
	if(originalSize < 2){
		printf("Error, incorrect input for population: ");
		exit(1);
	}

	printf("Enter the annual birth rate: ");
	scanf("%f",&birthRate);
	if(birthRate < 0)
	{
		printf("Error, incorrect input for annual birth rate: ");
	}

	printf("Enter the annual death rate: ");
	scanf("%f", &deathRate);
	if(deathRate < 0)
	{
		printf("Error, incorrect input for death rate");
	}

	printf("Enter the numbers of years to display: ");
	scanf("%d",&numOfYears);
	if(numOfYears< 2){
		printf("Error, incorrect input for number of years ");

	}
	else{
		//calculate and print population for number of numOfYears
		double population = (double)calculatePopulationYear(originalSize,birthRate,deathRate);
		printf("Year 1: %.0f\n",population);

		for(int i = 0; i< numOfYears-1; i++){
			population = calculatePopulationYear(population,birthRate,deathRate);
			printf("Year %d: %.0f\n",i+2,population);
		}
	}

	return 0;

}
