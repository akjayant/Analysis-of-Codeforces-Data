#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mod1 998244353
#define inf1 INT_MAX
#define inf2 LLONG_MAX
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define sbit __builtin_popcount
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define rit(it,x) for(auto it=x.begin();it!=x.end();it++)
#define cases(t) int t; cin>>t; rep(casn,1,t+1)
#define fill(a,b) memset(a,b,sizeof(a))
#define dbg(x) cerr<<#x<<" "<<x<<endl;
#define dbga(arr,n) cerr<<#arr<<": "; rep(tt,0,n)cerr<<arr[tt]<<" "; cerr<<endl;
#define infile ifstream fin; fin.open("input.txt")
#define outfile ofstream fout; fout.open("output.txt")
#define vec vector<int>
#define pii pair<int,int>
#define plii pair<ll,int>
#define pll pair<ll,ll>
#define p_queue priority_queue< plii,vector< plii >,greater< plii > > 
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sl(x) scanf("%lld",&x)
#define sst(x) scanf("%s",x)
#define pl(x) printf("%lld\n",x)
#define pi(x) printf("%d\n",x)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search

inline ll binex(ll a,ll b)
{
    ll ans=1,temp=a%mod;
    while(b!=0){
        if(b&1) ans=(ans*temp)%mod;
        temp=(temp*temp)%mod;
        b=b>>1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cases(t){
        int n; cin>>n;
        int a,b,c; cin>>a>>b>>c;
        string s,s1(n,'#'); cin>>s;
        int a1=0,b1=0,c1=0;
        rep(i,0,n){
            if(s[i]=='R') a1++;
            else if(s[i]=='P') b1++;
            else c1++;
        }
        int ans=min(a,c1)+min(b,a1)+min(c,b1);
        int x=(n%2==0) ? n/2 : (n/2)+1;
        if(ans>=x){
            cout<<"YES"<<endl;
            int p=min(a,c1),q=min(b,a1),r=min(c,b1);
            int p1=a-p,q1=b-q,r1=c-r;
            rep(i,0,n){
                if(s[i]=='R'){
                    if(q>0){
                        s1[i]='P'; q--;
                    }
                }
                else if(s[i]=='P'){
                    if(r>0){
                        s1[i]='S'; r--;
                    }
                }
                else if(s[i]=='S'){
                    if(p>0){
                        s1[i]='R'; p--;
                    }
                }
            }
            
            rep(i,0,n){
                if(s1[i]=='#'){
                    //cerr<<"ansjn0"<<endl;
                    if(q1>0){
                        s1[i]='P'; q1--;
                    }
                    else if(r1>0){
                        s1[i]='S'; r1--;
                    }
                    else if(p1>0){
                        s1[i]='R'; p1--;
                    }
                }
            }
            cout<<s1<<endl;
        }
        else cout<<"NO"<<endl;
    }
}