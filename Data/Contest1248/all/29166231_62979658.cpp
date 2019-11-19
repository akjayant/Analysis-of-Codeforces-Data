#include<bits/stdc++.h>
//#include <numeric>
using namespace std;
#define int long long int
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int o1=0,o2=0,e1=0,e2=0;
        int n;
        cin>>n;
        int i;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x%2==0)
            {
                e1++;
            }
            else 
                o1++;
        }
         int m;
        cin>>m;
        //int i;
        for(i=0;i<m;i++)
        {
            int x;
            cin>>x;
            if(x%2==0)
            {
                e2++;
            }
            else 
                o2++;
        }
        cout<<( e1*e2 + o1*o2)<<"\n";
    }

}