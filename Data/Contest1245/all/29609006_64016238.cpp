#include<bits/stdc++.h>

using namespace std;
int ans[105];

int main(){
    int T;
    cin>>T;
    while(T--){
        memset(ans, -1, sizeof(ans));
        int n, a, b, c;
        string s;
        cin>>n>>a>>b>>c>>s;
        int aa = count(s.begin(),s.end(),'R');
        int bb = count(s.begin(),s.end(),'P');
        int cc = count(s.begin(),s.end(),'S');
        int num = ceil(n*1.0/2);
        int cnt = (min(aa,b)+min(bb,c)+min(cc,a));
        if(cnt < num) cout<<"NO"<<endl;
        else{
            int a1 = a, a2 = b, a3 = c;
            cout<<"YES"<<endl;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == 'S' && a > 0)  a--, ans[i] = 1;
                else if(s[i] == 'R' && b > 0)  b--, ans[i] = 2;
                else if(s[i] == 'P' && c > 0) c--, ans[i] = 3;
                else ans[i] = 0;
            }
            for(int i = 0; i < n; i++){
                if(ans[i] == 1) cout<<"R";
                else if(ans[i] == 2) cout<<"P";
                else if(ans[i] == 3) cout<<"S";
                else{
                    if(a > 0) cout<<"R", a--;
                    else if(b > 0) cout<<"P", b--;
                    else if(c > 0) cout<<"S", c--;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
