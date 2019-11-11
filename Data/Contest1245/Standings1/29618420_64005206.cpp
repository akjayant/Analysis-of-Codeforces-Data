#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<ll, ll>
#define mp make_pair
#define pb push_back
#define vi vector<ll>
#define pd pair<double, double>
#define vp vector<pi>
#define f(i, n) for(int i = 0; i < n; i++)
#define fo(i, a, n) for(int i = a; i < n; i++)
#define mod (1000*1000*1000+7)
#define sz(x) int((x).size())
#define all(x) x.begin(),x.end()
#define DBG(v) cerr << #v << " = " << (v) << endl;
ll INF = (1ll<<61);

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
      string s;
      int n; cin >> n;
      int a, b, c; cin >> a >> b >> c;
      vector<char> v(n, 0);
      int w = 0;
      string r;
      cin >> s;
      f(i, sz(s)){
        switch(s[i]){
          case 'R':
          if(b){
            v[i] = 'P';
            b--;
            w++;
          }
          break;
          case 'P':
          if(c){
            v[i] = 'S';
            c--;
            w++;
          }
          break;
          case 'S':
          if(a){
            v[i] = 'R';
            a--;
            w++;
          }
          break;
        }
      }
      f(i, sz(v)){
        if(v[i] == 0){
          if(a){
            a--; v[i] = 'R';
          }else if(b){
            v[i] = 'P';b--;
          }else v[i] = 'S';
        }
      }
      f(i, sz(v)) r.pb(v[i]);
      if(w >= (sz(s) + 1)/2){
        cout << "YES" << endl;
        cout << r << endl;
      }else cout << "NO" << endl;
    }
    return 0;
}
