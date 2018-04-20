/*
 * PatternDisplay.c
 *
 *  Created on: Apr 19, 2018
 *      Author: Zeeshan
 */


#include<iostream>
using namespace std;

int main(){
    int n =10;
    int i = 0, j;

    cout<<"Pattern A\n";
    do {
        j = 0;
    do {
        cout<<"*";
    } while (++j <= i);
        cout<<"\n";

    } while (++i < n);
        cout<<"\n";
        cout<<"Pattern B";
        cout<<"\n";
        i = n;
    do {
        j = i;
    do {
        cout<<"*";
    } while (--j > 0);
        cout<<"\n";
    } while (--i > 0);

    return 0;
    }
