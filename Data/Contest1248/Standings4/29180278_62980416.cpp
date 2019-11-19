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
ll n;
ll arr[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    cin>>n;

    for(int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr, arr + n);
    ll sm = 0, big = 0;
    for(int i = 0; i < n / 2; i++){
        sm += arr[i];
    }
    for(int i = n / 2; i < n; i++){
        big += arr[i];
    }
    cout<<sm*sm + big*big<<endl;
    #ifdef Local
        cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}