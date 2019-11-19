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


void program(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int T = 0;
    for(int i=0;i<n;i++) T += a[i];
    sort(all(a));

    int V = 0;
    for(int i=0;i<n/2;i++) V += a[i];
    int H = T-V;
    cout << V*V + H*H << endl;
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
