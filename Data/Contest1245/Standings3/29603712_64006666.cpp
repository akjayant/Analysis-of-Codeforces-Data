#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef long long int ll;
typedef pair<int,int> pi;
typedef unsigned long long int ull;

ll lsone(ll p){return(p & -p);}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    std::ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int nn, a, b, c, suc, n;
    string ans, s;
    cin >> nn;
    a = 3;
    for (int tc=0;tc<nn;tc++){
        cin >> n;
        cin >> a >> b >> c;
        cin >> s;
        ans = "";
        suc = 0;
        for (int i=0;i<n;i++){
            suc += 1;
            if (s[i] == 'R' && b > 0){
                b -= 1;
                ans = ans + "P";
            }
            else if (s[i] == 'P' && c > 0){
                c -= 1;
                ans = ans + "S";
            }
            else if (s[i] == 'S' && a > 0){
                a -= 1;
                ans = ans + "R";
            }
            else{
                ans = ans + "U";
                suc -= 1;
            }
        }
        if (suc >= (n + 1) / 2){
            for (int i=0;i<n;i++){
                if (ans[i] == 'U'){
                    if (a > 0){
                        a -= 1;
                        ans[i] = 'R';
                    }
                    else if (b > 0){
                        b -= 1;
                        ans[i] = 'P';
                    }
                    else if (c > 0){
                        c -= 1;
                        ans[i] = 'S';
                    }
                }
            }
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
