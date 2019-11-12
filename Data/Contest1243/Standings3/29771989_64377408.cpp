#include <bits/stdc++.h>

#define ll long long
#define MAX 300005
#define pp pair<ll, pair<ll, ll>>
#define pb push_back
#define mod 1000000007

using namespace std;

ll power(ll x, ll y);

ll gcd(ll a, ll b);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int count=0;
        for(int i=0;i<n;i++) if(s1[i]!=s2[i]) count++;
        if(count!=2) cout<<"No\n";
        else {
            int idx1=-1,idx2=-1;
            for(int i=0;i<n;i++){
                if(s1[i]!=s2[i]){
                    if(idx1==-1) idx1=i;
                    else idx2=i;
                }
            }
            if(s1[idx1]==s1[idx2] && s2[idx1]==s2[idx2]) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}

ll power(ll x, ll y) {
    ll res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
