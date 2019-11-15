#include <bits/stdc++.h>
using namespace std;
int n,k;
string s,t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        cin>>k;
        cin>>s>>t;
        int co=0;
        vector<char>c1,c2;
        for(int i=0;i<k;i++){
            if(s[i]!=t[i]){
                    co++;
                    c1.push_back(s[i]);
                    c2.push_back(t[i]);
            }
        }
        if(co==0)cout<<"Yes"<<'\n';
        else if(co==2){
            if(c1[0]==c1[1]&&c2[0]==c2[1])cout<<"Yes"<<'\n';
            else cout<<"No"<<'\n';
        }
        else cout<<"No"<<'\n';
    }
    return 0;
}
