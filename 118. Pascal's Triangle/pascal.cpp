// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res(numRows);
    if (numRows == 0)
        return res;

    for (int i = 0; i < numRows; i++)
    {
        if (i == 0)
        {
            res[i] = {1};
        }
        if (i == 1)
        {
            res[i] = {1, 1};
        }
        if (i > 1)
        {
            vector<int> r;
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    r.push_back(1);
                    continue;
                }

                r.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            res[i] = r;
        }
    }

    return res;
}

int main(int argc, char **argv)
{
    auto res = generate(2);

    return 0;
}