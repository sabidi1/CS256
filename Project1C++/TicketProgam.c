
//
//  TheaterSeating.cpp
//
//
//  Created by Zeeshan Abidi on 4/21/18.
//


#include <iostream>
#include <iomanip>
using namespace std;

int DisplayMenu ();
void DisplaySeatingChart ();

//declare constant variables
const char takenSeat = '*';
const char emptySeat = '#';
const int numOfRows = 15;
const int numOfColumns = 30;

//map = key value and mapped value
char map [numOfRows][numOfColumns];

//Declare variables
double price;
int totalCost = 0;
int totalSeats = 450;
int totalSeatsPurchased = 0;
int Quit = 1;


int main ()
{
    int price [numOfRows];
    int rowEntered, columnEntered;
    int cost;
    int userAnswer;

    //ask user to input pric for each row
    for (int i = 0; i < numOfRows; i++)
    {
        cout << "Enter the seat cost for each row " << (i + 1) << ": ";
        cin >> price [i];
    }

    //fill array with emptySeat
    for (int i = 0; i < numOfRows; i++)
    {
        for (int j = 0; j < numOfColumns; j++)
        map [i][j] = emptySeat;
    }

    //switch statement to handle manu options
    int choice;
    do
    {
        choice = DisplayMenu();
        switch (choice)
        {
            case 1:
            cout << "View Seat Prices\n\n";

            for (int i = 0; i < numOfRows; i++)
            {
                cout << "The price for row " << (i + 1) << ": ";
                cout << price [i] << endl;
            }
            break;
            case 2:
            cout << "Purchase a Ticket\n\n";
            do
            {
                //Ask user for seat info
                cout << "Please enter the row number you would like: ";
                cin >> rowEntered;
                cout <<"Please enter the seat you would like: ";
                cin >> columnEntered;

                //Seat taken
                if (map [rowEntered] [columnEntered] == '*')
                {
                    cout << "Sorry, that seat is taken. Please select another seat:  ";
                    cout << endl;
                }
                else
                {
                    //cost is the price enterted by user
                    cost = price [rowEntered] ;
                    totalCost = totalCost + cost;

                    cout << "The ticket you selected costs:  " << cost << endl;
                    cout << "Confirm Purchase?( 1 = YES     2 = NO)";
                    cin >> userAnswer;
                    totalSeats = totalSeats - userAnswer;
                    totalSeatsPurchased += userAnswer;

                    //user presses 1 or 2 to confirm purchase
                    if (userAnswer == 1)
                    {
                        cout << "Your ticket purchase has been confirmed." << endl;
                        map [rowEntered][columnEntered] = takenSeat;
                    }
                    else if (userAnswer == 2)
                    {
                        cout << "Would you like to look at another seat? (1 = YES / 2 = NO)";
                        cout << endl;
                        cin >> Quit;
                    }

                    cout << "Would you like to look at another seat?(1 = YES / 2 = NO)";
                    cin >> Quit;
                }
            }while (Quit == 1);     //while quit is true

            break;
            case 3:
            cout << "Seating Chart";
            cout << "* = Seat taken";
            cout << "# = Seat available";
            DisplaySeatingChart ();
            break;
            case 4:
            cout << "Total ticket sales: "<< totalCost<< ".\n";
            cout << "Total Seats sold: "<< totalSeatsPurchased << ".\n";
            cout << "Total seats available "<< totalSeats << ".\n";
            break;
            case 5:
            cout<<"Exiting program, Goodbye!";
            break;
             default : cout << "Error, invalid input\n";
        }
    } while (choice != 5);
    return 0;
}

int DisplayMenu()
{
    int userChoice;
    cout << "---------------------------------------------------\n";
    cout << "Main Menu\n";
    cout << " 1. View Seat Prices.\n";
    cout << " 2. Purchase a ticket.\n";
    cout << " 3. View Available Seats.\n";
    cout << " 4. View ticket Sales.\n";
    cout << " 5. Quit the program.\n";
    cout << "---------------------------------------------------\n";
    cout << "Please enter your choice: ";
    cin >> userChoice;

    return userChoice;
}

void DisplaySeatingChart ()
{

    cout << "      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30";
    for (int i = 0; i < 15; i++)
    {
        cout << endl << "Row " << (i + 1);
        for (int j = 0; j < 30; j++)
        {
            cout << " " <<  map [i] [j];
        }
    }
    cout << endl;
}

