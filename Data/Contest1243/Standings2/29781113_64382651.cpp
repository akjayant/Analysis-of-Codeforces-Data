#include <bits/stdc++.h>
using namespace std;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';return n?-x:x;}
#define in hmt()
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define getbit(i,x) ((x>>i)&1ll)
#define ii pair<int,int>

int k,n;
string s,t;

main()
{
   // freopen("test.inp","r",stdin);
    cin>>k;
    while(k--)
    {
        int cnt=0;
        cin>>n;
        cin>>s>>t;
        s=' '+s,t=' '+t;
        forinc(i,1,n) if(s[i]!=t[i]) cnt++;
        if(cnt>=3||cnt==1) {cout<<"NO"<<"\n";continue;}
        else if(cnt==0) {cout<<"NO"<<"\n";continue;}
        else if(cnt==2)
        {
            bool ok=true,ok1=true;
            int pos,pos1;
            forinc(i,1,n) if(s[i]!=t[i]) {pos=i;break;}
            fordec(i,n,1) if(s[i]!=t[i]) {pos1=i;break;}
            swap(s[pos],t[pos1]);
            forinc(i,1,n) if(s[i]!=t[i]) {ok=false;break;}
            swap(s[pos],t[pos1]);
            swap(s[pos1],t[pos]);
            forinc(i,1,n) if(s[i]!=t[i]) {ok1=false;break;}
            if(ok||ok1) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
        //cout<<"\n";
    }
}
