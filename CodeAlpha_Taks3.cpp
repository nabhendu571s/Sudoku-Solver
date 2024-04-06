#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;
const int n = 9;
bool findEmptyLocation(int v[n][n], int &r, int &c) {
    for (r= 0; r < n; r++) {
        for (c= 0; c< n; c++) {
            if (v[r][c] == 0) {
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int v[n][n], int r, int c, int num) {
    for (int i = 0; i < n; i++) {
        if (v[r][i] == num || v[i][c] == num) {
            return false;
        }
    }
    int startRow = r - r % 3;
    int startCol = c- c % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int v[n][n]) {
    int r, c;
    if (!findEmptyLocation(v, r, c)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(v, r, c, num)) {
            v[r][c] = num;
            if (solveSudoku(v)) {
                return true;
            }
            v[r][c] = 0;
        }
    }
    return false;
}
void printBoard(int v[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout <<v[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int v[n][n] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    if (solveSudoku(v)) {
        cout << "Sudoku solved:\n";
        printBoard(v);
    } else {
        cout << "No solution exists!\n";
    }
    return 0;
}
