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
int m=0;
vector <pair<int,int>> ans;
vector <int> lp(27,0);
for(int k=0;k<a.size();k++){
    lp[a[k]-'a']++;
    lp[b[k]-'a']++;
}
for(int k=0;k<26;k++){
   if(lp[k]%2!=0){
    cout<<"NO"<<endl;
    return;
   }
}
for(int k=0;k<a.size();k++){
        int x=-1;
   if(a[k]!=b[k]){
    for(int i=k+1;i<a.size();i++){
        if(b[k]==a[i]){
                x=i;
            break;
        }
    }
    if(x!=-1){
    swap(a[x],b[k+1]);
    swap(a[k],b[k+1]);
    ans.push_back({x,k+1});
    ans.push_back({k,k+1});
    }
    else{
        for(int i=k+1;i<a.size();i++){
        if(b[k]==b[i]){
                x=i;
            break;
        }
        }
        swap(a[k],b[x]);
        ans.push_back({k,x});
   }
}
}
cout<<"YES"<<endl;
cout<<ans.size()<<endl;
for(int k=0;k<ans.size();k++)
    cout<<ans[k].first+1<<' '<<ans[k].second+1<<endl;
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
