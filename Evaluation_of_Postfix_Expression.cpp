/*
Problem Statement:
------------------
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include 
the basic arithmetic operators like *, /, + and -.

Example 1:
---------
Input: S = "231*+9-"
Output: -4
Explanation: After solving the given expression, we have -4 as result.

Example 2:
---------
Input: S = "123+*8-"
Output: -3
Explanation: After solving the given postfix expression, we have -3 as result.

Your Task: You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression 
as input parameter and returns the evaluated value.

Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)
*/

// Link --> https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

// Code:
class Solution
{
public:
    int evaluatePostfix(string exp)
    {
        stack <int> s;
        
        for(int i=0 ; i<exp.length() ; i++)
        {
            if(exp[i] >= '0' and exp[i] <= '9')
                s.push(exp[i]-'0');
        
            else
            {
                int operator2 = s.top();
                s.pop();
                
                int operator1 = s.top();
                s.pop();
                
                switch(exp[i])
                {
                    case '+':
                        s.push(operator1 + operator2);
                        break;
                    
                    case '-':
                        s.push(operator1 - operator2);
                        break;
                        
                    case '*':
                        s.push(operator1 * operator2);
                        break;
                        
                    case '/':
                        s.push(operator1 / operator2);
                        break;
                        
                    case '^':
                        s.push(pow(operator1 , operator2));
                        break;
                }
            }
        }
        return s.top();
    }
};


