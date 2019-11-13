#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, cur;
vector<int> v[N];

int main(){


    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cur = 1;
    for (int i = 1; i <= n * n; ++i){
        if (cur){
            for (int j = 1; j <= n; ++j){
                v[j].push_back(i);
                ++i;
            }
            --i;
        }
        else{
            for (int j = n; j >= 1; --j){
                v[j].push_back(i);
                ++i;
            }
            --i;
        }
        cur ^= 1;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) cout << v[i][j - 1] << ' ';
        cout << '\n';
    }


}
