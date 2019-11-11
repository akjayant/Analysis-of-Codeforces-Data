#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 1e5+10;

string str;
int n,a,b,c,da,db,dc; // a:R  b:P c:S
bool check(){
    int ta = a , tta = da;
    int tb = b, ttb = db;
    int tc = c, ttc = dc;
    int win = 0,tle = 0;
    int tmp = min(ta,ttc);
    ta -= tmp, ttc -= tmp;
    win += tmp;
    tmp = min(tb,tta);
    tb -= tmp, tta -= tmp;
    win += tmp;
    tmp = min(tc,ttb);
    tc -= tmp, ttb -= tmp;
    win += tmp;
    return win >= (n+1)/2;
}
int ans[N];
int main(){
    int t;  cin >> t;
    while(t--){
        memset(ans,0,sizeof ans);
        da = db = dc = 0;
        cin >> n;
        cin >> a >> b >> c;
        cin >> str;
        for(int i=0;i<n;++i){
            if(str[i]=='R') da++;
            else if(str[i]=='P') db++;
            else if(str[i]=='S') dc++;
        }
        if(check()){
            cout <<"YES\n";
            for(int i=0;i<n;++i){
                if(str[i]=='R'){
                    if(b){
                        ans[i] = 2;
                        b--;
                    }
                }else if(str[i]=='P'){
                    if(c){
                        ans[i] = 3;
                        c--;
                    }
                }else{
                    if(a){
                        ans[i] = 1;
                        a--;
                    }
                }
            }
            for(int i=0;i<n;++i){
                if(ans[i]==0){
                    if(a){
                        ans[i] = 1;
                        a--;
                    }else if(b){
                        ans[i] = 2;
                        b--;
                    }else{
                        ans[i] = 3;
                        c--;
                    }
                }
            }
            for(int i=0;i<n;++i){
                if(ans[i]==1)   cout <<'R';
                else if(ans[i]==2)  cout <<'P';
                else if(ans[i]==3)  cout <<'S';
            }cout <<'\n';
        }else{
            puts("NO");
        }
    }





    return 0;
}