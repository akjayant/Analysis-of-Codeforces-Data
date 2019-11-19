#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];}
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";}
#define S second
#define F first
const int  MOD = 1e9 + 7;
const int  N = 1e5 + 7;
vector<ll> v , sum;
ll n , k;


bool can(ll m){
    for(int i = 1; i <= n ; i++){
        auto it = lower_bound(v.begin() , v.end() , v[i] + m);
        ll sm = 0;
        int ind = it - v.begin();
        if(it != v.end()) sm += sum[n] - sum[ind - 1] - (v[i] + m ) * (n - ind + 1);
        // cout<<i<<" "<<sm<<endl;        
        sm += v[i] * i - sum[i];
        // cout<<i<<" "<<sm<<endl;
        if(sm <= k) return true;
    }

    for(int i = n; i >= 1 ; i--){
        auto it = lower_bound(v.begin() , v.end() , v[i] - m);
        int ind = it - v.begin();
        ind--;
        ll sm = 0;
        if(ind != -1) sm += (v[i] - m) * ind - sum[ind];
        // cout<<i<<" "<<sm<<endl;                
        sm += sum[n] - sum[i] - v[i] * (n - i);
        // cout<<i<<" "<<sm<<endl;        
        if(sm <= k) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    cin>>n>>k;
    v.resize(n + 1 , 0);
    sum.resize(n + 1 , 0);
    for(int i = 1 ; i <= n; i++) cin>>v[i];
    sort(v.begin() , v.end());
    for(int i = 1 ; i<= n ; i++) sum[i] = sum[i-1] + v[i];

    ll l = 0 , r = v[n] - v[1] , m , res = 0;
    while(l <= r){
        m = (l + r)/ 2;
        if(can(m)){
            res = m;
            r = m - 1;
        }else l = m + 1;
    }
    cout<<res<<endl;
    return 0;
}