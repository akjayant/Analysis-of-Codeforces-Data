using namespace std;
typedef long long ll;







const ll maxn=1e5+5;
const ll mod=1e9+7;
ll ans[maxn];
int main()
{
    std::ios::sync_with_stdio(false);







    ll i;
    ans[1]=1;
    ans[2]=2;
    for(i=3;i<maxn;++i)
    {
        ans[i]=ans[i-1]+ans[i-2];
        ans[i]%=mod;
    }
    string s;
    cin>>s;
    ll flag=1;
    ll cnt1=0;
    ll cnt2=0;
    ll res=1;
    for(i=0;i<s.length();++i)
    {
        if(s[i]=='w'||s[i]=='m')
        {
            flag=0;
            break;
        }else
        {
            if(s[i]=='u')
            {
                if(cnt2!=0)
                {
                    res=res*ans[cnt2]%mod;
                }
                cnt2=0;
                cnt1++;
            }else if(s[i]=='n')
            {
                if(cnt1!=0)
                    res=res*ans[cnt1]%mod;
                cnt1=0;
                cnt2++;
            }else
            {
                if(cnt2!=0)
                {
                    res=res*ans[cnt2]%mod;
                }
                if(cnt1!=0)
                    res=res*ans[cnt1]%mod;
                cnt2=cnt1=0;
            }
        }
    }
    if(cnt2!=0)
    {
        res=res*ans[cnt2]%mod;
    }
    if(cnt1!=0)
        res=res*ans[cnt1]%mod;
    if(flag==1)
        cout<<res<<endl;
    else
        cout<<0<<endl;
    return 0;
}
