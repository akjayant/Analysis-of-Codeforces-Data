#include <bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

long long bruteforce(int i, int j, vector<vector<int> > &current) {
    if(i >= current.size()) {
        for(int c=0;c<current.size();c++) {
            for(int c2=0;c2<current[c].size();c2++) {
                int neigh = 0;
                for(int d=0;d<4;d++) {
                    int x2 = c + dx[d];
                    int y2 = c2 + dy[d];
                    if(x2 < 0 || y2 < 0 || x2 >= current.size() || y2 >= current[x2].size()) {
                        continue;
                    }
                    if(current[x2][y2] == current[c][c2]) neigh++;
                }
                if(neigh > 1) return 0;
            }
        }
        return 1;
    }

    long long res = 0;

    for(int val = 0; val <= 1; val++) {
        current[i][j] = val;
        res += bruteforce(i+(j+1)/current[i].size(), (j+1)%current[i].size(),current);
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);



    long long n;
    cin>>n;
    long long m;
    cin>>m;
    if(n < m) swap(n,m);
    vector<vector<vector<long long> > > dp(2,vector<vector<long long> > (2,vector<long long>(n+1,0)));
    vector<long long> res(n+1,0);
    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    res[0]=2;
    long long mod = 1e9+7;
    for(int c=1;c<n;c++) {
        dp[0][0][c] = (dp[1][1][c-1] + dp[1][0][c-1])%mod;
        dp[0][1][c] = dp[0][0][c-1];
        dp[1][0][c] = (dp[0][1][c-1] + dp[0][0][c-1])%mod;
        dp[1][1][c] = dp[1][0][c-1];
        res[c] += dp[0][0][c] + dp[0][1][c] + dp[1][0][c] + dp[1][1][c];
        res[c] %= mod;
    }
 //   vector<vector<int> > current(n,vector<int>(m,0));
  /*  for(int c=1;c<=5;c++) {
        for(int c2=1;c2<=5;c2++) {
            vector<vector<int> > v(c,vector<int>(c2,0));
            cout<<c<<" "<<c2<<" "<<bruteforce(0,0,v)<<" "<<(res[c2-1]+res[c-1]-2+mod)%mod<<endl;
        }
    }
*/
    cout<<(res[n-1]+res[m-1]-2+mod)%mod;

}
