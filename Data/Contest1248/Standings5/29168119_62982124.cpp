#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin>>T;
    ll oddd,evenn,o2,e2;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        int b;
        oddd=evenn=o2=e2=0;
        for(int j=1;j<=n;j++)
            {cin>>b;if(b&1)oddd++;else evenn++;}
        cin>>m;
        for(int j=1;j<=m;j++)
            {cin>>b;if(b&1)o2++;else e2++;}
        cout<<oddd*o2+evenn*e2<<endl;
    }
    return 0;
}
