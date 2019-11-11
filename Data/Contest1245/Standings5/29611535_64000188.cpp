#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define DIM 100007
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define mood 1000000007
#define y1 ghjhklkhkyj
#define pi 3.14159265358979323846
typedef  pair< long long, pair<long long, long long> > ppll;

long long  n,m,l,r,h,k,res1,a1,a2,w,a3,z,alln,a4,a5,a6,a7,a8,a9,a10,last,LL,timer,start,finish,flag,step,tests,kilk,curr,shift;
string s,s1,s2;
char t;
ll x,y;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>tests;
    while(tests--){
        cin>>n;
        cin>>a1>>a2>>a3;
        cin>>s;
        s1=s;
        a4=0;
        for(int i=1;i<=n;i++){
            s1[i-1]='*';
        }
        for(int i=1;i<=n;i++){
            if(s[i-1]=='R'&&a2){
                a2--;
                s1[i-1]='P';
                a4++;
            }
            if(s[i-1]=='P'&&a3){
                a3--;
                s1[i-1]='S';
                a4++;
            }
            if(s[i-1]=='S'&&a1){
                a1--;
                s1[i-1]='R';
                a4++;
            }
        }
        for(int i=1;i<=n;i++){
            if(s1[i-1]=='*'&&a2){
                a2--;
                s1[i-1]='P';
            }
            if(s1[i-1]=='*'&&a3){
                a3--;
                s1[i-1]='S';
            }
            if(s1[i-1]=='*'&&a1){
                a1--;
                s1[i-1]='R';
            }
        }
        if(a4*2>=n)cout<<"YES"<<endl<<s1<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}
