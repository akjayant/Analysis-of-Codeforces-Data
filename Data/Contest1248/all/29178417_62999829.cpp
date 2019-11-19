#include<bits/stdc++.h>
using namespace std;
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);

long long t,n,x,od,ev,res;
cin>>t;

while(t-->0){
  cin>>n;
  od=0;ev=0;res=0;
  for(int i=0;i<n;++i){
    cin>>x;
    if(x%2==1)++od;
    else ++ev;
    }
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>x;
    if(x%2==1)res+=od;
    else res+=ev;
    }
  cout<<res<<endl;
  }

return 0;
}
