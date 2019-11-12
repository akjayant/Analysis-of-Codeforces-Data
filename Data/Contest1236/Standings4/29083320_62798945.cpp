#include <bits/stdc++.h>
#define ll long long
#define N 302
using namespace std;
ll a[N][N];
int main(){
    ll n,i,j;
    cin>>n;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            a[j][i]=(i&1 ? j+(i-1)*n : n*i-j+1);
    for(i=1; i<=n; ++i){
        for(j=1; j<=n; ++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
	return 0;
}
