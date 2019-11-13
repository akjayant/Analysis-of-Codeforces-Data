#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    ll n;
    cin>>n;
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            cout <<n*j+i+1 << " ";
            cout <<n*(n-j)-i << " ";
        }
        if(n%2){
            cout << n/2 * n + i + 1 << " ";
        }
        cout << "\n";
    }
    
    
    
}