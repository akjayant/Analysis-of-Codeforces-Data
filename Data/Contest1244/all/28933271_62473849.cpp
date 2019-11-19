#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,s=0,f=-1,j,g,max1=0,cnt=0;
        cin>>n;
        string str;
        cin>>str;
        for(i=0;i<n;i++)
        {
            if(f==-1)
            {
                if(str[i]=='1')
                {
                    f=i;
                    g=i;
                    cnt++;
                }
            }
            else
            {
                if(str[i]=='1')
                {
                    g=i;
                    cnt++;
                }
            }
        }
        f=f+1;
        g=g+1;
        //cout<<f<<" "<<g;
        if(cnt>0)
        {
            max1=cnt+n;
            max1=max(max1,(n-f+1)*2);
            max1=max(max1,(g*2));
            cout<<max1<<"\n";
        }
        else
        {
            cout<<n<<"\n";
        }
    }
}
