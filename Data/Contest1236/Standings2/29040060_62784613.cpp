#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int maxi=0;
        for(int i=0;i<=200;i++)
        {
            int tk=a-i;
            int tk2=b-2*i;
            if(tk<0 || tk2<0)
                break;
            int left=min(tk2,c/2);
            maxi=max(maxi,3*left+3*i);
        }
        cout<<maxi<<endl;
    }
}