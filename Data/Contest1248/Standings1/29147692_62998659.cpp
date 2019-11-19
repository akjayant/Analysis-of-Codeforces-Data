#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l=0;
    int r=0;
    int num=0;
    rep(i,n){
        rep(j,n){
            string t=s;
            char c=t[i];
            t[i]=t[j];
            t[j]=c;
            int lmn[n];
            int rmn[n];
            int cnt[n]={};
            if(t[0]=='('){
                cnt[0]=1;
                lmn[0]=1;
            }
            else{
                cnt[0]=-1;
                lmn[0]=-1;
            }
            for(int k=1;k<n;k++){
                if(t[k]=='(')cnt[k]=cnt[k-1]+1;
                else cnt[k]=cnt[k-1]-1;
                lmn[k]=min(cnt[k],lmn[k-1]);
            }
            rmn[n-1]=cnt[n-1];
            for(int k=n-2;k>=0;k--){
                rmn[k]=min(cnt[k],rmn[k+1]);
            }
            int cou=0;
            if(lmn[n-1]>=0)cou++;
            rep(k,n-1){
                if(rmn[k+1]-cnt[k]>=0 && lmn[k]+cnt[n-1]-cnt[k]>=0)cou++;
            }
            if(chmax(num,cou)){
                l=i;
                r=j;
            }
        }
    }
    l++;
    r++;
  	if(n%2==1)num=0;
    cout << num << endl;
    cout << l << ' ' << r;

}

/*

)(()(()())()
)(()(()())()


 */

