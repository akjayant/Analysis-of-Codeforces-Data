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
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int f=0;
        for(int i=0;i<=k;i++)
        {
            if(c*i>=a&&(k-i)*d>=b)
            {
                f=1;
                cout<<i<<" "<<k-i<<endl;
                break;
            }
        }
        if(f==0)
            cout<<-1<<endl;
    }

    return 0;
}





