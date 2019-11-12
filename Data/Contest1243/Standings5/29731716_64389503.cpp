#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int pos1=-1, pos2=-1;
        bool flag = true;
        for(int i=0;i<n&&flag;i++){
            if(s[i]!=t[i]){
                if(pos1==-1){
                    pos1=i;
                }
                else if(pos2==-1){
                    pos2=i;
                }
                else{
                    flag=false;
                }
            }
        }
        if(pos1==-1){
            cout<<"Yes"<<endl;
        }
        else if(!flag||pos2==-1){
            cout<<"No"<<endl;
        }
        else{
            if(s[pos1]==s[pos2]&&t[pos2]==t[pos1])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}