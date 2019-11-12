/// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

int n;
char s[100], t[100];
vector<pi> wynik;

int fors(int i){
    int tmp = i;
    int res = 0; ++i;

    for (;i<n; ++i){
        if (s[i] == s[tmp]){
            swap(s[i],t[tmp]);
            wynik.push_back({i,tmp});
            return 1;
        }
    }
    return 0;
}

int fort(int i){
    int tmp = i;
    int res = 0; ++i;
    for (;i<n; ++i){
        if (t[i] == t[tmp]){
            swap(t[i],s[tmp]);
            wynik.push_back({tmp,i});
            return 1;
        }
    }
    return 0;
}

int forr(int i){
    int tmp = i; ++i;
    for (;i<n; ++i){
        if (t[i] == s[tmp]){
            swap(s[i],t[i]);
            wynik.push_back({i,i});
            break;
        }
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        wynik.clear();
        cin >> n; int xxx = 0;
        cin >> s >> t;
        for (int i=0; i<n; ++i){
            if (s[i] == t[i]) continue;
            if (forr(i)){
                xxx++;
            }
            else if (fors(i)) {
                xxx++;
                //cout << "XD" << endl;
            }
            else if (fort(i)) {
                xxx++;
            }
            else {
                xxx = -1;
                cout << "No\n";
                break;
            }
        }

        if (xxx != -1){
            cout << "Yes\n";
            cout << wynik.size()<< endl;
            for (auto u:wynik)
                cout << u.F+1 << ' ' << u.S+1 << endl;
        }


    }



}
