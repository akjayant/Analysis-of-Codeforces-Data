#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll  n;
vector<ll>v;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n) {
        v.clear();
        ll m=n;
        for (ll i = 2; i * i <= n; i++) {
            while (n % i == 0){
                n/=i;
                v.emplace_back(i);
            }
        }
        if(n!=1)v.emplace_back(n);
        if (int(v.size()) == 0) {
            cout << m << endl;
            continue;
        }
        if(v[0]!=*(v.end()-1)){
            cout<<1<<endl;
            continue;
        }
        cout<<v[0]<<endl;
    }
    return 0;
}
/*
 4
 5
 */