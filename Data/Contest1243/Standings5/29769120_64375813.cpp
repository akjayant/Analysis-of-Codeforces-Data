#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t;
int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>t;
      while(t--){
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++){
          cin>>a[i];
        }
        sort(a,a+n);
        ll x=a[n-1],y=1;
        for(int i=n-2;i>=0;i--){
           if(a[i]<y+1)break;
           y++;
        }
        cout<<y<<endl;
      } 
}