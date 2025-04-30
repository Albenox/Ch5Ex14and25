/*
    Program File Name: Ch5Ex14and25.cpp
    Programmer: Gabriel Inocentes
    Date: April 29, 2025
    Requirements:
    Create a program that allows the user to input student names, then outputs an alphebetical order for them to line up in
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Declares function later to bubble sort names
void bubbleSort();
void getStudents(int count);

//Vector to hold list of names
vector<string> names;

// Function to get a valid number of students between 1 and 25
int main() {
    cout << "Enter the number of students that will be lined up: " << endl;
    int count;
    cin >> count;

    //Resets the input buffer before getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Loop to make sure inputs are within the set boundries, and resetting the cin if they are not
    while (cin.fail() || count < 1 || count > 25) {
        cin.clear();
        //Okay, I give up on this part somewhat, no matter what I try to do, the first time you enter a non-integer input, this error reads twice as the cin refuses to be read... I do not know the code to fix this
        cout << "Please enter a valid input greater than 1 and less than 25: " << endl << flush;
        cin >> count;

        //Clears the cache of inputs and resets the while loop
        if (cin.fail() || count < 1 || count > 25) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //Flush to ensure error message is output in cases of weird bugs when looping the while
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    
    //Sets the vector capacity to the count input from user
    names.resize(count);

    //Loop to add user input names to vector list
    getStudents(count);

    //Sorts the vector through the bubbleSort function
    bubbleSort();

    //Loop to display names in vector list
    for (int i=0; i < names.size(); i++) {
        cout << names[i] << endl;
    }
}

void bubbleSort() {
    //Loops through the for loop as many times as the size is
    for (int i = 0; i < names.size(); i++) {
        //Loops throught the full list once
        for (int x = 0; x < names.size() - 1; x++) {
            if (names[x] > names[x + 1]) {
                swap(names[x], names[x + 1]);
            }
        }
    }
}

void getStudents(int count) {
    for (int i = 0; i < count; i++) {
        string tempName;
        cout << "Enter student name: " << endl;
        getline(cin, tempName);
        names[i] = tempName;
    }
}