#include<bits/stdc++.h>
using namespace std;
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);

vector<unsigned long long> v;
unsigned long long n,x=0,a1=0,a0=0,sz,gt=0;

cin>>n;

for(int i=0;i<n;++i){
  cin>>x;
  v.push_back(x);
  }

sort(v.begin(),v.end());
sz=v.size();
gt=sz/2;

for(int i=0;i<gt;++i)a1+=v[i];
for(int i=gt;i<n;++i)a0+=v[i];

cout<<a1*a1+a0*a0<<endl;

return 0;
}
