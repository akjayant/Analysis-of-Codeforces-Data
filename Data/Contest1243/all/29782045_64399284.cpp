#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int k,n;
    string s,t;
    vector<pair<int,int>> v;
    cin>>k;
    int flag;
    char c;
    while(k--){
        cin>>n;
        cin>>s>>t;
        flag=1;
        v.clear();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                flag=0;
                for(int j=i+1;flag==0 && j<n;j++){
                    if(s[i]==s[j]){
                        v.emplace_back(j,i);
                        c=s[j];
                        s[j]=t[i];
                        t[i]=c;
                        flag=1;
                    }
                    else{
                        if(s[i]==t[j]){
                            v.emplace_back(j,j);
                            c=s[j];
                            s[j]=t[j];
                            t[j]=c;
                            v.emplace_back(j,i);
                            c=s[j];
                            s[j]=t[i];
                            t[i]=c;
                            flag=1;
                        }
                    }
                }
                if(flag==0) break;
            }
        }
        if(flag){
            cout<<"Yes\n";
            cout<<v.size()<<"\n";
            for(pair<int,int> p:v){
                cout<<p.first+1<<" "<<p.second+1<<"\n";
            }
        }
        else cout<<"No\n";
    }
    return 0;
}
