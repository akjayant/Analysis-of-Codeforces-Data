#include <bits/stdc++.h>  
#define N 100005
#define pb push_back
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int t,n,a[N];
string s1,s2;

int main(){
    cin>>t;
    while(t--){
        cin>>n>>s1>>s2;
        vector<int> v;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                v.pb(i);
                cnt++;
            } 
        }
        if(cnt>2||cnt==0){
            cout<<"No\n";
        }
        else if(cnt==1){
            cout<<"No\n";
        }
        else{
            if((s1[v[0]]==s1[v[1]])&&(s2[v[0]]==s2[v[1]])){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
    return 0;
}