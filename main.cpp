/**
 * @file main.cpp
 * @author George Paulino (github.com/GeorgePaulino)
 * @brief A code to generate Triangle of Pascal with a given rows number.
 * @version 1.0
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<list>
#include<vector>

using namespace std;

/**
 * @brief Calculates a binomial number.
 * 
 * @param r Number above.
 * @param c Number below.
 * @return Binomial.
 */
int Binomial(int r, int c);

/**
 * @brief Calculates the Factorial of a given number.
 * 
 * @param n Number.
 * @return Factorial.
 */
unsigned long long int Factorial(int n);

int main()
{
    /* LightMode
     * If true the program uses the last row as base to calculates the next row.
     * Else the program calculates the binomial number to get the row.
     */
    bool light_mode = true;

    cout << "\n";

    // Rows - Determines the number of rows.
    int rows;
    cout << "Number of Rows: ";
    cin >> rows;
    cout << endl;

    // Pascal - Variable to store the Pascal Triangle
    std::vector<std::list<unsigned long long int>> pascal(0);
    // columns - Stores the number of columns in the current row.
    int columns;
    
    cout << "\n";

    for(int current_row = 0; current_row < rows; current_row++)
    {
        columns++;
        // pascal_row - stores current row.
        std::list<unsigned long long int> pascal_row;
        // last_row_it - Iterator to access the last row.
        std::list<unsigned long long int>::iterator last_row_it;
        if(current_row > 0) 
        {
            last_row_it = pascal.at(current_row - 1).begin();
        }

        for(int current_column = 0; current_column < columns; current_column++)
        {
            if(light_mode) pascal_row.push_back(Binomial(current_row, current_column));
            else
            {
                if(current_column == 0 || current_column == columns - 1) pascal_row.push_back(1);
                else
                {
                    pascal_row.push_back(*std::next(last_row_it, current_column - 1) + *std::next(last_row_it, current_column));
                }
            }
        }
        pascal.push_back(pascal_row);
    }
    for(list<unsigned long long int> x : pascal)
    {
        for(unsigned long long int y : x)
        {
            cout << y << "\t\t";
        }
        cout << "\n";
    }
    cout << "\n";
    system("pause");
}

int Binomial(int r, int c)
{
    return Factorial(r) / (Factorial(c) * Factorial(r - c));
}

unsigned long long int Factorial(int n)
{ 
    unsigned long long int f = 1;
    for(unsigned long long int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}