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
const int maxn=2e5+10;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const double alpha=0.7;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
int gcd(int a,int b) {
    return b?gcd(b,a%b):a;
}
int main()
{
    int _,n,k,m;
    read(_);
    while(_--) {
        int a,b;
        read(a),read(b);
        if(gcd(a,b)!=1) puts("Infinite");
        else puts("Finite");
    }
    return 0;
}
