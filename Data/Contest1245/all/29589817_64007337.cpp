#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int

int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b, a %b);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin >>t;
    while(t--){
        int n;cin >> n;
        int a, b, c;cin >> a >> b >> c;
        string s; cin >> s;
        string ans = "";
        int wins = 0;
        int a1, b1, c1; 
        a1 = b1 = c1 = 0;
        
        FOR(i, s.length()){
            if(s[i] == 'R'){
               a1++; 
            }else if(s[i] == 'P')b1++;
            else c1++;
        }
        if(min(a1, b) + min(b1, c) + min(c1, a) >= (n+1)/2){
            cout << "YES" <<endl;
           
            int eb = b - min(a1, b);
            int ec = c - min(b1, c);
            int ea = a - min(c1, a);

            b -= eb;
            c -= ec;
            a -= ea;
            FOR(i, s.length()){
                if(s[i] == 'R'){
                    if(b){
                        cout << 'P';
                        b--;
                    continue;
                    }
                }
                if(s[i] == 'P'){
                    if(c){
                        cout << 'S';
                        c--;
                    continue;
                    }
                }
                if(s[i] == 'S'){
                    if(a){
                        cout << 'R';
                        a--;
                    continue;
                    }
                }
                if(ea)ea--,cout << 'R';
                else if(eb)eb--, cout << 'P';
                else ec--,  cout << 'S';
            }
            cout <<endl;
        }else cout << "NO" <<endl;
    }
}


