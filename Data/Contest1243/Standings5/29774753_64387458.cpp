#include<bits/stdc++.h>
#define int long long
using namespace std;
void icc(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void B1B2(){
int n;
string a,b;
cin>>n>>a>>b;
int h=0;
int x=0,ind=0,pas=0;
for(int k=0;k<a.size();k++){
    if(a[k]!=b[k]){
        ind++;
        if(ind==3){
            cout<<"NO"<<endl;
            return ;
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
if(ind==0 || pas==1)
    cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}

main(){
icc();
int t=1;
cin>>t;
while(t--){
   B1B2();
}
 return 0;
}
