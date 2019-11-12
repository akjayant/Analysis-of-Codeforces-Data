#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pi pair<int,int>
#define ppi pair<int,pi >
#define ld long double
#define pb push_back
#define mod 1000000007
#define F first
#define S second

int modular(int a,int b,int c){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        return modular(((a*a)%c),b/2,c);
    }else{
        return ((a%c)*(modular(((a*a)%c),b/2,c)%c))%c;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int ans[n][n];
    int k=1;
    int flag=0;
    for(int i=0;i<n;i++){
        if(flag==0){
            for(int j=0;j<n;j++){
                ans[j][i]=k;
                k++;
            }
            flag=(flag^1);
        }else{
            for(int j=n-1;j>=0;j--){
                ans[j][i]=k;
                k++;
            }
            flag=(flag^1);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
