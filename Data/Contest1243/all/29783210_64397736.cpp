#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 5;

vector<ll> d;

void divs(ll n) {
    d.clear();
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            d.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) d.push_back(n);
}

int main() {
    ll n;
    scanf("%lld", &n);
    divs(n);

    if(d.size() == 1) {
        if(*d.begin() != n) printf("%lld\n", *d.begin());
        else printf("%lld\n", n);
    }
    else {
        printf("1\n");
    }
    return 0;
}
