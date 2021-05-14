/*
Example:
--------
1XY2 is a valid shuffle of XY and 12
Y12X is not a valid shuffle of XY and 12
*/

#include <bits/stdc++.h>
using namespace std;

int shuffleString(string s1 , string s2 , string res)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = res.length();

    // i --> first string ; j --> second string ; k --> third string
    int i=0 , j=0 , k=0;
    bool flag = true;

    if(l1+l2 != l3)
        return 0;

    else
    {
        while(k < l3)
        {
            if(s1[i] == res[k])
            {
                i++;
                k++;
            }
            else if(s2[j] == res[k])
            {
                j++;
                k++;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }

    if(flag == true)
        return 1;
    else
        return 0;
}

int main()
{
    string s1,s2,res;

    cout<<"Enter the first string : ";
    cin>>s1;

    cout<<"Enter the second string : ";
    cin>>s2;

    cout<<"Enter the resultant string : ";
    cin>>res;

    if(shuffleString(s1 , s2 , res))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}

