#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
#define maxm 200005
#define INF 1234567890
#define p 1000000007
template<class T>inline bool read(T &x)
{
    x=0;register char c=getchar();register bool f=0;
    while(!isdigit(c)){if(c==EOF)return false;f^=c=='-',c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    if(f)x=-x;
    return true;
}
template<class T>inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10^48);
}
template<class T>inline T maxd(T a,T b){if(b>a)return b;return a;}
template<class T>inline T mind(T a,T b){if(b<a)return b;return a;}
template<class T>inline T gcd(T a,T b){while(a^=b^=a^=b%=a);return b;}
template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T>inline T absd(const T &a){if(a<0)return -a;return a;}
template<class T>inline void print(T x,char c){print(x),putchar(c);}
ll t,n,a,b,c,tot,els,cnt,flag;
string s;
char ans[maxn];
int main()
{
    //freopen("test.in","r",stdin);
    read(t);
    while(t--)
    {
        read(n),read(a),read(b),read(c);
        tot=els=flag=cnt=0;
        cin>>s;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                if(b)
                {
                    b--;
                    tot++;
                    ans[++cnt]='P';
                }
                else
                {
                    els++;
                    ans[++cnt]='0';
                }
            }
            else if(s[i]=='P')
            {
                if(c)
                {
                    c--;
                    tot++;
                    ans[++cnt]='S';
                }
                else
                {
                    els++;
                    ans[++cnt]='0';
                }
            }
            else
            {
                if(a)
                {
                    a--;
                    tot++;
                    ans[++cnt]='R';
                }
                else
                {
                    els++;
                    ans[++cnt]='0';
                }
            }
            if(tot>=(n+1)/2)
            {
                flag=1;
                cout<<"YES"<<endl;
                for(ll j=1;j<=cnt;j++)
                {
                    if(ans[j]=='0')
                    {
                        if(a)
                        {
                            a--;
                            cout<<'R';
                        }
                        else if(b)
                        {
                            b--;
                            cout<<'P';
                        }
                        else
                        {
                            c--;
                            cout<<'S';
                        }
                    }
                    else cout<<ans[j];
                }
                for(ll j=cnt+1;j<=n;j++)
                if(a)
                {
                    a--;
                    cout<<'R';
                }
                else if(b)
                {
                    b--;
                    cout<<'P';
                }
                else
                {
                    c--;
                    cout<<'S';
                }
                cout<<endl;
                break;
            }
        }
        if(!flag)cout<<"NO"<<endl;
    }
    return 0;
}
