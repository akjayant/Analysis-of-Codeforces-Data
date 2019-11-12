// by : 信冯哥
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5+5;
const int mod = (int)1e9+7;

typedef long double dl;
typedef long long ll;
//#define int ll

#define orz cout<<endl
#define debug cout<<"-------------------"<<endl
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define sync ios::sync_with_stdio(false)

int n,m,k,l,s,t,r,ans,T;
int a[maxn];



int main()
{

    cin>>T;
    while (T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        int x=min(b,c/2);
        ans+=x*3;
        b-=x;
        c-=x*2;
        x=min(a,b/2);
        ans+=3*x;
        cout<<ans<<endl;

    }

    return 0;
}

