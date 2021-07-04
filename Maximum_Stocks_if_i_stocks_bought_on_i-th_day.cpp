/*
Problem Statement:
-----------------
In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day. 
There is a rule that a customer can buy at most i stock on the ith day. If the customer has an amount of k amount of money initially,
find out the maximum number of stocks a customer can buy. 
For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 
2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.

Examples:
--------
Input : price[] = { 10, 7, 19 }, 
              k = 45.
Output : 4
A customer purchases 1 stock on day 1, 2 stocks on day 2 and 1 stock on day 3 for 10, 7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number of stocks purchased is 4.

Input  : price[] = { 7, 10, 4 }, 
               k = 100.
Output : 6
*/

// Link --> https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/

// Code: 
#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int money, int price[])
{
    if (price[0] > money)
        return 0;

    int currentPrice = price[0];
    int stocks = 1;

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < i + 1)
        {
            if (currentPrice + price[i] <= money)
            {
                stocks++;
                currentPrice += price[i];
                j++;
            }
        }
    }

    return stocks;
}

int main()
{
    int price[] = {4, 8, 8, 2};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 65;

    cout << "Maximum stocks can be bought is : " << buyMaximumProducts(n, k, price) << endl;

    return 0;
}
