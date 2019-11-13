#include <bits/stdc++.h>


#define mkp(i,j) make_pair(i,j)
#define int long long
#define _sz(x) (int)x.size()

using namespace std;
typedef long long ll;
const int MAX =  30;
const int LOGMAX = 105;
const int inf = 1e9;
const int md = 1e9 + 7;
typedef pair < int , int > ii;

vector <int> pos[MAX];
int position = 1;


int32_t main(){
    int t;cin>>t;
    while(t--){
        for(int i = 0;i<(MAX);i++){
            pos[i].clear();
        }
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        for(int i = 0;i<n;i++){
            pos[s[i]-'a'].push_back(i);
            pos[t[i]-'a'].push_back(i+n);
        }
        bool check = true;
        for(int i = 0;i<(MAX);i++){
            //cout<<_sz(pos[i])<<" ";
            if(_sz(pos[i])%2==1) check = false;
        }
        //cout<<endl;
        cout<<(check ? "YES" : "NO")<<endl;
        if(check == false) continue;
        vector< ii > ans;
        for(int i = 0;i<n;i++){
            char c = s[i];
            if(t[i] == c) continue;
            for(int j = i+ 1;j<n;j++){
                if(s[j] == c){
                    s[j] = t[i];
                    t[i] = c;
                    ans.push_back(mkp(j , i));
                    //cout<<"ADF "<<i<<" "<<j<<endl;
                    break;
                }
                else if(t[j] == c){
                    t[j] = s[n-1];
                    s[n-1] = c;
                    ans.push_back(mkp(n - 1 , j));
                    s[n-1] = t[i];
                    t[i] = c;
                    ans.push_back(mkp(n-1 , i));
                    //cout<<"endl "<<i<<" "<<j<<endl;
                    break;
                }
            }
        }
        //cout<<s<<" "<<t<<endl;
        cout<<_sz(ans)<<endl;
        for(int i = 0;i<_sz(ans);i++){
            cout<<ans[i].first + 1 <<" "<<ans[i].second + 1<<endl;
        }

    }

    return 0;

}
