#include <bits/stdc++.h>
using namespace std;
int nxt_in(){int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';return n?-x:x;}
#define in nxt_in()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(false),cin.tie(nullptr);
#define task "TASK"
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))

main(){
    fasty;
    int t; cin>>t;
    while(t--){
        vector<int> dd(500);
        int n,a,b,c,ret=0,a1,b1,c1;
        string s;
        cin>>n>>a>>b>>c>>s;
        s=' '+s;
        forinc(i,1,n){
            if(s[i]=='P'&&c){
                c--;
                ret++;
                dd[i]=3;
            }
            if(s[i]=='S'&&a){
                a--;
                ret++;
                dd[i]=1;
            }
            if(s[i]=='R'&&b){
                b--;
                ret++;
                dd[i]=2;
            }
        }
        int z=(n+1)/2;
        if(ret<z) cout << "NO\n";
        else{
            a1=a,b1=b,c1=c;
            cout<<"YES\n";
            forinc(i,1,n) if(dd[i]==0){
                if(a1>0) dd[i]=1,a1--;
                else if(b1>0) dd[i]=2,b1--;
                else dd[i]=3,c1--;
            }
            forinc(i,1,n){
                if(dd[i]==3) cout<<"S";
                if(dd[i]==2) cout<<"P";
                if(dd[i]==1) cout<<"R";
            }
            cout<<"\n";
        }
    }
    int pxh=2312;
    pxh++;
    forinc(i,100,1100) pxh;
}
