/*
 * StockTranscation.c
 *
 *  Created on: Apr 19, 2018
 *      Author: Zeeshan
 */



#include <iostream>

using namespace std;
int main()
{
//Purchased Stock
double shares_purchased = 1000;
double paid = 45.50;
double commisionPurchased = 0.02;
//sold stock
double sharesSold =1000;
double soldPaid= 56.90;
double commisionReceived = 0.02;

//Total calculations
double totalPaidPurchase = shares_purchased * paid ;
double totalCommisiomPurchased = commisionPurchased * totalPaidPurchase;
double soldAmount = soldPaid * sharesSold;
double soldCommision = soldAmount* commisionReceived;
double profit = (soldAmount - (totalPaidPurchase + totalCommisiomPurchased + soldCommision));

//Print statements
cout<<"The amount of money Joe paid for the stock is : $ " << totalPaidPurchase;
cout<<"\n The amount of commission Joe paid his broker when he bought the stock : $" << totalCommisiomPurchased ;
cout<<"\n The amount that Joe sold the stock for $ " << soldAmount;
cout<<"\n The amount of commision Joe paid his broker when he sold the stock : $" << soldCommision;
cout<<"\nTotal Profit is: $"<< profit;



return 0;
}
