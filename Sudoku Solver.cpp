#include <bits/stdc++.h>
using namespace std;

void printSudoku(vector<vector<int>> &sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool optionAvail(vector<vector<int>> &sudoku, int r, int c, int po)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[r][i] == po)
        {
            return false;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        if (sudoku[j][c] == po)
        {
            return false;
        }
    }

    int subr = 3 * (r / 3);
    int subc = 3 * (c / 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[subr + i][subc + j] == po)
            {
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku, int rownum, int colnum)
{
    if (rownum == sudoku.size())
    {
        printSudoku(sudoku);
        return;
    }

    int nc = 0;
    int nr = 0;

    if (colnum == sudoku[0].size() - 1)
    {
        nr = rownum + 1;
        nc = 0;
    }
    else
    {
        nr = rownum;
        nc = colnum + 1;
    }

    if (sudoku[rownum][colnum] != 0)
    {
        solveSudoku(sudoku, nr, nc);
    }

    else
    {
        for (int po = 1; po <= 9; po++)
        {
            if (optionAvail(sudoku, rownum, colnum, po))
            {
                sudoku[rownum][colnum] = po;
                solveSudoku(sudoku, nr, nc);
                sudoku[rownum][colnum] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> sudoku(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    // vector<vector<int>> sudoku =
    // {
    //     {3, 0, 6, 5, 0, 8, 4, 0, 0},
    //     {5, 2, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 8, 7, 0, 0, 0, 0, 3, 1},
    //     {0, 0, 3, 0, 1, 0, 0, 8, 0},
    //     {9, 0, 0, 8, 6, 3, 0, 0, 5},
    //     {0, 5, 0, 0, 9, 0, 6, 0, 0},
    //     {1, 3, 0, 0, 0, 0, 2, 5, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 7, 4},
    //     {0, 0, 5, 2, 0, 6, 3, 0, 0}
    // };
    cout << endl
         << endl;
    solveSudoku(sudoku, 0, 0);

    return 0;
}