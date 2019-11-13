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
ll n,a,b;
int main()
{
    //freopen("test.in","r",stdin);
    read(n);
    while(n--)
    {
        read(a),read(b);
        if(gcd(a,b)==1)
            cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }
    return 0;
}
