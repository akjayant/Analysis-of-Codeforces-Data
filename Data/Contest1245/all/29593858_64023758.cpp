#include <bits/stdc++.h>
using namespace std;
#define sc(x)            scanf("%d",&x)
#define scc(x)           scanf("%c",&x)
#define scl(x)           scanf("%lld",&x)
#define sz(v)	     	(v.size())
#define mem(v, d)		memset(v, d, sizeof(v))
#define oo				2000000100
#define OO				2000000000000000100
#define PI 3.14159265
#define s second
#define f first
#define Ceil(x,y) ((x+y-1)/y)
#define EPS 1e-8
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const double pi=3.14159265358979323846264338327950288419716939937510582097494459;
typedef unsigned int uint;
typedef long long ll;
int dX[] = {0,1,0,-1};
int dY[] = {1,0,-1,0};
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int N = 100100;
const int MOD = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
#else
    //freopen("reduce.in","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    int x,y,t;
    sc(t);
    while(t--){
        int a,b,c,n; sc(n);
        sc(a); sc(b); sc(c);    // R - P - S
        int score = 0;
        string str,out; cin>>str;
        for(auto ch:str){
            if(ch == 'R' && b) out+='P',b--,score++;
            else if(ch == 'P' && c) out+='S',c--,score++;
            else if(ch == 'S' && a) out+='R',a--,score++;
            else out+='?';
        }
        if(score*2>=n){
            puts("YES");
            for(auto x:out){
                if(x == '?'){
                    if(a) printf("R"),a--;
                    else if(b) printf("P"),b--;
                    else if(c) printf("S"),c--;
                }
                else printf("%c",x);
            }
            puts("");
        }
        else puts("NO");
    }
    return 0;
}
