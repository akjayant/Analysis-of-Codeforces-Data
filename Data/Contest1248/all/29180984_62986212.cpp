#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,p; cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n; i++){ cin>>p; vec[i]=p;}
    sort(vec.begin(),vec.end());
    long long sum1=0,sum2=0;
    for(int i=0; i<n/2; i++) sum1+=vec[i];
    for(int i=n/2; i<n; i++) sum2+=vec[i];
    cout<<sum1*sum1+sum2*sum2;
    return 0;
}

