#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define int long long

using namespace std;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int maxx=n;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                maxx=max(maxx,(2*i)+2);
                maxx=max(maxx,(2*n)-(2*i));
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}
