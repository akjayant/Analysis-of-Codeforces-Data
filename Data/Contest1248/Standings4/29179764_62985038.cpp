#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100,delta=1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>a;
    while(n--){
        int t;
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    long long sm=0;
    long long lg=0;
    for(int i=0;i<a.size()/2;i++)sm+=a[i];
    for(int i=a.size()/2;i<a.size();i++)lg+=a[i];
    long long ans=sm*sm+lg*lg;
    //cout<<sm<<' '<<lg;
    cout<<ans;
}
