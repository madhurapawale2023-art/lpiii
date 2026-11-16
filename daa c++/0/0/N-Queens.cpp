#include <iostream>
#include <cstdlib>
using namespace std;

char b[20][20];
int n;

bool safe(int r,int c) {
    for(int i=0;i<r;i++)
        if(b[i][c]=='Q') return false;
    for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
        if(b[i][j]=='Q') return false;
    for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++)
        if(b[i][j]=='Q') return false;
    return true;
}

bool solve(int r) {
    if(r==n) return true;
    for(int c=0;c<n;c++)
        if(safe(r,c)) {
            b[r][c]='Q';
            if(solve(r+1)) return true;
            b[r][c]='.';
        }
    return false;
}

int main() {
    cout<<"Enter N: "; cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) b[i][j]='.';
    if(solve(0))
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<b[i][j]<<" ";
            cout<<endl;
        }
    else cout<<"No Solution";
}
//ouput:Enter N: 4

//. Q . .
//. . . Q
//Q . . .
//. . Q .