#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;  
typedef pair<int,int> ii;  
typedef vector<ii> vii;  
typedef list<int> li;  
typedef unordered_map<int,int> mii;

#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)  
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rap(i,a,n) for (int i = a; i < (n); i++) 
#define rrap(i,n,a) for (int i = (n)-1; i >= a; i--) 

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t,a,b;
    cin >> t;
    rep(tt,t) {
        cin >> a >> b;
        a = gcd(a,b);
        if (a==1) {
            cout << "Finite\n";
        }
        else cout << "Infinite\n";
    }
    return 0;

    //compile: g++ -std=c++14 -O2 -Wall NAME.cpp -o NAME
}