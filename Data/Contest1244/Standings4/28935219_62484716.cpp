#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const int MX = 1e9;
vector<pair<long long,long long> > v;
vector<long long> arr;
long long n,k,l,h,mid,mn=MX,mx;
map<long long,long long> m;

int check(){
long long del = mx-mn-mid;
long long cost = 0;
for(long long i=0;i<v.size();i++){
    if(!del) break;
    long long x = min(del,v[i].second);
    cost += x * v[i].first;
    del-=x;
    if(!del) break;
}
return ((cost<=k) && !del);
}

int main()
{
   IO;
   cin>>n>>k;
   arr.resize(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
    mn=min(mn,arr[i]);
    mx=max(mx,arr[i]);
   }
   sort(arr.begin(),arr.end());
   for(long long i=0;i<n-1;i++) m[min(i+1,n-i-1)]+=(arr[i+1]-arr[i]);
   for(auto it: m) {
    v.push_back({it.first,it.second});
   }
   sort(v.begin(),v.end());
   l=0,h=mx-mn;
   while(l<h){
    mid = (l+h)/2;
    if(check()) h=mid;
    else l=mid+1;
   }
   cout<<l;
}
