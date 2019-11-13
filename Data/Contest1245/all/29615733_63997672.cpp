#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mll map<ll, ll>
#define mii map<in, int>
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define p push
using namespace std;
 

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    int t;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        if(__gcd(a, b) == 1) {
            cout<<"Finite\n";
        } else {
            cout<<"Infinite\n";
        }
    }
}
//