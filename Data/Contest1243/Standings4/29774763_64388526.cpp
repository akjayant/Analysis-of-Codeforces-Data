#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
int t=1;
cin>>t;
while(t--){
int n;
string a,b;
cin>>n>>a>>b;
int h=0;
int x=0,ind=0,pas=0;
for(int k=0;k<a.size();k++){
    if(a[k]!=b[k]){
        ind++;
        if(ind==3){

         break;
        }
        if(ind==2){
            if(a[x]==a[k] && b[x]==b[k]){
              pas=1;
            }
        }
        if(ind==1){
            x=k;

        }
    }
}
if(ind==3)
    cout<<"NO"<<endl;
else
if(ind==0 || pas==1)
    cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
 return 0;
}
