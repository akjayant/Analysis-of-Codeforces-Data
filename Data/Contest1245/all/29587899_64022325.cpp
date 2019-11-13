#include<bits/stdc++.h>
#define numm ch-48
#define pd putchar(' ')
#define pn putchar('\n')
#define pb push_back
#define debug(args...) cout<<#args<<"->"<<args<<endl
#define bug cout<<"************"
using namespace std;
template <typename T>
void read(T &res) {
    bool flag=false;char ch;
    while(!isdigit(ch=getchar())) (ch=='-')&&(flag=true);
    for(res=numm;isdigit(ch=getchar());res=(res<<1)+(res<<3)+numm);
    flag&&(res=-res);
}
template <typename T>
void write(T x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
typedef long long ll;
typedef long double ld;
const int maxn=1e5+10;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const double alpha=0.7;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
char s[maxn];
ll f[maxn];
int main()
{
    int _,n,k,m;
    f[0]=1,f[1]=1;
    for(int i=2;i<=(int)1e5;i++) {
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    while(scanf("%s",s)!=EOF) {
        int len=strlen(s);
        ll res=1;
        bool flag=true;
        for(int i=0;i<len;i++) {
            if(s[i]=='m'||s[i]=='w') {
                flag=false;
                break;
            }
            if(s[i]=='n') {
                ll ans=1;
                while(i+1<len&&s[i+1]=='n') ans++,i++;
                res=res*(f[ans])%mod;
            }
            else if(s[i]=='u'){
                ll ans=1;
                while(i+1<len&&s[i+1]=='u') ans++,i++;
                res=res*(f[ans])%mod;
            }
        }
        if(!flag) write(0);
        else write(res);pn;
    }
    return 0;
}
