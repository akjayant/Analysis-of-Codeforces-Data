#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int n;
int a[1000][1000];
vector<int> v[1000];
int main(void){
cin>>n;
for(int i=1;i<=n/2*2;i++){
for(int j=1;j<=n/2;j++){
if(i%2)a[i/2+1][j]=a[n-i/2][n-j+1]=i;
else a[n-i/2+1][j]=a[i/2][n-j+1]=i;
}
}
if(n%2){
for(int i=1;i<=n;i++)a[n/2+1][i]=n;
for(int i=1;i<=n/2;i++)a[i][n/2+1]=i;
for(int i=n/2+2;i<=n;i++)a[i][n/2+1]=i-1;
}

for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)v[a[i][j]].push_back((j-1)*n+i);
for(int i=1;i<=n;i++){for(int j=0;j<n;j++){cout<<v[i][j]<<" ";}cout<<endl;}
}