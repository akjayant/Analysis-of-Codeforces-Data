#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long a[n+1];
        int i;
        long long int c=0,d=0,c1=0,d1=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]&1)
            {
                c++;
            }
            else
            {
                d++;
            }
        }
        int m;
        cin>>m;
        long long b[m+1];
        for(i=1;i<=m;i++)
        {
            cin>>b[i];
            if(b[i]&1)
            {
                c1++;
            }
            else
            {
                d1++;
            }
        }
        cout<<c*c1+d*d1<<endl;
    }
}
