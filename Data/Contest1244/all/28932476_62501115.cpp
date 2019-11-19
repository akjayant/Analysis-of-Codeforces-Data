#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const long long INF = (long long) 1e18;
const int mod = (int) 1e9+7;
const int MAXN = (int) 3e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n, k;
ll arr[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);

    ll mxi = n - 1, mni = 0; 
    ll is = 0;
    ll frk = arr[n - 1] - arr[0];
    ll mncur = arr[0];
    ll mxcur = arr[n - 1];
    while(mni < n && arr[mni] == arr[0]){
        mni++;
    }
    mni--;
    while(mxi >= 0 && arr[mxi] == arr[n - 1]) mxi--;
    mxi++;
    while(is < k && mxi > mni && mxcur > mncur){
        if(n - mxi > mni + 1){
            ll frk = arr[mni + 1] - arr[mni];
            ll art = min(k - is, frk*(mni + 1));
            if(k -is < mni + 1) break;
            if(art == k - is){
                mncur = min(mncur + art/(mni + 1), mxcur);
                is += ((art/(mni + 1))*(mni + 1));
            }else{
                is += frk*(mni + 1);
                mni++;
                mncur = arr[mni];
            }
        }else{
            ll frk = arr[mxi] - arr[mxi - 1];
            ll art = min(k - is, frk*(n - mxi));
            if(k - is < n - mxi){
                break;
            }
            if(art == k - is){
                mxcur = max(mncur, mxcur - art/(n - mxi));
                is += ((art/(n - mxi))*(n - mxi));
            }else{
                is += frk*(n - mxi);
                mxi--;
                mxcur = arr[mxi];
            }
        }
        //cout<<is<<" "<<mxi<<" "<<mxcur<<" "<<mni<<" "<<mncur<<endl;
    }
    cout<<mxcur - mncur<<endl;

    
    #ifdef Local
        cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}