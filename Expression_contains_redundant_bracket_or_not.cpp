/*
Problem Statement:
-----------------
Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if same sub-expression is 
surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.
Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.

Example: 
-------
Input: 
((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No

Explanation:
1. ((a+b)) can reduced to (a+b), this Redundant
2. (a+(b)/c) can reduced to (a+b/c) because b is
surrounded by () which is redundant.
3. (a+b*(c-d)) doesn't have any redundant or multiple
brackets.
*/

// Link --> https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/

// Code:
#include <bits/stdc++.h>
using namespace std;

bool checkRedundancy(string &str)
{
    stack<char> s;
    int counter = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ')')
            s.push(str[i]);
        else
        {
            // If we found an opening bracket just after closing one.
            // Then the bracket pair had no content. Hence, redundant.
            if(s.top() == '(')    
                return true;
            
            else
            {
                while(s.top() != '(')
                {
                    s.pop();
                    counter++;
                }
                s.pop();    // Removing the opening bracket.

                // This basically means that bracket is around an single element only. 
                if(counter <= 1)
                    return true;
            }
        }
    }
    return false;
}

void findRedundant(string &str)
{
    bool answer = checkRedundancy(str);
    if (answer == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    string str = "((a+b))";
    findRedundant(str);

    str = "(a+(b)/c)";
    findRedundant(str);

    str = "(a+b*(c-d))";
    findRedundant(str);

    return 0;
}
