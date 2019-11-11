#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

#define LL long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)
#define FORD(i,r,l) for(int i = r; i >= l; --i)
#define REPD(i,r,l) for(int i = r; i > l; --i)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second

const int maxN = 2e5 + 11;
const LL oo = 1e17 + 11;

int T,N,a,b,c;
string s;
char A[maxN];

void testcase(){
    cin >> N >> a >> b >> c;
    cin >> s;
    //
    int cntR = 0,cntP = 0,cntS = 0;
    REP(i,0,N){
        if(s[i] == 'R') cntP += 1;
        else if(s[i] == 'P') cntS += 1;
        else cntR += 1;
    }
    //
    int countR = min(cntR,a),countP = min(cntP,b),countS = min(cntS,c);
    int win = countR + countP + countS;
    //
    int Zwin = N/2 + (N % 2);
    
    if(win < Zwin){
        cout << "NO" << endl;
        return ;
    }
    
    while(win > Zwin){
        if(countR > 0) --countR;
        else if(countP > 0) --countP;
        else --countS;
        --win;
    }

    a -= countR,b -= countP,c -= countS;
    //
    FOR(i,1,N){
        A[i] = '#';
        char c = s[i - 1];
        if(c == 'R' && countP > 0){
            A[i] = 'P';
            --countP;
        }else if(c == 'P' && countS > 0){
            A[i] = 'S';
            --countS;
        }else if(c == 'S' && countR > 0){
            A[i] = 'R';
            --countR;
        }
    }
    FOR(i,1,N){
        if(A[i] != '#') continue;
        if(a > 0){
            A[i] = 'R';
            --a;
        }else if(b > 0){
            A[i] = 'P';
            --b;
        }else if(c > 0){
            A[i] = 'S';
            --c;
        }
    }
    cout << "YES" << endl;
    FOR(i,1,N) cout << A[i];
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //

    cin >> T;
    FOR(i,1,T) testcase();

    return 0;
}