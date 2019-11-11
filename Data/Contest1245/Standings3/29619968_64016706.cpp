

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

int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a % b);
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    int t; scanf("%d",&t);
    while(t --){
        int a,b; scanf("%d%d",&a,&b);
        if(gcd(a,b) != 1) puts("Infinite");
        else puts("Finite");
    }

#ifndef ONLINE_JUDGE
    cerr << "time: " << 1.0 * (clock() - prostart) / CLOCKS_PER_SEC << " s" << endl;
#endif
    return 0;
}