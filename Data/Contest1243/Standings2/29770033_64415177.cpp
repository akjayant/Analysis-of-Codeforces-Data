#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int k,n;
string s,t;
vector<pair<int,int>> vec;
int main(){
    cin>>k;
    while(k--){
        cin>>n;
        cin>>s>>t;
        bool ok=true;
        vec.clear();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                bool flag=false;
                for(int j=i+1;j<n;j++){
                    if(s[j]==s[i]){
                        swap(s[j],t[i]);
                        vec.push_back(make_pair(j,i));
                        flag=true;
                        break;
                    }
                    if(t[j]==t[i]){
                        swap(s[i],t[j]);
                        vec.push_back(make_pair(i,j));
                        flag=true;
                        break;
                    }
                    if(s[i]==t[j]){
                        swap(s[i],t[i]);
                        swap(s[i],t[j]);
                        vec.push_back(make_pair(i,i));
                        vec.push_back(make_pair(i,j));
                        flag=true;
                        break;
                    }
                    if(t[i]==s[j]){
                        swap(s[i],t[i]);
                        swap(s[j],t[i]);
                        vec.push_back(make_pair(i,i));
                        vec.push_back(make_pair(j,i));
                        flag=true;
                        break;
                    }
                }
                if(flag==false){
                    cout<<"No"<<endl;
                    ok=false;
                    break;
                }
                
            }
        }
        if(ok){
            cout<<"Yes"<<endl;
            cout<<vec.size()<<endl;
            for(auto x:vec){
                cout<<x.first+1<<" "<<x.second+1<<endl;
            }
        }
    }
    return 0;
}