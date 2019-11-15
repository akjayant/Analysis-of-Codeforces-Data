#include<bits/stdc++.h>

#define ll long long
using namespace std;
const ll N = 2e5 + 5;

vector < int > g[305];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n;
    deque < int > dq;
    for(int i = 1 ;i <= n * n ;i++){
        dq.push_back(i);
    }
    for(int j = 1 ; j <= n ; j++) {
        for (int i = 1; i <= n; i++) {
            if (j & 1){
                g[i].push_back(dq.front());
                dq.pop_front();
            }
            else {
                g[i].push_back(dq.back());
                dq.pop_back();
            }
        }
    }
    for(int i = 1 ;i <= n ; i++){
        for(auto it : g[i])
            cout << it <<' ' ;
        cout << "\n";
    }
    return 0;
}