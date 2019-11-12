// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], t;
string s2, s1;
char ch1, ch2;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n;
        cin >> s1;
        cin >> s2;
        LL kq = 0, kt = 1;
        for(int i = 0 ; i < n ; ++i)
        if(s1[i] != s2[i]){
            kq++;
            if(kq == 1){
                ch1 = s1[i];
                ch2 = s2[i];
            }
            if(kq == 2){
                if(s1[i] != ch1 || s2[i] != ch2){
                    kt = 0;
                    break;
                }
            }
            if(kq > 2){
                kt = 0;
                break;
            }
        }
        if(kq < 2) kt = 0;
        if(kt) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}