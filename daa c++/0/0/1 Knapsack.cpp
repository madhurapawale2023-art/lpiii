//Write a C++ program to solve the 0/1 Knapsack problem using Dynamic Programming to maximize the total profit.
#include <iostream>
using namespace std;

int main() {
    int n, w[20], p[20], cap, dp[20][100]={0};
    cout << "Enter number of items: ";
    cin >> n;
    for(int i=1;i<=n;i++) {
        cout << "Enter weight and profit: ";
        cin >> w[i] >> p[i];
    }
    cout << "Enter capacity: ";
    cin >> cap;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=cap;j++)
            dp[i][j]=(w[i]<=j) ? max(dp[i-1][j],p[i]+dp[i-1][j-w[i]]) : dp[i-1][j];
    cout << "Maximum Profit = " << dp[n][cap];
    return 0;
}
//output:Enter number of items: 3
//Enter weight and profit: 10 60
//Enter weight and profit: 20 100
//Enter weight and profit: 30 120
//Enter capacity: 50
//Maximum Profit = 220