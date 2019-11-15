#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,fre[100],f;
string s,t;
vector<pair<int,int>>v;
int main(){
    cin>>T;
    while(T--){
        for(int i=0;i<30;i++)fre[i]=0;
        v.clear();
        f=0;
        cin>>n>>s>>t;
        for(int i=0;i<n;i++){
            fre[s[i]-'a']++;
            fre[t[i]-'a']++;
        }
        for(int i=0;i<30;i++){
            if(fre[i]%2)f=1;
        }
        if(f)cout<<"No\n";
        else {/*
            abc
            bca*/
            for(int i=0;i<n;i++){
                f=0;
                if(s[i]!=t[i]){
                    for(int j=i+1;j<n;j++){
                        if(s[i]==s[j]){
                            swap(s[j],t[i]);
                            v.push_back({j,i});
                            f=1;
                            break;
                        }
                    }
                    if(f)continue;
                    for(int j=i+1;j<n;j++){
                        if(t[i]==t[j]){
                            swap(s[i],t[j]);
                            v.push_back({i,j});
                            f=1;
                            break;
                        }
                    }
                    if(f)continue;
                    swap(s[i],t[i]);
                    v.push_back({i,i});
                    for(int j=i+1;j<n;j++){
                        if(s[i]==s[j]){
                            swap(s[j],t[i]);
                            v.push_back({j,i});
                            f=1;
                            break;
                        }
                    }
                    if(f)continue;
                    for(int j=i+1;j<n;j++){
                        if(t[i]==t[j]){
                            swap(s[i],t[j]);
                            v.push_back({i,j});
                            f=1;
                            break;
                        }
                    }
                }
            }
            cout<<"Yes\n"<<v.size()<<endl;
            for(int i=0;i<v.size();i++)cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
        }
    }
}
