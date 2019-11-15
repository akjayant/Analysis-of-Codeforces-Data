#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define IOS cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

int x[333][333];
signed main()
{IOS;
int n;
    cin>>n;
    int xer=0;
    for(int j=1;j<=n;j++){
        if(j&1)
        for(int i=1;i<=n;i++){
            x[i][j]=++xer;
        }
        else
        for(int i=n;i>=1;i--){
            x[i][j]=++xer;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<x[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}

/*
*/

