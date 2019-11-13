#include <bits/stdc++.h>
using namespace std;
int n,k;
string s,t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>k;
    while(k--){
        cin>>n>>s>>t;
        vector<pair<int,int>>ops;
        map<char,int>mp;
        for(auto el:s)mp[el]++;
        for(auto el:t)mp[el]++;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                bool bo=0;
                for(int j=i+1;j<n;j++){
                    if(s[j]==s[i]){
                        char c1=s[j],c2=t[i];
                        s[j]=c2;t[i]=c1;
                        ops.push_back({j,i});
                        bo=1;
                        break;
                    }
                }
                if(!bo){
                    for(int j=i+1;j<n;j++){
                        if(t[j]==s[i]){
                            char c1=s[i+1],c2=t[j];
                            s[i+1]=c2;t[j]=c1;
                            ops.push_back({i+1,j});
                            c1=s[i+1],c2=t[i];
                            s[i+1]=c2;t[i]=c1;
                            ops.push_back({i+1,i});
                            break;
                        }
                    }
                }
            }
        }
        if(s!=t || ops.size()>2*n){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        cout<<ops.size()<<endl;
        for(auto el:ops){
            cout<<el.first+1<<' '<<el.second+1<<endl;
        }
    }
    return 0;
}
