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

    int t, i;
    cin>>t;
    while(t--){
        int n, f=-1, l=-1;
        cin>>n;
        string s;
        cin>>s;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                f=i;
                break;
            }
        }
        //cout<<f<<" ";
        for(i=n-1;i>=0;i--){
            if(s[i]=='1'){
                l=n-i-1;
                break;
            }
        }
        if(f==-1&&l==-1){
            cout<<n<<endl;
            continue;
        }
        cout<<max(2*(n-f), 2*(n-l))<<endl;
    }
}