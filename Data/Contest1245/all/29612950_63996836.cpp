#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;



int main(){
    int t, a, b; cin>>t;
    while(t--){
        cin>>a>>b;
        if(__gcd(a, b) == 1)
            puts("Finite");
        else
            puts("Infinite");
    }
	return 0;
}
