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
    while(T--)
    {
        cin>>n>>m;
        if(__gcd(n,m)!=1)
        {
            cout<<"Infinite"<<endl;
        }else
        {
            cout<<"Finite"<<endl;
        }


    }

    return 0;
}

