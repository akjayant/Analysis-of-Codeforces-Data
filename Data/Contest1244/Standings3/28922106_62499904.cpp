#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>

#ifdef LOCAL
#define debug(x) cout<<#x<<" "<<(x)<<endl;
#else
#define debug(x)
#endif

struct fast_io{
    fast_io(){
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        cout<<fixed<<setprecision(12);
    }
}____;

int main()
{
    ll n, k;
    cin>>n>>k;
    ll a[n];
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a, a + n);
    vector<pair<ll, ll> > chsl;
    for(int i =0 ;i < n; i++){
        if(chsl.size() == 0 || a[i] != chsl[chsl.size() - 1].fi){
            chsl.pb(mp(a[i], 1));
        }else chsl[chsl.size() - 1].se ++;
    }
    int it1 = 0;
    int it2 = chsl.size() - 1;
    while(it1 < it2 && k > 0){
        if(chsl[it1].se <= chsl[it2].se && chsl[it1].se <= k){
            if(chsl[it1].se * (chsl[it1 + 1].fi - chsl[it1].fi) <= k){
                chsl[it1 + 1].se += chsl[it1].se;
                k -= chsl[it1].se * (chsl[it1 + 1].fi - chsl[it1].fi);
                chsl[it1].se = 0;
                it1++;
            }else{
                chsl[it1].fi = chsl[it1].fi + k / (chsl[it1].se);
                k = k % (chsl[it1].se);
                break;
            }
        }else if(chsl[it2].se < chsl[it1].se && chsl[it2].se <= k){
            if(chsl[it2].se * (chsl[it2].fi - chsl[it2 - 1].fi) <= k){
                chsl[it2 - 1].se += chsl[it2].se;
                k -= chsl[it2].se * (chsl[it2].fi - chsl[it2 - 1].fi);
                chsl[it2].se = 0;
                it2--;
            }else{
                chsl[it2].fi = chsl[it2].fi - k / (chsl[it2].se);
                k = k % (chsl[it2].se);
                break;
            }
        }else break;
    }
    int i = 0;
    while(chsl[i].se == 0){
        i++;
    }
    int j = chsl.size() - 1;
    while(chsl[j].se == 0){
        j--;
    }
    cout<<chsl[j].fi - chsl[i].fi<<endl;
    return 0;
}
