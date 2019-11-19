#include<cstdio>
#include<iostream>
#define ll long long

using namespace std;
ll exgcd(ll a, ll b, ll &x, ll &y){
    ll ans = a;
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        ans = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return ans;
}
ll fix_gcd(ll a, ll b, ll &x, ll & y){
    ll ans = exgcd(a, b, x, y);
    if (a * x + b * y == -1){
        x = -x;
        y = -y;
    }
    return ans;
}
int main() {
	ll n, p;
    ll a, b, x, y;
    scanf("%lld%lld%lld%lld", &n, &p, &a, &b);
    ll res = fix_gcd(a, b, x, y);
    if(!(p % res == 0)) printf("-1\n");
    else{
    	ll cnt = 0;
    	while(p % a != 0 && p >= 0){
    		p -= b;
    		cnt++;
		}
		if(p < 0){
			 printf("-1\n");
		}else{
			ll aa = p / a;
			ll sum = aa + cnt;
			if(sum > n)  printf("-1\n");
			else{
				printf("%lld %lld %lld\n", aa, cnt, n - sum);
			}
		}
	}
    return 0;
}