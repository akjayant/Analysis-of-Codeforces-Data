#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<ctime>
#define int long long
#define lowbit(x) x&-x
#define inf 2147483647
#define N 200005
#define mod 1000000007
#define int long long
using namespace std;
int n,m,t,x,y,z,ans;
char a[1005],b[1005];
signed main()
{
    cin>>t;
    while(t--)
	{
        cin>>n>>x>>y>>z;
        scanf("%s",a+1); 
		ans=0;
        for(int i=1;i<=n;i++)
		    b[i]='L';
        for(int i=1;i<=n;i++)
		{
            if(a[i]=='R'&&y) 
			    b[i]='P',--y,++ans;
            if(a[i]=='P'&&z) 
			    b[i]='S', --z,++ans;
            if(a[i]=='S'&&x)
			    b[i]='R',--x,++ans;
        }
        if(ans<(n+1)/2) 
            cout<<"NO"<<endl; 
        else
		{
			cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
			{
                if(b[i]=='L')
				{
                    if(x) 
					    b[i]='R',--x;
                    else if(y) 
					    b[i]='P',--y;
                    else if(z) 
					    b[i]='S',--z;
                } 
            }
            for(int i=1;i<=n;i++)
			    cout<<b[i];
			cout<<endl;
        }
    }
    return 0;
}