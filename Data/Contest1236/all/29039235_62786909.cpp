#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#define fir first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define cl(a,b) memset(a,b,sizeof(a))
#define quickio(a) ios::sync_with_stdio(a)
#define datatest() freopen("data.in","r",stdin)
#define makeans() freopen("data.out","w",stdout)
#define makedata() freopen("data.in","w",stdout)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
const int maxn=1e6+10;
const int maxm=1e6+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxblock=sqrt(maxn)+10;
const double eps=1e-7;
const ll INF=1e16;


int main(){
    int t;
    cin>>t;
    while (t--){
        int a,b,c;
        cin>>a>>b>>c;
        int numc=c/2;
        int numb=b;
        int res=0;
        res+=min(numb,numc)*3;
        b-=min(numb,numc);
        c-=min(numb,numc)*2;
        numb=b/2;
        int numa=a;
        res+=min(numa,numb)*3;
        cout<<res<<endl;
    }
    return 0;
}