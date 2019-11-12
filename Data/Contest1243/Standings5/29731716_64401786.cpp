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
        int cnt[256]={0};
        unordered_map<char, unordered_set<int>> s_pos, t_pos;
    
        for(int i=0;i<n;i++){
            s_pos[s[i]].insert(i);
            t_pos[t[i]].insert(i);
            cnt[s[i]]++,cnt[t[i]]++;
        }
        bool flag=true;
        for(int i='a';i<='z';i++){
            if(cnt[i]&1)
                flag=false;
        }
        if(!flag)
            cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            cout<<2*n<<endl;
            for(int i=0;i<n;i++){
                s_pos[s[i]].erase(i);
                if(!s_pos[s[i]].empty()){
                    int j=*s_pos[s[i]].begin();
                    cout<< j+1 <<' '<< i+1<<endl;
                    cout<< i+1 <<' '<< i+1<<endl;
                    s_pos[s[i]].erase(j);
                    s_pos[t[i]].insert(j);
                    t_pos[t[i]].erase(i);
                    s[j]=t[i];
                }
                else{
                    int j=*t_pos[s[i]].begin();
                    cout<< i+1 <<' '<< i+1<<endl;
                    cout<< i+1 <<' '<< j+1<<endl;
                    t_pos[s[i]].erase(j);
                    t_pos[t[i]].insert(j);
                    t_pos[t[i]].erase(i);
                    t[j]=t[i];
                }
            }
            
        }
        
    }
        
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
