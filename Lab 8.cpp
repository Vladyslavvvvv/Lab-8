#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int rows, cols, minValue, maxValue;

    cout << "Enter the number of rows of the matrix: ";
    cin >> rows;

    cout << "Enter the number of matrix columns: ";
    cin >> cols;

    cout << "Enter the minimum value for the matrix elements: ";
    cin >> minValue;

    cout << "Enter the maximum value for the matrix elements: ";
    cin >> maxValue;

    // Initialize the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Declaration and initialization of a matrix with random values
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % (maxValue - minValue + 1) + minValue;
        }
    }

    // Derivation of the matrix
    cout << "Generated matrix:\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << '\t';
        }
        cout << '\n';
    }

    // Counting the number of elements equal to zero
    int zeroCount = 0;

    for (auto&row : matrix) {
        zeroCount += count(row.begin(), row.end(), 0);
    }

    cout << "The number of elements that are zero: " << zeroCount << endl;

    return 0;
}