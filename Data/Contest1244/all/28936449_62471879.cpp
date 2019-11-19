#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB pusb_back
#define P push
#define mem(x,y) memset(x,y,sizeof(x))

int main()
{
    int test,tc;
    cin>>test;
    for(tc=1; tc<=test; tc++)
    {
        int i,j,k,s,d,r,m,n;
        cin>>n;
        string line;
        cin>>line;

        int mx=0;
        for(i=0; i<n; i++)
        {
            if(line[i]=='1')
            {
                int x,y;
                x=i+1;
                y=n-i;
                mx=max(mx,x);
                mx=max(mx,y);
            }
        }
        if(mx==0)
            mx=n;
            else mx*=2;
        cout<<mx<<endl;
    }

}

