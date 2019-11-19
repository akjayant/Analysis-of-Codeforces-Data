#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> nt;
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int x=sqrt(n);
    int m=n;
    for(int i=2;i<=x;i++)
    {
        if(m%i==0)nt.push_back(i);
        while(m%i==0)
        {
            m/=i;
        }
    }
    if(m>1)nt.push_back(m);
    if(nt.size()==1){cout<<nt[0];return 0;}
    cout<<1;
    return 0;
}
