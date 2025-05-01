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
vector<unordered_map<int, int> > create_employee_map(int N, vector<vector<int> > &employee_preferences)
{
    vector<unordered_map<int, int> > employee_rankings(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            employee_rankings[i][employee_preferences[i][j] - 1] = j;
        }
    }
    return employee_rankings;
}
vector<int> matching_algorithm(int N, vector<unordered_map<int, int> > &employee_rankings, vector<vector<int> > &employer_preferences)
{
    vector<int> matches(N, -1);     // Vector for matches, empty w/ no matches @ start
    queue<int> unmatched_employers;
    for (int i = 0; i < N; i++)
        unmatched_employers.push(i);

    vector<int> proposals(N, 0);    // Tracks # of proposals each employer makes
    while (!unmatched_employers.empty())
    {
        int employer = unmatched_employers.front();
        unmatched_employers.pop();

        int employee = employer_preferences[employer][proposals[employer]] - 1;
        proposals[employer]++;
        // If the employee is free, matches
        if (matches[employee] == -1)
        {
            matches[employee] = employer;
        }

        // If the employee is matched, compare
        else
        {
            int current_match = matches[employee];
            // If the new match is better, switch
            if (employee_rankings[employee][employer] < employee_rankings[employee][current_match])
            {
                matches[employee] = employer;
                unmatched_employers.push(current_match);
            }
            // Else employee rejects
            else
            {
                unmatched_employers.push(employer);
            }
        }
    }
    return matches;
}
void printMatching(vector<int> &matches)
{
    cout << "Matching (Employer -> Employee): " << endl;
    for (int i = 0; i < matches.size(); i++)
        cout << "Employer " << i << " -> Employee " << matches[i] << endl;
    cout << endl;
}
int main()
{
    const int N = 3;

    // Braced initializer lists refused to work. This is the next best solution

    vector<int> x1; x1.push_back(1); x1.push_back(2); x1.push_back(3);
    vector<int> x2; x2.push_back(2); x2.push_back(1); x2.push_back(3);
    vector<int> x3; x3.push_back(1); x3.push_back(2); x3.push_back(3);
    vector<vector<int> > employer_preferences;
    employer_preferences.push_back(x1);
    employer_preferences.push_back(x2);
    employer_preferences.push_back(x3);

    vector<int> y1; y1.push_back(2); y1.push_back(1); y1.push_back(3);
    vector<int> y2; y2.push_back(1); y2.push_back(2); y2.push_back(3);
    vector<int> y3; y3.push_back(1); y3.push_back(2); y3.push_back(3);
    vector<vector<int> > employee_preferences;
    employee_preferences.push_back(y1);
    employee_preferences.push_back(y2);
    employee_preferences.push_back(y3);

    vector<unordered_map<int, int> > employee_rankings = create_employee_map(N, employee_preferences);
    vector<int> matches = matching_algorithm(N, employee_rankings, employer_preferences);
    printMatching(matches);

    return 0;
}