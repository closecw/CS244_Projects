/**
* Program for a 0/1 Knapsack, also known as a Whole Knapsack
 * Classic DSA problem
 * @author Carter Close
 * @version 1.0
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * Function for the knapsack itself
 * Creates an n+1 size table to iterate through
 * @param W Weight of the knapsack (total capacity)
 * @param value Vector that holds values of each Item object
 * @param weight Vector that holds weights of each Item object
 * @return Table index that has the best value while still maxing out the weight
 */
int wholeKnapsack(int W, vector<int> &value, vector<int> &weight)
{
    int n = weight.size();
    // Creating the table that compares value to weight
    vector<vector<int> > table(n + 1, vector<int>(W + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else
            {
                int choice = 0;
                // Choosing the item based on "what do I gain now?"
                if (weight[i - 1] <= j)
                {
                    choice = value[i - 1] + table[i - 1][j - weight[i - 1]];
                }

                // Not choosing the item based on "what can I gain later?"
                int notChoice = table[i - 1][j];
                // Comparison of the two, whichever is greater is the better choice
                table[i][j] = max(choice, notChoice);
            }
        }
    }
    return table[n][W];
}

int main()
{
    vector<int> value;
    value.push_back(3);
    value.push_back(5);
    value.push_back(6);
    vector<int> weight;
    weight.push_back(1);
    weight.push_back(2);
    weight.push_back(3);
    int W = 4;
    cout << "Best value: " << wholeKnapsack(W, value, weight) << endl;

    return 0;
}