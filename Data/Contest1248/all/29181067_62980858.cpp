/*
g++ -std=c++11 code.cpp; cat inp.txt | ./a.out
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        ll fo=0,fe=0;
        for(int i=0; i<n; i++) {
            int x; cin >> x;
            if (x&1) fo++; else fe++;
        }

        cin >> n;
        ll so=0,se=0;
        for(int i=0; i<n; i++) {
            int x; cin >> x;
            if (x&1) so++; else se++;
        }

        cout << fo*so+fe*se << endl;
    }
}