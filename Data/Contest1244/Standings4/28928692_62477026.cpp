#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define slld(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define For(i, st, en) for(ll i=st; i<en; i++)
#define For2(i, st, en) for(ll i=st; i<en; i+=2)
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define int long long int
#define mp make_pair
#define F first
#define mem(a,b) memset(a,b,sizeof(a))
#define S second
typedef pair<int, int> pii;
#define MOD 1000000007
#define INF 1000000000000000007
#define MAXN 305

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, p, w, d, D=-1, i;
    cin>>n>>p>>w>>d;
    for(i=0;i<w;i++){
        if(p%w==((d%w)*(i%w))%w){
            D = i;
            break;
        }
    }
    if(D==-1){
        cout<<-1<<endl;
        return 0;
    }
    if(p-d*D<0){
        cout<<-1<<endl;
        return 0;
    }
    int W = (p-d*D)/w;
    if(W+D>n)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<W<<" "<<D<<" "<<n-W-D<<endl;
}