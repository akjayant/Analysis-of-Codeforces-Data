#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll mo=1e9+7;
ll po(ll a,ll b){
   if(b==0) return 1;
   ll ans=po(a,b/2);
   ans=ans*ans%mo;
   if(b%2) ans=ans*a%mo;
   return ans;
}

int main(){
   int i,n,m;
   cin>>n>>m;
   ll x=po(2,m)-1;
   x%=mo;
   if(x<0) x+=mo;

   x=po(x,n);
   cout<<x<<endl;
   return 0;
}
