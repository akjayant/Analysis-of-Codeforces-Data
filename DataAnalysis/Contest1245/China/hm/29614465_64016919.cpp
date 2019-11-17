using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int mod = 1e9+7;


ll num[maxn];
int len;
void init()
{
    num[2] = 2; num[3] = 3;
    for(int i=4;i<=len;i++)
    {
        num[i] = (num[i-1] + num[i-2]) % mod;
    }
}

vector<int> v;

int main()
{
    string s;
    cin>>s;
    len = s.length();
    init();
    int flag = 0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='w' || s[i]=='m')
        {
            flag = 1;break;
        }
        if(s[i]=='u')
        {
            int j=i;
            int cnt=0;
            while(s[j]=='u' && j<len)
            {
                cnt++;j++;
            }
            if(cnt>=2)
                v.push_back(cnt);
            i=j-1;
        }
        else if(s[i]=='n')
        {
            int j=i;
            int cnt=0;
            while(s[j]=='n' && j<len)
            {
                cnt++;j++;
            }
            if(cnt>=2)
                v.push_back(cnt);
            i=j-1;
        }
    }
    if(flag)
    {
        cout<<0<<endl;
    }
    else
    {
        ll ans = 1;
        for(auto x : v)
        {

            ans = (ans%mod * num[x]%mod) % mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
