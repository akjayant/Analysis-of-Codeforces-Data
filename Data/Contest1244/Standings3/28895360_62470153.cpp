#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#define BUG puts("no bug")
#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define PER(a,b,c) for(int a=b;a>=c;a--)
#define ll long long
#define lb(a) (a&(-a))
using namespace std;
const int MAXN=1e6+5;
int n,m,t;
int num[MAXN];
char s[MAXN];
int main()
{
    cin>>t;
    REP(pp,1,t)
    {
        cin>>n;
        cin>>s+1;
        int maxm=0;
        REP(i,1,n)
        {
            if(s[i]=='1')maxm=max(maxm,max(i,n-i+1));
        }
        if(maxm==0)cout<<n<<endl;
        else cout<<maxm*2<<endl;
    }
}
