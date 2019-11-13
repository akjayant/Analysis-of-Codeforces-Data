#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
set<lld> use[301];
int main()
{
     ios;
     lld TESTS,a,b,c,n,p,w,d,m,x,i,y,z;
     TESTS=1;
     while(TESTS--)
     {
         cin>>n;
         lld cur=1;
         lld doo=1;
         rep(i,1,n){
            if (doo%2==1){
            rep(i,1,n){
                use[i].insert(cur);
                cur++;
            }
            }
            else {
                repr(i,n,1){
                    use[i].insert(cur);
                    cur++;
                }
            }
            doo=1-doo;
         }
         rep(i,1,n){
            for (set<lld>::iterator it=use[i].begin();it!=use[i].end();it++) cout<<*it<<" ";
            cout<<"\n";
         }
     }
    return 0;
}
