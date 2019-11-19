#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100004];
ll ans,ans2;
int main(void){
scanf("%d",&n);
for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans+=a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n/2;i++)ans2+=a[i];
cout<<(ans-ans2)*(ans-ans2)+ans2*ans2<<endl;
}