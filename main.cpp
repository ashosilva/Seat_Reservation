#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


const int ROWS = 13;
const int COLS = 6;
char seats[ROWS][COLS];
int num;
char alpha;

void init();
void printMenu();
void printSeats();
void getSeatInput(int &rowNum, char &colChar);
int convertColChar(const char& c);
bool checkAvailability(const int& rowNum, const int& colNum);
void reserveSeat();
void reserveSeat(const int& numSeats);

int main(){
    
    int numSeats;
    int opt;
    
    
    init();
Menu:
    printMenu();
    cin >> opt;
    
    
    if (opt == 1) {
        
        printSeats();
        goto Menu;
        
    } else if(opt == 2){
        
        reserveSeat();
        goto Menu;
        
    } else if(opt == 3){
        
        cout << "How many seats would you like to reserve?: ";
        cin >> numSeats;
        reserveSeat(numSeats);
        goto Menu;
        
        
    } else if(opt == 4){
        
        system("pause");
        return 0;
        
    } else {
        
        cout << "ERROR!!!. Wrong Key Pressed.";
        cout << endl;
        goto Menu;
        
    }
    
    
}


//Initial display of the Seats
void init(){
    
    cout << setw(10) << 'A' << setw(5) << 'B' << setw(5) << 'C' << setw(5) << 'D' << setw(5) << 'E' << setw(5) << 'F' ;
    cout << endl << endl;
    
    for (int i = 0; i < 13 ; i++) {
        
        cout << "ROW " << i + 1;
        
        for (int j = 0; j < 6; j++) {
            seats[i][j] = '*';
            cout << setw(5) << seats[i][j] ;
        }
        cout << endl << endl;
    }
    
}


//Prints the Menu
void printMenu(){
    
    
    cout << "**********************************************";
    cout << endl;
    
    cout << "Plane Seat Reservation Program";
    cout << endl;
    cout << "Please select a menu option from below:";
    cout << endl;
    cout << "1. Show Seats";
    cout << endl;
    cout << "2. Reserve a single seat";
    cout << endl;
    cout << "3. Reserve multiple seats";
    cout << endl;
    cout << "4. Exit";
    cout << endl;
    
    cout << "**********************************************";
    cout << endl;
}


//Prints the seats containing either available seats(*) or reserved sests(x)
void printSeats(){
    
    cout << setw(10) << 'A' << setw(5) << 'B' << setw(5) << 'C' << setw(5) << 'D' << setw(5) << 'E' << setw(5) << 'F' ;
    cout << endl << endl;
    
    for (int i = 0; i < 13 ; i++) {
        
        cout << "ROW " << i + 1;
        
        for (int j = 0; j < 6; j++) {
            cout << setw(5) << seats[i][j] ;
        }
        cout << endl << endl;
    }
    
}


//Getting the users input
void getSeatInput(int &rowNum, char &colChar){
    cout << "Please enter the seat Row Number: ";
    cin >> rowNum;
    cout << endl;
    cout << "Please enter the seat Column Character: ";
    cin >> colChar;
    cout << endl;
    if (colChar < 'A' or colChar > 'F' ) {
        cout << "ERROR!!!. You typed the wrong character.";
        cout << endl << endl;
        colChar = '\0';
    }
}


//Converts the LETTER to its corresponding NUMBER.
int convertColChar(const char& c){
    
    switch (c)
    {
        case 'A':
            return 1;
            break;
        case 'B':
            return 2;
            break;
        case 'C':
            return 3;
            break;
        case 'D':
            return 4;
            break;
        case 'E':
            return 5;
            break;
        case 'F':
            return 6;
            break;
        default:
            return c;
            
        
    }

}



//Checks if the seat is available
bool checkAvailability(const int& rowNum, const int& colNum){
    
    
    if (seats[rowNum - 1][colNum - 1] == '*') {
        return true;
    } else {
        return false;
    }
    
}





//Reserves just one seat
void reserveSeat(){
    
Rechoose:
    getSeatInput(num, alpha);
    
    if (convertColChar(alpha) != '\0') {
        
        if (checkAvailability(num, convertColChar(alpha)) == true) {
            seats[num - 1][convertColChar(alpha) - 1] = 'X';
            cout << "Seat Reserved";
            cout << endl << endl;
        } else {
            cout << "Sorry this seat is already taken!!!";
            cout << endl << endl;
            goto Rechoose;
            
        }
        
    } else {
    
        goto Rechoose;
    }
    
    
    
}


//Reserves multiple seats
void reserveSeat(const int& numSeats){
    
    cout << "Please enter your choice of seats one at a time. Please make sure to enter correct seat #.";
    cout << endl;
    
    for (int i = 0; i < numSeats; i++) {
        
    Rechoose:
        getSeatInput(num, alpha);
        
        if (convertColChar(alpha) != '\0') {
            
            if (checkAvailability(num, convertColChar(alpha)) == true) {
                seats[num - 1][convertColChar(alpha) - 1] = 'X';
                cout << "Seat Reserved";
                cout << endl << endl;
            } else {
                cout << "Sorry this seat is already taken!!!. Pick another one";
                cout << endl << endl;
                goto Rechoose;
                
            }
            
        } else {
            goto Rechoose;
        }
        
        
    }
    
    
}
