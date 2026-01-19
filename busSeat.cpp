#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int TOTAL_SEATS = 50;

void showSeats(string seats[], int available_seats);
void reserveSeat(string seats[], int &available_seats);
void cancelSeat(string seats[], int &available_seats);
void changeSeat(string seats[]);


int main() {
    
    string seats[TOTAL_SEATS]; // 50 seats
    int available_seats = TOTAL_SEATS;
    int choice;
    do {
        cout << "\n--- Bus Reservation Menu ---\n";
        cout << "1. Show available seats\n";
        cout << "2. Reserve a seat\n";
        cout << "3. Cancel a seat\n";
        cout << "4. Change seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
        cin.clear(); // clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "\aInvalid input! Please enter a valid number.\n";
        continue;
        }


        switch (choice) {
            case 1: showSeats(seats, available_seats); break;
            case 2: reserveSeat(seats, available_seats); break;
            case 3: cancelSeat(seats, available_seats); break;
            case 4: changeSeat(seats); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "\aInvalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}