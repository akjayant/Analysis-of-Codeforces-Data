#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define yoi cout<<"yo"<<endl;
#define debug(x) cerr << #x << " is " << x << endl;
#define all(x) x.begin(),x.end()
const lli inf=1e18;
const int mod=1e9+7;
int main(){
IOS;
int n,i,j;
cin>>n;
vector<vector<int> > v(n+1);
for(i=n-1;i>=0;i--){
    if((n-i)%2){
        for(j=n;j>=1;j--){
            v[n-j+1].pb(i*n+j);
        }
    }
    else{
        for(j=1;j<=n;j++){
            v[j].pb(i*n+j);
        }
    }
}
for(i=1;i<=n;i++){
    for(j=0;j<n;j++)
        cout<<v[i][j]<<" ";
    cout<<endl;
}
}
