#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef long long int ll;
typedef pair<int,int> pi;
typedef unsigned long long int ull;

ll lsone(ll p){return(p & -p);}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    std::ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s;
    cin >> s;
    ll ans,ns, us, divi;
    ll fib[100010];
    fib[0] = 1;
    fib[1] = 1;
    divi = 1e9+7;
    for (int i = 2;i < 100005;i++){
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] = fib[i] % divi;
    }
    s = s + "a";
    int n = s.size();
    ans = 1;
    us = 0;
    ns = 0;
    for (int i=0;i<n;i++){
        if (s[i] == 'm' || s[i] == 'w'){
            ans *= 0;
        }
        else{
            if (s[i] != 'u'){
                ans = ans * fib[us] % divi;
                us = 0;
            }
            if (s[i] != 'n'){
                ans = ans * fib[ns] % divi;
                ns = 0;
            }
            if (s[i] == 'u'){
                us += 1;
            }
            if (s[i] == 'n'){
                ns += 1;
            }
        }
    }
    cout << ans;
}
