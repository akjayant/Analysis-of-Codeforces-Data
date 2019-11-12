#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rint register int
typedef long long ll;
typedef long long unsigned llu;
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int bs=31;
const double eps=1e-8;
const ll zzz=1e9;
struct iiios{
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template<typename _Tp> inline ios&operator>>(_Tp&x){
        static char ch,sgn;ch=gc(),sgn=0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc()) x=x*10+(ch^'0');
        sgn&&(x=-x);
    }
}io;
char ss[N],tt[N];
int k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        k=0;
        for(int i=0;i<n;i++)
            if(s[i]!=t[i])
            {
                ss[k]=s[i];
                tt[k]=t[i];
                k++;
            }
        if(k!=2) puts("No");
        else
        {
            if(ss[0]==ss[1]&&tt[0]==tt[1]) puts("Yes");
            else puts("No");
        }
    }
}
