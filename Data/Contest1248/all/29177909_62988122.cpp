#include<bits/stdc++.h>
#define IO cin.tie(0);ios_base::sync_with_stdio(false);
#define int long long 
#define push push_back
#define pop pop_back
#define endl '\n'

using namespace std;

signed main(){
    IO
    int n,a,k;
    int output=0;
    vector<int> l;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        l.push(a);
    }
    sort(l.begin(),l.end());
    reverse(l.begin(),l.end());
    k=0;
    for(int i=0;i<n/2;i++){
        k+=l.back();
        l.pop();
    }
    output+=k*k;
//  cout<<output<<endl;
    k=0;
    while(l.size()){
        k+=l.back();
        l.pop();
    }
    output+=k*k;
    cout<<output<<endl;
    return 0;
}
