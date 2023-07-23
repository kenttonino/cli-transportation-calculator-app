#include <iostream>
#include "./headers/appdescription.hpp"
#include "./headers/clearscreen.hpp"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
using namespace std;

int main() {  
  int totalSeats;
  int totalPassengers;
  int emptySeats;
  int isContinue;

  do {
    // * Clean up the screen first.
    clearScreen();

    // * Application description.
    appDescription();

    // * Ask input for total bus seats.
    cout << endl << "Enter the total number of bus seats: ";
    cin >> totalSeats;

    // * Ask input for total passengers.
    cout << "Enter the total number of passengers: ";
    cin >> totalPassengers;

    if (totalPassengers < totalSeats) {
      // * If passengers less than total seats.
      emptySeats = totalSeats - totalPassengers;
      cout << "Total last trip empty seats: " << emptySeats << endl << endl;
      
      // * Ask if want to continue.
      cout << "Do you want to continue (1 - yes, 0 = no)?: ";
      cin >> isContinue;
    } else {
      emptySeats = totalPassengers % totalSeats;
      
      if (emptySeats == 0) {
        // * If total seats is divisible by total passengers.
        cout << "Total last trip empty seats: " << emptySeats << endl << endl;

        // * Ask if want to continue.
        cout << "Do you want to continue (1 - yes, 0 = no)?: ";      
        cin >> isContinue;
      } else {
        // * If total seats are not divisible by total passengers.
        emptySeats = totalSeats - emptySeats;
        cout << "Total last trip empty seats: " << emptySeats << endl << endl;
        
        // * Ask if want to continue
        cout << "Do you want to continue (1 - yes, 0 = no)?: ";      
        cin >> isContinue;
      }
    }
  } while (isContinue != 0);

  cout << endl << "**THANK YOU FOR USING**" << endl;

  return 0;
}

