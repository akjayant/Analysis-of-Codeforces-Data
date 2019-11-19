#include <bits/stdc++.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define oo 2000000000
#define inf 1000000000000000LL
#define M 1000000007
typedef long long ll;
using namespace std;
const int N = 105001;

ll n;
ll k;
ll freqL,freqR,L,R;
map<ll,ll> freq;
ll a[N];
vector<ll> v;
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin >> n >> k ;
    for(ll i = 0 ; i < n ; i++)scanf("%lld",a+i),freq[a[i]]++;
    sort(a,a+n);
    v.push_back(a[0]);
    for(ll i = 1 ; i < n ; i++)
        if(a[i]!=v.back())
            v.push_back(a[i]);
    freqL=freq[v[0]];
    freqR=freq[v.back()];
    ll steps = 0;
    L=0;
    R=v.size()-1;
    while(k>0&&L!=R){
        if(freqL<freqR){
            steps = k/freqL;
            if(steps==0)break;
            if(v[L+1]-steps<=v[L]){
                k-=(v[L+1]-v[L])*freqL;
                L++;
                freqL+=freq[v[L]];
            }else{
                v[L]+=steps;
                k-=freqL*steps;
            }
        }else{
            steps = k/freqR;
            if(steps==0)break;
            if(v[R]-steps<=v[R-1]){
                k-=(v[R]-v[R-1])*freqR;
                R--;
                freqR+=freq[v[R]];
            }else{
                v[R]-=steps;
                k-=freqR*steps;
            }
        }
    }
    cout << v[R]-v[L] << endl;




    return 0;
}
