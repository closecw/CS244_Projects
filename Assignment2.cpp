/**
* Program for a Fractional Knapsack, a classic DSA problem
 * @author Carter Close
 * @version 1.0
 */
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Struct for an item of the knapsack
 * Assigns its weight and profit respectively
 */
struct Item
{
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

/**
 * Compares two Item objects
 * @param a First item in the comparison
 * @param b Second item in the comparison
 * @return True if a > b, false if b > a
 */
bool cmp(Item a, Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return (r1 > r2);
}

/**
 *
 * @param W Weight of the knapsack (allowed capacity)
 * @param arr Array of possible items to take
 * @param N Size of the array
 * @return Final profit after taking fractional items in the knapsack
 */
double fractionalKnapsack(int W, Item arr[], int N)
{
    sort(arr, arr + N, cmp);  //first address, last address (start to end), cmp is comparison
    double finalProfit = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].weight <= W)  //Take the full item
        {
            W -= arr[i].weight;
            finalProfit += arr[i].profit;
        }
        else
        {
            finalProfit += arr[i].profit * ((double)W / (double)arr[i].weight);  //Take fractional if we can't take full
        }
    }
    return finalProfit;
}

int main()
{
    int W = 50;
    Item arr[] = { Item(60, 10), Item(100, 20), Item(120, 30) };
    int N = sizeof(arr) / sizeof(Item);
    double x = fractionalKnapsack(W, arr, N);
    cout << x << endl;
    return 0;
}