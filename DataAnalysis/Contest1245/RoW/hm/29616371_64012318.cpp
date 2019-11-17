using namespace std;
string s;
int n,f1[100005],f2[100005],dem;
long long ans=1,d[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    cin>>s;
    n=s.length();
    s=' '+s;
    d[2]=2, d[1]=1;
    for(int i=3;i<=n;i++)
    {
        d[i]=(d[i-1]+d[i-2])%1000000007;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout << 0;
            return 0;
        }
        if(s[i]=='u')
        {

            while(s[i]=='u')
            {
                dem++;
                i++;
            }
            i--;
            ans=(ans*d[dem])%1000000007;
            dem=0;
        }
        else
        {
            if(s[i]=='n')
            {
                dem=0;
                while(s[i]=='n')
                {
                    dem++;
                    i++;
                }
                i--;
                ans=(ans*d[dem])%1000000007;
                dem=0;
            }
            else dem=0;
        }
    }
    cout << ans;
    return 0;
}
