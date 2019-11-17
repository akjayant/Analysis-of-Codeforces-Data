using namespace std;

typedef long long ll;

long long int INF = 3e18;
ll mod = 1000000007;

ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k,ans;
ll x[500005],y[500005],z[500005];
char s[500005];

void pre_calc(){
    x[1] = 1;
    x[2] = 2;
    for(int i=3;i<=n;i++){
        x[i] = x[i - 1] + x[i - 2];
        x[i] %= mod;
    }
    return;
}
void solve(ll length){
    ans *= x[length];
    ans %= mod;
    return;
}
int main(){
    cin >> s;
    n = strlen(s);
    pre_calc();
    ll same = 1;
    s[n] = 'A';
    ans = 1;
    for(int i=0;i<n;i++){
        if(s[i] == 'm' || s[i] == 'w'){
            ans = 0;
        }
        if(s[i] == s[i + 1]){
            same ++;
        }else{
            if(s[i] == 'u' || s[i] == 'n'){
                solve(same);
            }
            same = 1;
        }
    }
    cout<<ans<<"\n";;

    return 0;

}
