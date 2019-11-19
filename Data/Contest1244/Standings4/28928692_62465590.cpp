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

    int t;
    cin>>t;
    while(t--){
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        int x = ceil((double)a/c)+ceil((double)b/d);
        if(x>k){
            cout<<-1<<endl;
            continue;
        }
        cout<<(int)ceil((double)a/c)<<" "<<(int)ceil((double)b/d)<<endl;
    }
}