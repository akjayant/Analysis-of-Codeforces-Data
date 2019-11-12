#include <bits/stdc++.h>
#define ll long long
#define read1(a) scanf("%d",&a)
#define read2(a,b) scanf("%d%d",&a,&b)
#define read3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write(a) printf("%d",a)
#define writen(a) printf("%d\n",a)
#define ff first
#define ss second
#define pll pair<long long ,long long>
#define pii pair<int ,int>
#define ull unsigned long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
    {
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
         if(cnt+1>a[i])
            break;
         cnt++;
    }
    cout << cnt << endl;
    }

}
