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
        vector<pair<int,int>> v;
        bool fans=false;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                bool flag=false;
                for(int j=i+1;j<n;j++){
                    if(s1[j]==s1[i]){
                        v.push_back({j,i});
                        char ch=s1[j];
                        s1[j]=s2[i];
                        s2[i]=ch;
                        flag=true;
                        break;
                    } else if(s1[i]==s2[j]){
                        v.push_back({j,j});
                        char ch=s1[j];
                        s1[j]=s2[j];
                        s2[j]=ch;
                        v.push_back({j,i});
                        ch=s1[j];
                        s1[j]=s2[i];
                        s2[i]=ch;
                        flag=true;
                        break;
                    }
                }
                if(!flag) {
                    fans=true;
                    break;
                }
            }
        }
        if(fans) cout<<"No\n";
        else {
            cout<<"Yes\n";
            cout<<v.size()<<"\n";
            for(int i=0;i<v.size();i++) cout<<v[i].first+1<<" "<<v[i].second+1<<"\n";
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
