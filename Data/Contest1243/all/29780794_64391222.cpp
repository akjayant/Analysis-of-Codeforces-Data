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
int c[30];
int l[N],r[N];
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
        memset(c,0,sizeof c);
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        k=0;
        for(int i=0;i<n;i++)
            c[s[i]-'a']++,c[t[i]-'a']++;
        int flag=0;
        for(int i=0;i<26;i++)
            if(c[i]&1)
            {
                flag=1;
                break;
            }
        if(flag) puts("No");
        else
        {
            puts("Yes");
            for(int i=0;i<n;i++)
            {
                if(t[i]==s[i]) continue;
                for(int j=i+1;j<n;j++)
                    if(s[j]==s[i])
                    {
                        l[k]=j;
                        r[k]=i;
                        k++;
                        swap(s[j],t[i]);
                        break;
                    }
                if(t[i]==s[i]) continue;
                for(int j=i+1;j<n;j++)
                    if(t[j]==s[i])
                    {
                        l[k]=n-1;
                        r[k]=j;
                        k++;
                        swap(s[n-1],t[j]);
                        l[k]=n-1;
                        r[k]=i;
                        k++;
                        swap(s[n-1],t[i]);
                        break;
                    }
            }
            printf("%d\n",k);
            for(int i=0;i<k;i++)
                printf("%d %d\n",l[i]+1,r[i]+1);
        }
    }
}
