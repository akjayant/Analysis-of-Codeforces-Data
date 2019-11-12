#include<bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n;
    cin>>T;
    while(T--){
        string s,t;
        cin>>n>>s>>t;
        int cnt=0;
        string a,b;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                a+=s[i];
                b+=t[i];
                cnt++;
            }
        }
        if(cnt!=2){
            cout<<"No"<<endl;
        }else{
            bool flag=0;
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    string x=a;
                    string y=b;
                    swap(x[i],y[j]);
                    if(x==y) flag=1;
                }
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}