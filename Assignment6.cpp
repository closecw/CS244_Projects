/**
* Program for bin sorting, a classic DSA problem
 * Uses both the FirstFit approach and the NextFit approach
 * @auathor Carter Close
 * @version 1.0
 */
#include <iostream>
using namespace std;

/**
 * Function for determining bin sorting using the NextFit approach
 * NextFit will fit an item into the next possible bin
 * @param weight Array for the weights of items
 * @param n Size of the weight array
 * @param c Weight remaining
 * @return Number of bins required to sort every item
 */
int nextFit(int weight[], int n, int c)
{
    int res = 1;
    int bin_rem = c;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] > bin_rem) // If the item can't fit in the current bin
        {
            res++; // Use a new bin
            bin_rem = c - weight[i];
        }
        else bin_rem -= weight[i];
    }
    return res;
}

/**
 * Function for determining bin sorting using the FirstFit approach
 * FirstFit will fit an item into the first bin if it can
 * @param weight Array for the weights of items
 * @param n Size of the weight array
 * @param c Weight remaining
 * @return Number of bins required to sort every item
 */
int firstFit(int weight[], int n, int c)
{
    int res = 0;
    int bin_rem[10];
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < res; j++)
        {
            if (bin_rem[j] >= weight[i])
            {
                bin_rem[j] -= weight[i];
                break;
            }
        }
        if (j == res)
        {
            bin_rem[j] = c - weight[i];
            res++;      // Use a new bin
        }
    }
    return res;
}

int main()
{
    int weight[] = { 2, 5, 4, 7, 1, 3, 8 };
    int n = sizeof(weight) / sizeof(weight[0]);
    int c = 10; // Max weight, which turns into remaining weight once it gets changed
    cout << "Number of bins required for NextFit: " << nextFit(weight, n, c) << endl;
    cout << "Number of bins required for FirstFit: " << firstFit(weight, n, c) << endl;

    return 0;
}