#include <iostream>
using namespace std;

const int SIZE = 9;

void printWelcome() {
    cout << "=======================================\n";
    cout << "         SUDOKU SOLVER PROJECT\n";
    cout << "=======================================\n";
    cout << "Enter the Sudoku puzzle.\n";
    cout << "Use 0 for empty cells.\n\n";
}

void printGrid(int grid[SIZE][SIZE]) {
    cout << "\n+-------+-------+-------+\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "| ";
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0)
            cout << "+-------+-------+-------+\n";
    }
}

int countEmptyCells(int grid[SIZE][SIZE]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (grid[i][j] == 0)
                count++;
    return count;
}

bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {

    for (int x = 0; x < SIZE; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x < SIZE; x++)
        if (grid[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[SIZE][SIZE]) {

    int row = -1;
    int col = -1;
    bool found = false;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        return true;

    for (int num = 1; num <= 9; num++) {

        if (isSafe(grid, row, col, num)) {

            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    char choice;
    do {

        int grid[SIZE][SIZE];
        printWelcome();
        cout << "Enter 81 numbers:\n";
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cin >> grid[i][j];
                while (grid[i][j] < 0 || grid[i][j] > 9) {
                    cout << "Invalid input! Enter value between 0 and 9: ";
                    cin >> grid[i][j];
                }
            }
        }

        cout << "\nEmpty Cells : " << countEmptyCells(grid) << endl;
        cout << "\nSolving Sudoku...\n";

        if (solveSudoku(grid)) {
            cout << "\nSudoku Solved Successfully!\n";
            printGrid(grid);
        } else {
            cout << "\nNo Solution Exists for the given Sudoku.\n";
        }
        cout << "\nDo you want to solve another Sudoku? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you for using Sudoku Solver!\n";

    return 0;
}