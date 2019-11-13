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

int n,m,k,l,s,t,r,T;
int a[maxn];

int tmp[3];
char ans[maxn];
int main()
{
	
    cin>>T;
    while(T--)
    {
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        string p;
        cin>>p;
        tmp[0]=tmp[1]=tmp[2]=0;
        for(auto i:p)
        {
            if(i=='R')
                tmp[0]++;
            else if(i=='P')
                tmp[1]++;
            else if(i=='S')
                tmp[2]++;
        }
        int s1=min(tmp[2],a);
        int s2=min(tmp[0],b);
        int s3=min(tmp[1],c);
        int tot=(n+1)/2;
        for(int i=1;i<=n;i++)
            ans[i]=0;
        if(s1+s2+s3>=tot)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
                if(p[i-1]=='S')
                {
                    if(a)
                        ans[i]='R',a--;
                }else if(p[i-1]=='P')
                {
                    if(c)
                        ans[i]='S',c--;
                }else if(p[i-1]=='R')
                {
                    if(b)
                        ans[i]='P',b--;
                }
            for(int i=1;i<=n;i++)
            if(ans[i]==0)
            {
                if(a)
                    ans[i]='R',a--;
                else if(b)
                    ans[i]='P',b--;
                else if(c)
                    ans[i]='S',c--;
            }
            ans[n+1]=0;
            cout<<ans+1<<endl;
        }else cout<<"NO"<<endl;


    }

    return 0;
}

