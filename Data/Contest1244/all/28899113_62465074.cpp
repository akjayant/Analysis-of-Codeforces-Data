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
        float a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int num=ceil(a/c)+ceil(b/d);
        if(num>k){
            cout<<-1<<endl;
        }
        else{
            cout<<ceil(a/c)<<" "<<ceil(b/d)<<endl;
        }
    }
    return 0;
}
