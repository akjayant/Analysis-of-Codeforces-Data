using namespace std;
typedef long long int ll;

ll md = 1000000007;

int main()
{
    vector<int> dp(100005);
    dp[0] = 1;
    dp[1] = 1;
    string s;
    cin>>s;
    for(int i = 2; i<=s.size(); i++){
        dp[i] = (dp[i-2] + dp[i-1]) % md;
    }
    vector<int> st;
    int us = 0;
    for(char c: s){
            if(c=='m' || c=='w'){
                cout<<0;
                return 0;
            }
        if (c=='u'){
            us++;
        }else{
            if(us > 0){
                st.push_back(us);
                us = 0;
            }
        }
    }
    if(us > 0){
        st.push_back(us);
        us = 0;
    }
    for(char c: s){
        if (c=='n'){
            us++;
        }else{
            if(us > 0){
                st.push_back(us);
                us = 0;
            }
        }
    }
     if(us > 0){
        st.push_back(us);
        us = 0;
    }
    int ans = 1;
    for(int i: st){
        ans = (ans * 1ll * dp[i])%md;
    }
    cout<<ans;
    return 0;
}
