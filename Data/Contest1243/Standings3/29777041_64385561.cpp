#include<bits/stdc++.h>
using namespace std;
int c[100005];
int main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n,cnt=0;cin >> n;
        string a,b;cin >> a >> b;
        //memset(jl,0,sizeof(jl));
        for (int i=0;i<n;i++){
            if(a[i]!=b[i]){
                c[cnt++]=i;
            }
        }
        if(cnt!=2) cout << "NO" <<endl;
        else {
            if(a[c[0]]==a[c[1]]&&b[c[0]]==b[c[1]]) cout << "YES" <<endl;
            else cout << "NO" <<endl;
        }
        /*int flag=0;
        for (int i=0;i<26;i++){
            if(jl[i]&1) flag=1;
        }
        if(flag)
        else cout << "YES" <<endl;*/
    }
    return 0;
}
