//#include<bits/stdc++.h>


#include<bits/stdc++.h>
using namespace std;
#define ls rt<<1
#define rs (rt<<1)+1
#define PI acos(-1)
#define eps 1e-8
#define ll long long
#define fuck(x) cout<<#x<<"     "<<x<<endl;
typedef pair<int,int> pii;
const int inf=2e9;
const int maxn=1e6+10;
int d[4][2]={1,0,-1,0,0,1,0,-1};
inline ll read() {
    ll s = 0,w = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') w = -1;
        ch = getchar();
    }
    while(isdigit(ch))
        s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
inline void write(ll x) {
    if(x < 0)
        putchar('-'), x = -x;
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

int vis[1000100],prime[1000010];
int cnt=0;
bool check(ll n){
    for(ll i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}
void init()
{

    for(int i=2;i<=1000000;i++)
    {
        if(!vis[i])
        {
            vis[i]=i;
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++)
            if(prime[j]>vis[i]||prime[j]>1000000/i)
                break;
            else
                vis[i*prime[j]]=prime[j];
    }
}
bool weiyi(ll n,ll x){
    while(n%x==0)
        n/=x;
    if(n==1)
        return 1;
    return 0;
}
int flagf=0;
int main(){
    init();
    ll n;
    bool flag=1;
    n=read();
    if(check(n)){
        cout<<n<<endl;return 0;}
    for(int i=1;i<=cnt;i++){
        flagf++;
        if(n%prime[i]==0)
        {
            if(flagf==-1)
                cout<<flagf<<endl;
            else
            if(weiyi(n,prime[i]))
                cout<<prime[i]<<endl;
            else
                cout<<1<<endl;
            break;

        }
    }

    return 0;
}
