#include <bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x);
#define rep(x ,n) for(int x=0; x<n; x++)
#define ll long long
#define finish(x) return cout << x << endl,0;
#define scarr(a,n) for(int x=0; x<n; x++)scanf("%d",&a[x]);

#define MAX_N 2003

int main()
{
    int t;
    sc(t)
    while(t--){
        int n ,a ,b ,c;
        sc(n)sc(a)sc(b)sc(c)
        string s;
        cin >> s;

        int R = count(s.begin() ,s.end() ,'R');
        int P = count(s.begin() ,s.end() ,'P');
        int S = count(s.begin() ,s.end() ,'S');

        int to = min(a ,S) + min(c ,P) + min(b ,R);

        if(to >= (n+1)/2){
            cout << "YES" << endl;
            string ans(n ,0);
            for(int i=0; i<n; i++){
                if(s[i] == 'R' && b)
                    ans[i] = 'P' ,b--;
                else if(s[i] == 'P' && c)
                    ans[i] = 'S' ,c--;
                else if(s[i] == 'S' && a)
                    ans[i] = 'R' ,a--;
            }
            for(int i=0; i<n; i++) if(!ans[i]) {
                if(b)
                    ans[i] = 'P' ,b--;
                else if(c)
                    ans[i] = 'S' ,c--;
                else if(a)
                    ans[i] = 'R' ,a--;
            }
            cout << ans << endl;
        }
        else
            cout << "NO" << endl;

    }
}
