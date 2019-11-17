using namespace std;
inline long long mod(long long n, long long m){ long long ret = n%m; if(ret < 0) ret += m; return ret; }
long long exp(long long a,long long b,long long m){
    if(b==0) return 1LL;
    if(b==1) return mod(a,m);
    long long k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);;
    string s;
    cin >> s;
    vector<long long> sz(100100);
    long long n = s.size();
    for(long long i=0;i<n;i++){
        if(s[i]=='m' or s[i]=='w'){
            cout << 0 << "\n";
            return 0;
        }
        if(s[i]=='n'){
            long long q = 0;
            while(i<n && s[i]=='n'){
                q++;
                i++;
            }
            i--;
            sz[q]++;
        }
        else if(s[i]=='u'){
            long long q = 0;
            while(i<n && s[i]=='u'){
                q++;
                i++;
            }
            i--;
            sz[q]++;
        }
    }
    vector<long long> dp(100100);
    dp[0] = dp[1] = 1;
    long long ans = 1;
    for(long long i=2;i<=100050;i++){
        dp[i] = (dp[i-2] + dp[i-1]) % 1000000007;
        ans = ans * exp(dp[i],sz[i],1000000007) % 1000000007;
    }
    cout << ans << "\n";
}
