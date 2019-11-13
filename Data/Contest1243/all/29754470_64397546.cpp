#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10, mod=1e9+7;
int tc, n, tot[26], cnt[26][2];
string s[2];
vector<pair<int,int>> res;
void swp(int i, int j){
    cnt[s[0][i]-'a'][0]--, cnt[s[1][j]-'a'][0]++;
    cnt[s[1][j]-'a'][1]--, cnt[s[0][i]-'a'][1]++;
    char c=s[0][i];
    s[0][i]=s[1][j];
    s[1][j]=c;
    res.push_back({i+1,j+1});
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n>>s[0]>>s[1];
        for(int i=0;i<26;i++) tot[i]=cnt[i][0]=cnt[i][1]=0;
        for(int i=0;i<n;i++){
            cnt[s[0][i]-'a'][0]++;
            cnt[s[1][i]-'a'][1]++;
            tot[s[0][i]-'a']++;
            tot[s[1][i]-'a']++;
        }
        bool ok=1;
        for(int i=0;i<26;i++){
            if(tot[i]%2) ok=0;
        }
        if(!ok){
            cout<<"No\n";
            continue;
        }
        for(int i=0;i<n;i++){
            if(s[0][i]!=s[1][i]){
                int I=-1;
                for(int j=i+1;j<n;j++){
                    if(s[0][j]==s[0][i]){
                        I=j;
                        break;
                    }
                }
                if(I!=-1){
                    swp(I, i);
                    continue;
                }
                else{
                    int J=-1;
                    for(int j=i+1;j<n;j++){
                        if(s[1][j]==s[1][i]){
                            J=j;
                            break;
                        }
                    }
                    if(J!=-1){
                        swp(i, J);
                        continue;
                    }
                    else{
                        swp(i, i);
                        i--;
                        continue;
                    }
                }
            }
        }
        cout<<"Yes\n";
        cout<<(int)res.size()<<'\n';
        for(pair<int,int> x:res) cout<<x.first<<' '<<x.second<<'\n';
        res.clear();
    }
    return 0;
}
