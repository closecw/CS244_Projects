/**
* Program to evaluate a postfix math string
 * @author Carter Close
 * @version 1.0
 */
#include <iostream>
#include <stack>
using namespace std;

/**
 * Function for the evaluation, uses a stack to keep track of operands
 * @param s the input string to be evaluated
 * @return the top of the stack, which will be the final result after evaluation
 */
int evaluateString (string s) {
    stack <int> st;
    string num;
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        char x = s[i];
        //Handles digits
        if (isdigit(x))
        {
            num += x;
            flag = true;
        }
        //Handles spaces if they were preceded by at least one digit
        else if (x == ' ' && flag)
        {
            int y = stoi(num);
            st.push(y);
            num = "";
            flag = false;
        }
        //Handles spaces after operations
        else if (x == ' '){}
        //Handles operations
        else if (x == '+' || x == '*')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (s[i] == '+')
                st.push(a + b);
            else if (s[i] == '*')
                st.push(a * b);
        }
        //Handles bad input
        else
        {
            cout << "Bad input, terminating program." << endl;
            break;
        }
    }
    return st.top();
}

/**
 * Main method, defines the string and calls {@link evaluateString()} to evaluate the string
 * @return end program
 */
int main()
{
    string s;
    cout << "Enter a postfix equation:" << endl;
    getline(cin, s);
    while (s[0] != 'q')
    {
        cout << "Result: " << evaluateString(s) << endl;
        getline(cin, s);
    }

    return 0;
}