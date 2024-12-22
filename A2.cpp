#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascalTriangle(int numRows)
{
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i)
    {
        vector<int> row(i + 1, 1); // Create a row with all elements initialized to 1

        // Calculate the values for the middle elements
        for (int j = 1; j < i; ++j)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        // Add the row to the triangle
        triangle.push_back(row);
    }

    return triangle;
}

void printPascalTriangle(const vector<vector<int>> &triangle)
{
    for (const auto &row : triangle)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numRows = 5; // Change this to generate a different number of rows
    vector<vector<int>> pascalTriangle = generatePascalTriangle(numRows);

    cout << "Pascal's Triangle:" << endl;
    printPascalTriangle(pascalTriangle);

    return 0;
}
