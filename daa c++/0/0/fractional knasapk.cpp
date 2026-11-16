//Write a C++ program to solve the Fractional Knapsack problem using the Greedy Method to maximize the total profit.
#include <iostream>
using namespace std;

int main() {
    int n, w[20], p[20], cap;
    float total = 0;
    cout << "Enter items: ";
    cin >> n;
    for(int i=0;i<n;i++) {
        cout << "Weight and Profit: ";
        cin >> w[i] >> p[i];
    }
    cout << "Enter capacity: ";
    cin >> cap;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if((float)p[i]/w[i] < (float)p[j]/w[j]) {
                swap(w[i],w[j]); swap(p[i],p[j]);
            }
    for(int i=0;i<n && cap>0;i++) {
        int take = min(w[i],cap);
        total += (float)take*p[i]/w[i];
        cap -= take;
    }
    cout << "Maximum Profit = " << total;
    return 0;
}
//output:Enter items: 3
//Enter items: 3
//Weight and Profit: 10 60
//Weight and Profit: 20 100
//Weight and Profit: 30 120
//Enter capacity: 50
//Maximum Profit = 240