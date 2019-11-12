#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef double db;

#define mp make_pair
#define pb push_back
#define pt(i) printf("%lld\n",(ll)i)
#define mp make_pair
#define ff first
#define ss second
#define pi acos(-1.0)

ll in() { ll a;scanf("%lld",&a); return a;}
db din(){ db a;scanf("%lf",&a); return a; }
ll bigmod(ll b, ll p,ll md){if(p==0) return 1;if(p%2==1){ return ((b%md)*bigmod(b,p-1,md))%md;} else {ll y=bigmod(b,p/2,md);return (y*y)%md;}}
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b);}

long long getRandom(long long a,long long b){
    long long ret = (long long)rand()*(long long)rand();
    ret %= (b - a + 1);
    ret += a;
    return ret;
}

int main()
{
    int t=in();
    while(t--)
    {
        int len=in();
        char s1[len+5],s2[len+5];
        scanf("%s %s",s1,s2);
        int pos=0,cnt=0,fre[200],hobe=0;
        memset(fre,0,sizeof fre);
        for(int i=0;i<len;i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                if(cnt==1)
                pos=i;
                else if(cnt==2)
                {
                    if(s1[pos]==s1[i]&&s2[pos]==s2[i]);
                    else
                    {
                        pos=-1;
                        break;
                    }
                }
                else{
                    pos=-1;
                    break;
                }
            }
            fre[s1[i]]++;
            if(fre[s1[i]]==2)
            hobe=1;
        }
        if(pos==-1||cnt==1||(cnt==0&&hobe==0))
        puts("No");
        else
        puts("Yes");
    }
}
