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


// Display the seating chart
void showSeats(string seats[], int available_seats) {
    cout << "\n------------------- Bus Seat Arrangement -------------------\n";
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].empty()) {
            // Available seat
            if (i + 1 < 10) cout << "[ " << i + 1 << "]\t"; // spacing for single-digit
            else cout << "[" << i + 1 << "]\t";
        } else {
            // Reserved seat
            cout << "[X]\t";
        }

        // New row after every 5 seats
        if ((i + 1) % 5 == 0) cout << endl;
    }

    cout << "\nTotal seats left: " << available_seats << "\n";

    // Show reserved seat details
    cout << "\n--- Reserved Seats ---\n";
    bool anyReserved = false;
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (!seats[i].empty()) {
            cout << "Seat " << i + 1 << ": " << seats[i] << endl;
            anyReserved = true;
        }
    }
    if (!anyReserved) cout << "No seats are reserved yet.\n";
}