#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10001];

main(){

int t=1;
cin>>t;
while(t--){
cin>>n;
for(int k=1;k<=n;k++)
    cin>>a[k];
    sort(a+1,a+n+1);
int ans=0;
int i=1;
for(int k=n;k>=1;k--){
   ans=max(ans,min(i,a[k]));
   i++;
}
cout<<ans<<endl;
}
 return 0;
}
