#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #define lli long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
#define f(i,j,l) for(i=j;i<l;i++)

int const mod = 1e9+7;
int power(int a,int b){
    int res = 1;
    while(b){
        if(b&1){
            res = res*a;
            // res %= mod;
        }
        a=a*a;
        // a%=mod;
        b=b/2;
    }
    return res;
}

// int inverse_mod(int x){
//     return power(x,mod-2);
// }

int const N = 1e5+5;




void solve(){
    int n,i,j,l;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    int lf = 1;
    int rt = 1;

    int op = 0;int cl = 0;
    for(i=0;i<n;i++){
        if(s[i] == '(') op++;
        else cl++;
    }

    if(op != cl){
        cout<<ans<<endl;
        cout<<lf<<" "<<rt<<endl;
        return;
    }

    lf=0;
    rt=0;
    
    int is = 0;
    if(is == 0){
        int a[n+1] = {0};
        a[n] = 1;
        int sm = 0;
        int sm1 = 0;

        for(l=n-1;l>=0;l--){
            if(s[l] == '('){
                if(sm1 < 0) sm1++;
                if(sm1 >=0) a[l] = 1;
                else a[l] = 0;
            }
            else{
                sm1--;
                a[l] = 0;
            }
        }

        int b[n]={0};
        for(l=0;l<n;l++){
            if(s[l] == '('){
                sm++;
                b[l] = 0;
            }
            else{
                if(sm > 0) sm--;
                if(sm <= 0) b[l] = 1;
                else b[l] = 0;
            }
        }

        for(l=0;l<n;l++){
            if(b[l] == 1 && a[l+1] == 1){
                ans++;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(s[i] == '(' && s[j] == ')'){
                int cnt = 0;
                int a[n+1]={0};
                a[n] = 1;
                int sm = 0;
                int sm1 = 0;
                for(l=n-1;l>=0;l--){
                    if(i == l){
                        sm1--;
                        a[l]=0;
                    }
                    else if(j == l){
                        if(sm1 < 0) sm1++;
                        if(sm1 >= 0) a[l] = 1;
                        else a[l] = 0;
                    }
                    else{
                        if(s[l] == '('){
                            if(sm1 < 0) sm1++;
                            if(sm1 >= 0) a[l] = 1;
                            else a[l] = 0;
                        }
                        else{
                            sm1--;
                            a[l] = 0;
                        }
                    }
                }

                int b[n+1]={0};
                for(l=0;l<n;l++){
                    if(l == i){
                        if(sm > 0) sm--;
                        if(sm <= 0) b[l] = 1;
                        else b[l] = 1;
                    }
                    else if(l == j){
                        sm ++;
                        b[l] = 0;
                    }
                    else{
                        if(s[l] == '('){
                            sm++;
                            b[l] = 0;
                        }
                        else{
                            if(sm > 0) sm--;
                            if(sm <= 0) b[l] = 1;
                            else b[l] = 0;
                        }
                    }
                }

                for(l=0;l<n;l++){
                    if(b[l] == 1 && a[l+1] == 1){
                        cnt++;
                    }
                }

                if(ans < cnt){
                    lf = i;
                    rt = j;
                    ans = cnt;
                }
            }
        }
    }

    cout<<ans<<endl;
    cout<<lf+1<<" "<<rt+1<<endl;
}


int32_t main(){
    IOS;
    int t;
    t = 1;
    // cin>>t;
    for(int tt=1;tt<=t;tt++){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    return 0;
}

/*

 */