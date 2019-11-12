                       //  @ /\/\ BESH //

#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back


using namespace std;

typedef long long ll;

const int MAXN = 100001;
const int mod = 1000000007;

int main(){
    inp_out_work
    testCase{
        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        int fq[26];
        fill(fq, fq + 26, 0);
        for(char x : s)fq[x-'a']++;
        for(char x : t)fq[x-'a']++;
        bool can = 1;
        fr(i,26)if(fq[i]&1)can = 0;

        vector<pair<int,int> > ans;

        if(can)
            fr(i,n-1){
                if(t[i] == s[i])continue;
                bool kiya = 0;
                for(int j = i+1; j < s.length(); j++)if(s[j] == s[i]){
                    swap(s[j], t[i]);
                    ans.push_back({j+1, i+1});
                    kiya = 1;
                    break;
                }
                if(!kiya){
                    for(int j = i+1; j < t.length(); j++)if(t[j] == s[i]){
                        swap(s[n-1], t[j]);
                        swap(s[n-1], t[i]);
                        ans.push_back({n, j+1});
                        ans.push_back({n, i+1});
                        kiya = 1;
                        break;
                    }
                }
            }

        if(s != t || ans.size() > 2*n)can = 0;

        if(can){
                cout<<"Yes\n";
                cout<< ans.size() << endl;
                for(auto p : ans){
                    cout<< p.first<<' '<<p.second<<endl;
                }
        }
        else cout<<"No\n";
    }
}
