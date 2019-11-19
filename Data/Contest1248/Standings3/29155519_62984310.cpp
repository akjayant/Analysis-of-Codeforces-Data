#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main()
{
    long long t,n,p,ans=0,kk=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ans=0;
        kk=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)
            {
                ans++;
            }
        }
        cin>>p;
        for(int i=0;i<p;i++)
        {
            cin>>b[i];
            if(b[i]%2==0)
            {
                kk++;
            }
        }
        cout<<ans*kk+(n-ans)*(p-kk)<<endl;
        for(int i=0;i<n;i++)
        {
            a[i]=0;
        }
        for(int i=0;i<p;i++)
        {
            b[i]=0;
        }
    }



}