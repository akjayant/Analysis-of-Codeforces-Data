#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy -2147382637
#define bql 2147483647
#define ll long long
#define ull unsigned long long
#define ld long double
#define il inline
#define sz(x) x.size()
#define rp(i, l, r) for (int i = l; i <= r; i++)
#define rb(i, r, l) for (int i = r; i >= l; i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define maxn 105
using namespace std;
using namespace std;
ll max(ll a,ll b){if(a>b)return a;else return b;}
ll min(ll a,ll b){if(a<b)return a;else return b;}
ll lowbit(ll x){return x&(-x);}
ll prime(ll x){
   if(x<=1)return false;
   for(int i=2;i<=int(sqrt(x));i++){
	   if(x%i==0)return false;
   }return true;
}
bool cmp(ll a,ll b){return a>b;}
ll gcd(ll a,ll b){ll r;while(b>0){r=a%b;a=b;b=r;}return a;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline ll read() {
	char c = getchar(); ll w = 1; ll x = 0;
	while (!isdigit(c))
		(c == '-') && (w = -w), c = getchar();
	while (isdigit(c))
		x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	x *= w;
}
const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
		  dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int q,n,a,b,c,ans,vis[maxn];
char s[maxn];
int main()
{
    cin>>q;
    while(q--)
    {
        ans=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>a>>b>>c;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='R'){
                if(b){
                    b--;
                    ans++;
                    vis[i]=1;
                }
            }
            else if(s[i]=='P'){
                if(c){
                    c--;
            		ans++;
                    vis[i]=1;
                }
            }
            else{
                if(a){
                    a--;
                    ans++;
                    vis[i]=1;
                }
            }
        }
        if(ans*2>=n)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;++i)
            {
                if(vis[i])
                {
                    if(s[i]=='R')cout<<'P';
                    else if(s[i]=='P')cout<<'S';
                    else cout<<'R'; 
                }
                else{
                    if(a){
                    	cout<<'R';a--;	
					}
                    else if(b){
                        cout<<'P';b--;
                    }
                    else{
                    	cout<<'S';c--;
                    }
                }
            }
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
	return 0;
}
