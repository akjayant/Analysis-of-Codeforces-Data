#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<bitset>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define pb(x) push_back(x)
#define cls(x, val) memset(x, val, sizeof(x))
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define inc(i, l, r) for(int i=l; i<=r; i++)
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+10;
int n, m;
int a[maxn];
int ji1, ou1;
int ji2, ou2;


int main(){
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--){
            ji1 = ou1 = ou2 = ji2 = 0;
        cin>>n;
        for(int i=1; i<=n; i++){
            int temp;
            cin>>temp;
            if(temp%2) ji1+=1;
            else ou1 +=1;
        }
        cin>>n;
        for(int i=1; i<=n; i++){
            int temp;
            cin>>temp;
            if(temp%2) ji2+=1;
            else ou2 +=1;
        }
        cout<<1ll*ji1*ji2+1ll*ou1*ou2<<endl;
    }

    return 0;
}


