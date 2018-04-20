/*
 * RestaurantBill.c
 *
 *  Created on: Apr 19, 2018
 *      Author: Zeeshan
 */


#include <iostream>

	using namespace std;

int main()
	{

	//Declare Variables
	double meal_charge,tax,tip,total, total_bill;
	meal_charge = 88.67; // in dollars

	//Calculations
	tax = meal_charge * 6.75 / 100;
	tip = total *20/100;    //Cost of tip
	total = meal_charge + tax;  //cost of total
	total_bill = total +tip;    //mealCost + tax + tip

	cout<<" Restaurant Bill";
	cout<<"\n Meal Cost: "<<"$"<< meal_charge;
	cout<<"\n Tax amount: "<<"$"<< tax;
	cout<<"\n Tip amount: "<<"$"<< tip;
	cout<<"\n Total bill : "<<"$"<< total_bill;

	return 0;

}

