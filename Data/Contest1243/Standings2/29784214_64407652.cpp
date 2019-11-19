// Siddhant Gautam
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long ll
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define bitcount __builtin_popcountll
#define INF 1e18+9
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define FIO ios_base::sync_with_stdio(false)
#define mod 1000000007
ll power(ll a,ll b,ll m)
{
    a%=m;
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret=((ret%m)*(a%m))%m;
        a=((a%m)*(a%m))%m;
        b>>=1;
    }
    return ret;
}

int main()
{
    FIO;
    
    map < ll,ll > m;   

    ll n;
    cin >> n;

    for(ll i=2;i*i<=n;i++){
        if(n%i == 0){
            int ct = 0;
            while(n%i == 0){
                n /= i;
                ct++;
            }
            m[i] = ct;
        }
    }

    if(n > 1) m[n] = 1;

    if(m.size() == 1){
        cout << (m.begin())->ff << endl;
    }
    else{
        cout << 1 << endl;
    }
    return 0;
}