#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<int,int>
#define iii pair<int, ii>
#define se second
#define double long double
#define mod 1000000007
#define popcount __builtin_popcountll
using namespace std;
const double PI = acos(-1.0);

ll n, p, w, d, W;
ll x, y, z;
unordered_map<ll,bool> mp;
int main(){
    cin>>n>>p>>w>>d;
    W=(p/w)*w;
    int c = 0;
    while(c<=50000000){
        c++;
        ll md=(p-W)%d;
        if(mp[md] || W<0){
            cout<<-1<<endl;
            return 0;
        }
        mp[md]=1;
        if(md==0){
            x = W/w;
            y = (p-W)/d;
            z = n-x-y;
            if(x+y<=n){
                assert(x+y+z<=n);
                cout<<x<<" "<<y<<" "<<z<<endl;
                return 0;
            }
            mp[md] = 0;
        }
        W-=w;
    }
    cout<<-1<<endl;
    return 0;
}
