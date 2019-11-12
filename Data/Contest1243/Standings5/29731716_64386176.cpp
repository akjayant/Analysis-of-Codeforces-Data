#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> data(1001,0);
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            data[tmp]++;
        }
        for(int i=999;i>=0;i--){
            data[i]+=data[i+1];
        }
        for(int i=1000;i>=0;i--){
            if(data[i]>=i){
                cout<<i<<endl;
                break;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
