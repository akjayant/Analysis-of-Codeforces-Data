#include <bits/stdc++.h>  
#define N 100005
#define pb push_back
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int t,n,num[30];
string s1,s2;

int main(){
    cin>>t;
    while(t--){
        cin>>n>>s1>>s2;
        vector<pii> v;
        bool chk=true;
        for(int i=0;i<30;i++) num[i]=0;
        for(int i=0;i<n;i++){
            num[s1[i]-'a']++;
            num[s2[i]-'a']++;
        }
        for(int i=0;i<30;i++){
            if(num[i]%2){
                chk=false;
            }
        }
        if(!chk){
            cout<<"No\n";
            continue;
        }
        for(int i=0;i<2*n;i++){
            bool chk=false;
            for(int j=0;j<n;j++){
                for(int k=0;k<j;k++){
                    if(s1[j]!=s2[j]&&s1[k]!=s2[k]){
                        if(s1[j]==s1[k]||s2[j]==s2[k]){
                            v.pb({j,k});
                            swap(s1[j],s2[k]);
                            chk=true;
                        }
                        else if(s1[j]==s2[k]||s2[j]==s1[k]){
                            v.pb({j,j});
                            v.pb({j,k});
                            swap(s1[j],s2[j]);
                            swap(s1[j],s2[k]);
                            chk=true;
                        }
                    }
                    if(chk) continue;
                }
                if(chk) continue;
            }
        }
        cout<<"Yes"<<"\n";
        cout<<v.size()<<"\n";
        for(pii i:v){
            cout<<i.fi+1<<" "<<i.se+1<<"\n";
        }
    }
}