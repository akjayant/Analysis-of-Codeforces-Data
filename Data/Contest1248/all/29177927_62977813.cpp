#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int cases[2]={0,0};
        for(int c=0;c<n;c++) {
            long long z;
            cin>>z;
            cases[z%2]++;
        }
        int m;
        cin>>m;
        long long res = 0;
        for(int c=0;c<m;c++) {
            long long z;
            cin>>z;
            res += cases[z%2];
        }
        cout<<res<<endl;
    }
}
