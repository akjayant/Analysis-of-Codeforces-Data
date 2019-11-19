#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define for0(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define int long long

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

 int n, m, k, x, y;


signed main(){
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    vector<set<int> > str(n+1), stb(m+1);

//    for(int i = 1; i <= n; i++){
//        strto[i].insert(0);
//        strd[i].insert(m+1);
//    }
//
//    for(int i = 1; i <= m; i++){
//        stbto[i].insert(0);
//        stbd[i].insert(n+1);
//    }

    for(int i = 0; i < k; i++){
        cin >> x >> y;
        str[x].insert(y);
        stb[y].insert(x);
    }

    int stmx = m+1, stmn = 0, sbmx = n+1, sbmn = 0;
    int tx = 1, ty = 1, np = 3;
    ll ans = 0;


   // for(int i = 0; i < 7; i++)

        while(1)
        {
        np = (np+1)%4;

        if(np == 0){
            str[tx].insert(ty);
            set<int>::iterator t = str[tx].find(ty);
            t++;
            int gty;
            if(t == str[tx].end()) gty = m+1; else gty = *t;
            gty = min(gty, stmx);
           // cout<<"np = "<<np<<"  gty = "<<gty<<endl;
            ans += (gty-ty-1);
            stmx = gty-1;
            sbmn = max(sbmn, tx);
            str[tx].erase(ty);
            ty = gty-1;
//               cout<<"tx = "<<tx<<"   ty = "<<ty<<endl;
//               cout<<"stmx = "<<stmx<<"   stmn = "<<stmn<<"   sbmx = "<<sbmx<<"   sbmn = "<<sbmn<<endl;
//
//               cout<<endl;

               if(stmx == stmn) break;
        }

        if(np == 2){
            str[tx].insert(ty);
            set<int>::iterator t = str[tx].find(ty);

            int gty;
            if(t == str[tx].begin()) gty = 0; else{t--; gty = *t;}

            gty = max(gty, stmn);
            //cout<<"np = "<<np<<"  gty = "<<gty<<endl;
            ans += (ty - gty-1);
            stmn = gty+1;
            sbmx = min(sbmx, tx);
            str[tx].erase(ty);
            ty = gty+1;

//            cout<<"tx = "<<tx<<"   ty = "<<ty<<endl;
//              cout<<"stmx = "<<stmx<<"   stmn = "<<stmn<<"   sbmx = "<<sbmx<<"   sbmn = "<<sbmn<<endl;
//
//               cout<<endl;
               if(stmx == stmn) break;
        }

        if(np == 1){
            stb[ty].insert(tx);
            set<int>::iterator t = stb[ty].find(tx);
            t++;
            int gtx;
            if(t == stb[ty].end()) gtx = n+1; else gtx = *t;
            gtx = min(gtx, sbmx);
         //   cout<<"np = "<<np<<"  gtx = "<<gtx<<endl;
            ans += (gtx-tx-1);
            sbmx = gtx-1;
            stmx = min(stmx, ty);
            stb[ty].erase(tx);
            tx = gtx-1;
//               cout<<"tx = "<<tx<<"   ty = "<<ty<<endl;
//                 cout<<"stmx = "<<stmx<<"   stmn = "<<stmn<<"   sbmx = "<<sbmx<<"   sbmn = "<<sbmn<<endl;
//
//                  cout<<endl;
                  if(sbmx == sbmn) break;
        }

        if(np == 3){
            stb[ty].insert(tx);
            set<int>::iterator t = stb[ty].find(tx);

            int gtx;
            if(t == stb[ty].begin()) gtx = 0; else{t--; gtx = *t;}

            gtx = max(gtx, sbmn);
           // cout<<"np = "<<np<<"  gtx = "<<gtx<<endl;
            ans += (tx - gtx-1);
            sbmn = gtx+1;
            stmn = max(stmn, ty);
            stb[ty].erase(tx);
            tx = gtx+1;
//               cout<<"tx = "<<tx<<"   ty = "<<ty<<endl;
//                 cout<<"stmx = "<<stmx<<"   stmn = "<<stmn<<"   sbmx = "<<sbmx<<"   sbmn = "<<sbmn<<endl;
//
//                  cout<<endl;
                  if(sbmx == sbmn) break;
        }

 //cout << ans<<endl;
    }

 ans++;
// cout<<ans<<endl;

 if(ans == n*m - k) cout <<"Yes"; else cout << "No";

}

