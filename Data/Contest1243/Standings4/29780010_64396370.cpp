#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define vi vector<int>
#define FOR(i,x,y) for(int i=x; i<=y; i++)

const int mod=int(1e9+7),MAXN=int(2e5+50);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    ll n;
    cin >> n;
    if (n==1)
    {
        printf("1\n");
        return 0;
    }
    if (n==(n&(-n)))
    {
        printf("2\n");
        return 0;
    }
    if (n%2==0)
    {
        printf("1\n");
        return 0;
    }

    int pr=0;
    ll st;
    for (ll i=3; i*i<=n; i+=2)
        if (n%i==0)
        {
            pr++;
            st=i;
            while (n%i==0)
                n/=i;
        }

    if (!pr)
    {
        printf("%lld\n",n);
        return 0;
    }

    if (n>1)
        pr++;

    if (pr==1)
    {
        printf("%lld\n",st);
        return 0;
    }

    printf("1\n");

    return 0;
}
