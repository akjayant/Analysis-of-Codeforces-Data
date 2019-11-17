using namespace std;

string s;
long long f[100100];

int main()
{
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i<=100000; i++)
        f[i] = (f[i-1] + f[i-2]) % 1000000007;

    cin >> s;
    int n = s.length();

    for (int i = 0; i<n; i++)
        if (s[i]=='m' || s[i]=='w')
        {
            cout << 0 << endl;
            return 0;
        }

    long long ans = 1;
    char pre = ' ';
    int cnt = 0;
    for (int i = 0; i<n; i++)
        if (s[i]=='u' || s[i]=='n')
        {
            if (s[i]==pre)
            {
                cnt ++;
            }else if (cnt)
            {
                ans = (ans * f[cnt]) % 1000000007;
                cnt = 1;
                pre = s[i];
            }else
            {
                cnt = 1;
                pre = s[i];
            }
        }else if (cnt)
        {
            ans = (ans * f[cnt]) % 1000000007;
            cnt = 0;
        }
    if (cnt)
        ans = (ans * f[cnt]) % 1000000007;

    cout << ans << endl;
}
