// SetMatrixZeros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

namespace Solution
{
    void setZeroes(vector<vector<int> > &A)
    {
        // extra space to tag columns that will need to become zeros
        unordered_set<int> columns;

        // loop throu M x N matrix and set the rows to 0
        // as well as find the columns that should be set to 0
        for (size_t i = 0; i < A.size(); i++)
        {
            // track whether the row should be set to zero
            bool setZeroRow = false;
            for (size_t j = 0; j < A[i].size(); j++)
            {
                // track the columns that should be 0 by adding them to the unordered set
                if (A[i][j] == 0)
                {
                    columns.insert(j);
                    setZeroRow = true;
                }
            }

            // set the row to all 0 if it was tagged during the column loop
            if (setZeroRow)
            {
                for (size_t c = 0; c < A[i].size(); c++)
                {
                    A[i][c] = 0;
                }
            }
        }

        // the main loop is done, which was what decided which rows to set to zero
        // go through the unordered set and make these columns all 0
        for (auto c : columns)
        {
            for (size_t r = 0; r < A.size(); r++)
            {
                A[r][c] = 0;
            }
        }
    }
}



int main()
{
    vector<vector<int>> A{ {1,0,1}, {1,1,1}, {1,1,1} };
    Solution::setZeroes(A);

    vector<vector<int>> B{ { 0,0 },{ 1,1} };
    Solution::setZeroes(B);
    return 0;
}

