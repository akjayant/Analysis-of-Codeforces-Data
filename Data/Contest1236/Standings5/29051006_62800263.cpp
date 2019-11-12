#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define LL long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)

const int maxN = 301 * 301;

int N;
vector <int> G[maxN],S[maxN];

int cal(int x,int y){
    int rr = 0;
    REP(i,0,N)
        REP(j,0,N) if(G[x][i] > G[y][j]) ++rr;
    return rr;
}

int main(){
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    
    cin >> N;
    int M = 0;
    FOR(i,1,N){
        FOR(j,1,N) S[i].push_back(++M);
    }

    int l = 1,r = N;
    while(l <= r){
        if(l < r){
            REP(i,0,N){
                G[i + 1].push_back(S[l][i]);
            }
            for(int i = N - 1; i >= 0; --i) G[N - i].push_back(S[r][i]);
            ++l;
            --r;
        }else{
            REP(i,0,N){
                G[i + 1].push_back(S[l][i]);
            }
            ++l;
        }
    }

    FOR(i,1,N){
    //    cout << " ::: " ;
        REP(j,0,N) cout << G[i][j] << " ";
        cout << endl;
    }

    //int res = 1234567890;
    //FOR(i,1,N) FOR(j,i + 1,N) res = min(res,min(cal(i,j),cal(j,i)));

   // cout << res;

    return 0;
}