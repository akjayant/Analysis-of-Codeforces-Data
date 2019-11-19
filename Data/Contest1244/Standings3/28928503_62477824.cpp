#include<bits/stdc++.h>
using namespace std;
const int MX = 1009;
long double ans[MX];


int main() {
    // freopen("exptree.in","r",stdin);
    long long n , score , W , D;
    cin>>n>>score>>W>>D;

    set < long long > S;
    long long x = score;
    long long cnt = 0 , atleast = -1;
    while(1){
        if(S.count(x % D)){
            puts("-1");
            return 0;
        }
        S.insert(x % D);
        if(x % D == 0){
            atleast = cnt;
            break;
        }
        x -= W;
        ++cnt;
        if(x < 0) break;
    }
    if(atleast == -1){
        puts("-1");
        return 0;
    }
    long long win = atleast , rem = score - atleast * W;

    long long cycle = ( (W * D)/__gcd(W , D) ) / W;

    long long more = rem/(cycle * W);

    win += more * cycle;

    rem -= more * cycle * W;

    long long draw = rem / D;

    //cout<<win<<' '<<draw<<' '<<atleast<<' '<<cycle<<endl;
    if(win + draw > n) puts("-1");
    else {
        cout<<win<<' '<<draw<<' '<<n - win - draw<<endl;
        assert(win * W + draw * D == score);
    }

 //   cout<<win * W + draw * D<<endl;
}
