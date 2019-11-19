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
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        int tmpa=a/c;
        if(a%c)tmpa++;
        int tmpb=e-tmpa;
        if(tmpb*d<b||tmpb<0)cout<<-1;
        else cout<<tmpa<<' '<<tmpb;
        cout<<endl;
    }
}
