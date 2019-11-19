#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v;

int main() {
    LL n;
    scanf("%lld", &n);
    LL rt = sqrt(n);
    LL t = n;
    for(LL i = 2; i <= rt; ++i) {
        if(t % i == 0) {
            v.push_back(i);
            while(t % i == 0) t /= i;
        }
    }
    if(!v.size() ) printf("%lld\n", n);
    else if(v.size() == 1) {
        while(n % v[0] == 0 && n) n /= v[0];
        if(n == 1) printf("%lld\n", v[0]);
        else printf("1\n");
    }
    else printf("1\n");
    return 0;
}

