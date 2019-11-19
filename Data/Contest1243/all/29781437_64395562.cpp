#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, ans; scanf("%lld", &n);
    bool flag = false;
    for(int i = 2; 1ll * i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            ans = i;
            flag = true;
            break;
        }
    }
    if(!flag) ans = n;
    else if(n != 1) ans = 1;
    printf("%lld", ans);
}