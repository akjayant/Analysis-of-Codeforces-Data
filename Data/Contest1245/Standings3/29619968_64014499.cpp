

#include<bits/stdc++.h>
#define debug(x) cerr << "[" << #x <<": " << (x) <<"]"<< endl
#define pii pair<int,int>
#define clr(a, b) memset((a),b,sizeof(a))
#define rep(i, a, b) for(int i = a;i < b;i ++)
#define pb push_back
#define MP make_pair
#define LL long long
#define ull unsigned LL
#define ls i << 1
#define rs (i << 1) + 1
#define fi first
#define se second
#define ptch putchar
#define CLR(a) while(!(a).empty()) a.pop()

using namespace std;

#ifndef ONLINE_JUDGE
clock_t prostart = clock();
#endif

int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    int t; scanf("%d",&t);
    while(t --){
        int n; scanf("%d",&n);
        int a,b,c; scanf("%d%d%d",&a,&b,&c);    //石头布剪刀
        string s; cin >> s;
        int p1 = 0,p2 = 0,p3 = 0;               //石头布剪刀
        for(int i = 0;i < s.size();++ i){
            if(s[i] == 'R') ++ p1;
            else if(s[i] == 'P') ++ p2;
            else ++ p3;
        }
        int ans = min(p1,b) + min(p2,c) + min(p3,a);
        if(ans >= (int)ceil(n * 1.0 / 2)){
            char ss[110] = {0};
            for(int i = 0;i < s.size();++ i) ss[i] = '1';
            for(int i = 0;i < s.size();++ i){
                if(s[i] == 'R'){
                    if(b > 0){
                        -- b;
                        ss[i] = 'P';
                    }
                }
                else if(s[i] == 'P'){
                    if(c > 0){
                        -- c;
                        ss[i] = 'S';
                    }
                }
                else {
                    if(a > 0){
                        -- a;
                        ss[i] = 'R';
                    }
                }
            }
            for(int i = 0;i < s.size();++ i){
                if(ss[i] == '1'){
                    if(a > 0) -- a,ss[i] = 'R';
                    else if(b > 0) -- b,ss[i] = 'P';
                    else -- c,ss[i] = 'S';
                }
            }
            puts("YES");
            for(int i = 0;i < s.size();++ i) printf("%c",ss[i]); printf("\n");
        }
        else puts("NO");
    }

#ifndef ONLINE_JUDGE
    cerr << "time: " << 1.0 * (clock() - prostart) / CLOCKS_PER_SEC << " s" << endl;
#endif
    return 0;
}

