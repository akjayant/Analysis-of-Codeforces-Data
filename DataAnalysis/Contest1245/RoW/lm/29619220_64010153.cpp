using namespace std;
const long long mod = 1000000007;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long qq = 1;

    for(long long qqq = 0; qqq<qq; qqq++){
        string s;
        cin >> s;
        s = s+"#";
        long long len = 1;
        long long ans = 1;
        char ls = ' ';
        for(long long i = 0; i<s.length(); i++){
            if(s[i]=='m' || s[i]=='w'){
                cout << 0;
                return 0;
            }
            if(ls==s[i] && (s[i]=='n' || s[i]=='u'))
                len++;
            else {
                if(len==1){

                } else {
                    long long dp1 = 1, dp2 = 1;
                    for(long long j = 0; j<len-1; j++){
                        dp2 = dp1+dp2;
                        dp1 = dp2-dp1;
                        dp2%=mod;
                    }
                    ans*=dp2;
                    ans%=mod;
                }
                len = 1;
            }
            ls = s[i];
        }
        cout << ans;
    }
    return 0;
}
