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
int m=0;
vector <pair<int,int>> ans;
vector <int> lp(27,0);
for(int k=0;k<a.size();k++){
    lp[a[k]-'a']++;
    lp[b[k]-'a']++;
}
int ind=0;
for(int k=0;k<26;k++){
   if(lp[k]%2!=0){

ind=1;
break;
   }
}
if(ind){
     cout<<"NO"<<endl;
     continue;
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
 return 0;
}
