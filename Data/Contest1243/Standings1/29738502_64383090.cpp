#include <bits/stdc++.h>
using namespace std;

int main()
{
 //freopen("bath.in","r",stdin);
 //freopen("bath.out","w",stdout);
 ios_base::sync_with_stdio(0);
 int t;
 cin>>t;
 for(int ii=0;ii<t;ii++){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vector<pair<int,int> > ans;
    for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i]){
      int fl=0;
      for(int j=i+1;j<s1.size();j++)if(s1[i]==s1[j]){
        swap(s1[j],s2[i]);
        ans.push_back(make_pair(j,i));
        fl=1;
        break;
      }
     if (fl==0) {
        for(int j=i+1;j<s1.size();j++)if(s1[i]==s2[j]){
        swap(s1[j],s2[j]);
        swap(s1[j],s2[i]);
        ans.push_back(make_pair(j,j));
        ans.push_back(make_pair(j,i));
        fl=1;
        break;
      }
     }
     //cout<<s1<<' '<<s2<<endl;
    }
  if (s1==s2) {
    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
  } else cout<<"No"<<endl;
 }
}


