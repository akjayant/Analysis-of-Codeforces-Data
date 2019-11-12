#include <bits/stdc++.h>

using namespace std;

int grid[305][305];

int main()
{
    int n;
    scanf("%d", &n);
    int num = 1;
    for(int col=1; col<=n; col++){
        if(col%2 == 1){
            for(int row=1; row<=n; row++){
                grid[row][col] = num++;
            }
        }
        else {
            for(int row=n; row>=1; row--){
                grid[row][col] = num++;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout << grid[i][j] << " ";
        cout << endl;
    }
}