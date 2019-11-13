#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define eps 1e-5

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

char v[110];
int main(){
   int t;
   cin >> t;
   while(t--) {
      int n, a, b, c;
      cin >> n >> a >> b >> c;
      string s;
      cin >> s;
      int ret = 0;
      for(int i = 0; i < n; i++)
         v[i] = 'X';
      for(int i = 0; i < n;i++){
         char x = s[i];
         if(x == 'R'){
            if(b>0){
               b--;
               ret++;
               v[i] = 'P';
            }
         }
         if(x == 'P'){
            if(c>0){
               c--;
               ret++;
               v[i] = 'S';
            }
         }
         if(x == 'S'){
            if(a>0){
               a--;
               ret++;
               v[i] = 'R';
            }
         }
      }
      for(int i = 0; i < n; i++){
         if(v[i] == 'X'){
            if(a>0){
               a--;
               v[i] = 'R';
            }
            else if(b>0){
               b--;
               v[i] = 'P';
            }
            else if(c>0){
               c--;
               v[i] = 'S';
            }
         }
      }
      if(ret >= (n+1)/2) {
         cout << "YES" << endl;
         for(int i = 0; i < n; i++)
            cout << v[i];
         cout<<endl;
      }
      else cout <<"NO"<<endl;
   }
   exit(0);
}
