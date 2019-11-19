#include <bits/stdc++.h>
using namespace std;
void program(); int main() {cin.sync_with_stdio(0); cin.tie(0); program();}
#define int long long
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>


int a[2];
void program(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        a[0] = a[1] = 0;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            a[t&1]++;
        }
        int res = 0;
        int m;
        cin >> m;
        for(int i=0;i<m;i++){
            int t;
            cin>>t;
            res += a[t&1];
        }
        cout << res << endl;
    }
}

/*
WA:
-bounds on loops
-truncating
-intialization
-0 vs 1 indexing

TLE:
-might need unordered_set/map
-infinite while loop

Stuck:
-different perspective?
-bruteforce?
-greedy?
-reduce dimensionality with problem contraints?
*/
