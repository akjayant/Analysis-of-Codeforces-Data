#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 
#define ll long long 
#define N 305
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define piii pair<int, pii>
#define print(x) cout << #x << "=" << x << "\t";
#define endl "\n"
#define newline cout << endl;

int n;
vector<vector<int>> grid;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    cin >> n;
    grid.resize(n, vector<int>(n, 0));
    int m = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            grid[i][j] = m++;
    for(int i = 0; i < n; i++)
        if (i & 1)
            reverse(grid[i].begin(), grid[i].end());

    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    return 0;
}
