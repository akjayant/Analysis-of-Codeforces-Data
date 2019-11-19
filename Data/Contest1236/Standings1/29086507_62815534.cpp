#include <bits/stdc++.h>

using namespace std;
int z[300050];
int y[300050];
int xzy;
int xzz;
int main()
{
    int n,m;
    cin>>n>>m;
    int i=100001;while(i<=100000+n)
    {
        z[i]=1;
        y[i]=1;
        i++;
    }
    i=1;while(i<=m)
    {
        int temp;
        cin>>temp;
        int mm=temp-i+100000;
        y[mm-1]+=y[mm];
        y[mm]=0;
        mm=temp+i+100000;
        z[mm+1]+=z[mm];
        z[mm]=0;
        i++;
    }
    long long sum=0;
    int temp=100001;
    i=1;while(i<=100000+n)
    {
        if(y[i]!=0)
        {
            while(y[i]--)
            {
                sum=sum+min(i+m+1,100000+n)-temp;
               // cout<<"***"<<temp<<" "<<sum<<endl;
                temp++;
            }
        }
        i++;
    }
    temp=100000+n;
    i=300005;while(i>=100001)
    {
        if(z[i]!=0)
        {
            while(z[i]--)
            {
                sum=sum-max(i-m-1,100001)+temp;
               // cout<<temp<<"***"<<sum<<endl;
                temp--;
            }
        }
        i--;
    }
    if(n==1) cout<<0<<endl;
    else cout<<sum+n<<endl;

    return 0;
}
