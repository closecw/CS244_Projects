/**
 * Stable Matching project
 * Uses the Gale-Shapley algorithm to find stable matches of employers -> employees
 * This solution is an N x N matching (same number of employers and employees)
 * @author Carter Close
 * @version 1.0
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<unordered_map<int, int> > create_map(int N, vector<vector<int> > &employee_preferences)
{
    vector<unordered_map<int, int> > employer_rankings(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            employer_rankings[i][employee_preferences[i][j]] = j;
        }
    }
    return employer_rankings;
}
vector<int> matching_algorithm(int N, vector<unordered_map<int, int> > &employer_rankings, vector<vector<int> > &employer_preferences)
{

}
void printMatching(vector<int> &matches)
{
    cout << "Matching (Employer -> Employee): " << endl;
    for (int i : matches)
        cout << "Employer " << i << " -> Employee " << matches[i] << endl;
    cout << endl;
}
int main()
{
    const int N = 3;
    vector<vector<int> > employer_preferences = {
        {1, 2, 3},
        {2, 1, 3},
        {1, 2, 3} };

    vector<vector<int> > employee_preferences = {
        {2, 1, 3},
        {1, 2, 3},
        {1, 2, 3} };

    return 0;
}