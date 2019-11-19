#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int c=0;c<n;c++) {
        cin>>v[c];
    }
    sort(v.begin(),v.end());

    long long x = 0, y = 0;
    for(int c=0;c<n/2;c++) {
        x += v[c];
    }
    for(int c=n/2;c<n;c++) {
        y += v[c];
    }
    cout<<(x*x+y*y);
}
