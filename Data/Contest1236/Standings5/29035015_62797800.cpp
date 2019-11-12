#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e3;
int arr[N][N];
signed main() {
    int n;
    cin>>n;
    for(int i = n; i > 0; i--)
    {
        for(int j = 0; j < n; j++)
        {
            if(i % 2 == 0)
                arr[i - 1][j] = i * n - j;
            else
                arr[i - 1][n - j - 1] = i * n - j;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<arr[j][i]<<" ";
        cout<<endl;
    }

}