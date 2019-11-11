#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define maxn 100005
#define pb push_back

using namespace std;

ll mul(ll x, ll y){
    ll res = (x%mod * y%mod)%mod;
    return res;
}

ll add(ll x, ll y){
    ll res = (x%mod + y%mod)%mod;
    return res;
}

ll fib[1000006];

int main()
{
    fib[1] = 1;
    fib[2] = 2;
    for(int i=3;i<=200000;i++){
        fib[i] = add(fib[i-1], fib[i-2]);
    }
    ll n, res = 1;
    string s;
    cin >> s;
    s += '?';
    n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == 'm' || s[i] == 'w') res = 0;
    }
    ll cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'u') cnt++;
        else{
            if(cnt){
                res = mul(res, fib[cnt]);
                cnt  = 0;
            }

        }
    }
    cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'n') cnt++;
        else{
            if(cnt){
                //cout << cnt << endl;
                res = mul(res, fib[cnt]);
                cnt  = 0;
            }
        }
    }
    cout << res << endl;
    return 0;
}
