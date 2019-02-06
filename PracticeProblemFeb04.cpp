//============================================================================
// Name        : PracticeProblemFeb04.cpp
// Author      : R. Bruce Tuckey    CS2363-TS02S
// Version     :
// Copyright   : Dr. Goulden         Mon 5:30-8:00
// Description : Practice Problem from Lecture specs below.
//
//• display a friendly greeting to the user
//• prompt the user for the number of rows and columns in a 2-dimensional array
//• accept those values
//• create the array
//• populate the array by initializing each element with the sum of its row and column index
//• display the array using a user-written function
//• create a new array that is larger by two rows and two columns
//• zero every element in the new array
//• copy the old array into the new (some elements will still be zero)
//• deallocate the old array
//• associate the name of the old array with the new array
//• display the array by invoking the same function as before
//============================================================================

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


void zeroTable(int * * theTable, int numRows, int numCols) {
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			theTable[r][c] = 0;
		}
	}
}

void copyTable(int * * sourceTable, int * * destTable, int srcRows, int srcCols) {
	for (int x = 0; x < srcRows; x++) {
		for (int y = 0; y < srcCols; y++) {
			destTable[x][y] = sourceTable[x][y];
		}
	}
}

void displayTable(int * * theTable, int numRows, int numCols) {
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			cout << setw(4) << theTable[r][c];
		}
		cout << endl;
	}
	cout << endl;
}

void initializeTable(int * * theTable, int numRows, int numCols) {
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			theTable[r][c] = r + c;
		}
	}
}

int main() {

	int numRows = -1;	// initialize to setup while input
	int numCols = -1;	// initialize to setup while input
	int newRows;		// rows for second table
	int newCols;		// columns for second table

	srand((unsigned)time(0));

	cout << "Welcome to the wonderful world of two dimensional arrays" << endl;
	while (numCols < 0) {
		cout << "Please enter preferred number of columns: ";
		cin >> numCols;
	}
	while (numRows < 0) {
		cout << "Please enter preferred number of rows: ";
		cin >> numRows;
	}


	int * * theTable = new int *[numRows];			// make a table with the numbers as in desc
	for (int r = 0; r < numRows; r++) {
		theTable[r] = new int[numCols];
	}

	initializeTable(theTable, numRows, numCols);	// make the array hold the numbers we want
	displayTable(theTable, numRows, numCols);		// display the array

	newRows = numRows + 2;							// set new rows to two more than before
	newCols = numCols + 2;							// set new columns to two more than before

	int * * myTable = new int *[newRows];			// make a new table (maybe oak this time)
	for (int r = 0; r<newRows; r++) {
		myTable[r] = new int[newCols];
	}

	zeroTable(myTable, newRows, newCols);			// fill new table with zeros
	//displayTable(myTable, newRows, newCols);
	copyTable(theTable, myTable, numRows, numCols);	// copy old table into new table

	for (int x = 0; x < numRows; x++) {				// delete the old table
		delete[] theTable[x];						// each row at a time
	}
	delete[] theTable;								// and finally delete the col

	theTable = myTable;								// make the old table new again

	displayTable(theTable, newRows, newCols);		// display the new table under the old name with new size

	return 0;
}