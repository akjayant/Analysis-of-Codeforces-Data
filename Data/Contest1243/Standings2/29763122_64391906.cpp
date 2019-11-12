#include<bits/stdc++.h>
using namespace std;
int n1,n;
string s,t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n1;
    while(n1--){
        cin>>n;
        cin>>s;
        cin>>t;
        int dif[3],ok=1,d=0;
        for(int i=0;i<n;i++){
            //cout<<i<<endl;
            if(s[i]!=t[i]){
                d++;
                if(d>2) {cout<<"No"<<endl;ok=0;break;}
                dif[d]=i;
                }
            }
        if(ok==0) continue;
        if(d<2) {cout<<"No"<<endl;continue;}
        //cout<<dif[1]<<" "<<dif[2]<<endl;
        if(s[dif[1]]==s[dif[2]] && t[dif[1]]==t[dif[2]]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}
