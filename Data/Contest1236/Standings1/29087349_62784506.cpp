#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define IOS cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);


signed main()
{IOS;
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        ans+=min(b,c/2);
        b-=ans;
        ans+=min(a,b/2);
        cout<<ans*3<<endl;
    }
    return 0;
}

/*
*/

