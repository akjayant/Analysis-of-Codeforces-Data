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
        cin>>n;
        string p;
        cin>>p;
        int x=0;
        for(int i=1;i<=n;i++)
            a[i]=p[i-1]-'0',x+=a[i];
        int ans=n;
        if(x)
            ans=n+1;
        else
        {
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                ans=max(ans,i*2);
                ans=max(ans,(n-i+1)*2);
            }

        }
        cout<<ans<<endl;

    }

    return 0;
}

