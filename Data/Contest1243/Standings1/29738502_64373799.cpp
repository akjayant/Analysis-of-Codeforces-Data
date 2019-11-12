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
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=a.size()-1;i>=0;i--){
      if (a[i]>=ans+1) ans++;
    }
    cout<<ans<<endl;
 }
}


