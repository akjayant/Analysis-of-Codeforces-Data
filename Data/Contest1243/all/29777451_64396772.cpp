//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1000 + 10;
//int a[maxn];
//int n;
//
//bool check(int pos){
//    for(int i = 1; i <= n - pos + 1; i++) if(a[i] >= pos) return true;
//    return false;
//}
//
//int main(){
//    int T;
//    cin>>T;
//    while(T--){
//        cin>>n;
//        for(int i = 1; i <= n; i++) cin>>a[i];
//        sort(a + 1, a + 1 + n);
//        int l = 1, r = n;
//        int ans;
//        if(a[1] == a[n]){
//            cout<<a[1]<<endl;
//            continue;
//        }
//        while(l < r){
//            int mid = (l + r) >> 1;
//            if(check(mid)) ans = mid, l = mid + 1;
//            else r = mid;
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

 /*cout<<"─────────▄──────────────▄"<<endl;
    cout<<"────────▌▒█───────────▄▀▒▌"<<endl;
    cout<<"────────▌▒▒▀▄───────▄▀▒▒▒▐"<<endl;
    cout<<"───────▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐"<<endl;
    cout<<"─────▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐"<<endl;
    cout<<"───▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀██▀▒▌"<<endl;
    cout<<"──▐▒▒▒▄▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▒▌much speed"<<endl;
    cout<<"──▌▒▒▐▄█▀▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐"<<endl;
    cout<<"─▐▒▒▒▒▒▒▒▒▒▒▒▌██▀▒▒▒▒▒▒▒▒▀▄▌"<<endl;
    cout<<"─▌▒▀▄██▄▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌"<<endl;
    cout<<"─▌▀▐▄█▄█▌▄▒▀▒▒▒▒▒▒░░░░░░▒▒▒▐ Wow"<<endl;
    cout<<"▐▒▀▐▀▐▀▒▒▄▄▒▄▒▒▒▒▒░░░░░░▒▒▒▒▌"<<endl;
    cout<<"▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒░░░░░░▒▒▒▐"<<endl;
    cout<<"─▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌good macro"<<endl;
    cout<<"─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐"<<endl;
    cout<<"──▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▌"<<endl;
    cout<<"────▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀"<<endl;
    cout<<"───▐▀▒▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀"<<endl;
    cout<<"──▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀"<<endl;*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1000000 ;
ll prime[maxn + 1] ;

void getPrime(){
    memset (prime , 0 , sizeof (prime)) ;
    for (ll i = 2 ; i <= maxn ; ++i){
        if (!prime[i]) prime[++prime[0]] = i ;
        for (ll j = 1 ; j <= prime[0] && prime[j] <= maxn / i ; ++j){
            prime[prime[j] * i] = 1 ;
            if (i % prime[j] == 0) break ;
        }
    }
}

long long ans[100][2] ;
ll cnt ;
int asjhdfikjashfkdhjsdgfidshgbf = 1;

ll solve(long long x){
    cnt = 0 ;
    int asdsjhfdksjhfdskjhfsdkjhfijdksfjkds = 1;
    long long tmp = x ;
    for (ll i = 1 ; prime[i] <= tmp / prime[i] ; ++i){
        ans[cnt][1] = 0 ;
        int asjdhasijdhdaskjhfghsdjhkfgdsijhf = 1;
        if (tmp % prime[i] == 0){
            ans[cnt][0] = prime[i] ;
            while (tmp % prime[i] == 0){ans[cnt][1]++ ;tmp /= prime[i] ;}
            cnt++ ;
        }
        int sdjhfkjsdhfodskjjfodsuihf = 1;
    }
    if (tmp != 1){ans[cnt][0] = tmp ;ans[cnt++][1] = 1 ;}
    return cnt ;
}

int main (){
    getPrime() ;
    long long n;
    cin>>n;
    int asdjhfdkjsdhfkjdshfiudj = 1;
    long long tmp = solve(n) ;
    if (tmp == 0) cout<<n<<endl;
    else if (tmp == 1) cout<<ans[0][0]<<endl;
    else cout<<1<<endl;
    return 0;
}


