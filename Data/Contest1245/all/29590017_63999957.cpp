//⣿⣿⣿⣿⣿⣿⠟⠋⠁⣀⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿
//⣿⣿⣿⣿⠋⠁⠀⠀⠺⠿⢿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⣿
//⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣤⣤⠀⠀⠀⠀⠀⣤⣦⣄⠀⠀
//⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⠏⣿⣿⣿⣿⣿⣁⠀⠀⠀⠛⠙⠛⠋⠀⠀
//⡿⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⣰⣿⣿⣿⣿⡄⠘⣿⣿⣿⣿⣷⠄⠀⠀⠀⠀⠀⠀⠀⠀
//⡇⠀⠀⠀⠀⠀⠀⠀⠸⠇⣼⣿⣿⣿⣿⣿⣷⣄⠘⢿⣿⣿⣿⣅⠀⠀⠀⠀⠀⠀⠀⠀
//⠁⠀⠀⠀⣴⣿⠀⣐⣣⣸⣿⣿⣿⣿⣿⠟⠛⠛⠀⠌⠻⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣶⣮⣽⣰⣿⡿⢿⣿⣿⣿⣿⣿⡀⢿⣤⠄⢠⣄⢹⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣿⣿⣿⣿⣿⡘⣿⣿⣿⣿⣿⣿⠿⣶⣶⣾⣿⣿⡆⢻⣿⣿⠃⢠⠖⠛⣛⣷⠀
//⠀⠀⢸⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣮⣝⡻⠿⠿⢃⣄⣭⡟⢀⡎⣰⡶⣪⣿⠀
//⠀⠀⠘⣿⣿⣿⠟⣛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⡿⢁⣾⣿⢿⣿⣿⠏⠀
//⠀⠀⠀⣻⣿⡟⠘⠿⠿⠎⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣵⣿⣿⠧⣷⠟⠁⠀⠀
//⡇⠀⠀⢹⣿⡧⠀⡀⠀⣀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⢰⣿⠀⠀⠀⠀
//⡇⠀⠀⠀⢻⢰⣿⣶⣿⡿⠿⢂⣿⣿⣿⣿⣿⣿⣿⢿⣻⣿⣿⣿⡏⠀⠀⠁⠀⠀⠀⠀
//⣷⠀⠀⠀⠀⠈⠿⠟⣁⣴⣾⣿⣿⠿⠿⣛⣋⣥⣶⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⣿ 
//⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//⣿⠛⣷⠀⠀⢸⣟⡛⠀⠀⣿⠛⣷⠀⠀⢸⣟⡛⠀⠀⣴⢟⣛⡀⠀⠀⣸⢿⣇⠀ 
//⣿⠉⠉⠀⠀⢸⣯⣥⠀⠀⣿⠉⠉⠀⠀⢸⣯⣥⠀⠀⢿⣮⣽⡇⠀⢠⡿⠶⣿⡄ 
#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 300309
#define MAXM 900009
#define MAXLOGN 20
#define ALFA 256
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define pr printf
#define sc(x) scanf("%d", &x)
#define sc2(x, y) sc(x);sc(y)
#define sc3(x, y, z) sc2(x, y);sc(z)
#define scll(x) scanf("%lld", &x)
#define sc2ll(x, y) scll(x);scll(y)
#define sc3ll(x, y, z) sc2ll(x, y);scll(z)
#define ff first
#define ss second
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x))
#define LOWBIT(A) (A & -A)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair <ll, ll> pll;
typedef pair < pll, ll > plll;

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        sc(n);
        int a, b, c;
        sc3(a, b, c);
        string s;
        cin >> s;
        int ba, bb, bc;
        ba = bb = bc = 0;
        FOR(i, sz(s)){
            if(s[i] == 'R')ba++;
            if(s[i] == 'P')bb++;
            if(s[i] == 'S')bc++;
        }
        int wins = min(ba, b) + min(bb, c) + min(bc, a);
        if(wins >= (n / 2 + (n%2))){
            pr("YES\n");
            int rock = min(bc, a);
            int paper = min(ba, b);
            int sci = min(bb, c);
            a -= rock;
            b -= paper;
            c -= sci;
            FOR(i, sz(s)){
                if(s[i] == 'R'){
                    if(paper){
                        pr("P");
                        paper--;
                    }else{
                        if(a){
                            a--;
                            pr("R");
                        }else{
                            c--;
                            pr("S");
                        }
                    }
                }
                if(s[i] == 'P'){
                    if(sci){
                        pr("S");
                        sci--;
                    }else{
                        if(a){
                            a--;
                            pr("R");
                        }else{
                            b--;
                            pr("P");
                        }
                    }
                }
                if(s[i] == 'S'){
                    if(rock){
                        pr("R");
                        rock--;
                    }else{
                        if(c){
                            c--;
                            pr("S");
                        }else{
                            b--;
                            pr("P");
                        }
                    }
                }
            }
            pr("\n");
        }else pr("NO\n");
    }
    return 0;
} 
