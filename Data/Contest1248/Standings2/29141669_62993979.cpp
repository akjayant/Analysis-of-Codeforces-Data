#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<long long> dpn(n+1,0);
    dpn[0]=2;
    dpn[1]=2;
    for(int i=2;i<n+1;i++)
        dpn[i]=(dpn[i-1]+dpn[i-2])%1000000007;
    vector<long long> dpm(m+1,0);
    dpm[0]=2;
    dpm[1]=2;
    for(int i=2;i<m+1;i++)
        dpm[i]=(dpm[i-1]+dpm[i-2])%1000000007;
    cout << (dpn[n]+dpm[m]-2 + 1000000007)%1000000007 << endl;
    return 0; 
}
