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


int p[305][305];
int main()
{
//	input;
//	sync;
    cin>>n;
    int now=1;
    for(int i=1;i<=n;i++)
    {
        if(now)
        {
            for(int j=1;j<=n;j++)
                p[j][i]=++s;
        }else
        {
            for(int j=n;j>=1;j--)
                p[j][i]=++s;
        }
        now=!now;
    }
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
        cout<<p[i][j]<<" ";
    return 0;
}

