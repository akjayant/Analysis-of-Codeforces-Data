#include<bits/stdc++.h>
using namespace std;
const int N = 100;
typedef long long ll;
typedef pair<int, int> pii;
ll n;
vector<ll> ve;
int main() {
    scanf("%lld", &n);
    ll nn = n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ve.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ve.push_back(n);
    if(ve.size() > 1) printf("1\n");
    else if(ve.size() == 1) printf("%lld\n", ve[0]);
    else printf("%lld\n", nn);
    return 0;
}
