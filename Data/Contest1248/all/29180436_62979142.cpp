#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n, m;
        cin>>n;
        int c1=0, c2=0;
        for(int a=0;a<n;a++){
            int inp;
            cin>>inp;
            if(inp&1) c1++;
            else c2++;
        }
        cin>>m;
        int d1=0, d2=0;
        for(int b=0;b<m;b++){
            int inp;
            cin>>inp;
            if(inp&1) d1++;
            else d2++;
        }
        LL hasil=c1;
        hasil*=d1;
        LL hasil2=c2;
        hasil2*=d2;
        cout<<hasil+hasil2<<endl;
    }
    return 0;
}