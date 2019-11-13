#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define PB push_back
#define LL long long
#define pii pair<int,int>
#define MEM(x,y) memset(x,y,sizeof(x))
#define bug(x) cout<<"debug "#x" is "<<x<<endl;
#define FIO ios::sync_with_stdio(false);
#define ALL(x) x.begin(),x.end()
#define LOG 20
const int inf =1e9;
const int maxn =3e5+7;
const int mod = 1e9+7;

int main(){
    FIO;
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c;
        string s,ans;
        cin>>n>>a>>b>>c>>s;
        ans=s;
        int f=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='R'){
                if(b){
                    b--;
                    ans[i]='P';
                    f++;
                }
                else ans[i]='X';
            }
            else if(ch=='P'){
                if(c){
                    c--;
                    ans[i]='S';
                    f++;
                }
                else ans[i]='X';
            }
            else{
                if(a){
                    a--;
                    ans[i]='R';
                    f++;
                }
                else ans[i]='X';
            }
        }
        //bug(f)
        if(f>=((n+1)/2)){
            for(int i=0;i<n;i++){
                char ch=ans[i];
                if(ch=='X'){
                    if(a){
                        a--;ans[i]='R';
                    }
                    else if(b){
                        b--;ans[i]='P';
                    }
                    else{
                        c--;ans[i]='S';
                    }
                }
            }
            cout<<"YES\n"<<ans<<endl;
        }
        else{
            cout<<"NO\n";
        }


    }
    return 0;
}


