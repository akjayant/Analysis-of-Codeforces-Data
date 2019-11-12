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

	int t;
	cin >> t;
	while (t--)
    {
        int n,a[1010];
        cin >> n;
        FOR(i,1,n)
            cin >> a[i];
        sort(a+1,a+n+1);
        int rez=0;
        for (int i=n,j=1; i>=1; i--,j++)
            rez = max(rez, min(j,a[i]));
        printf("%d\n",rez);
    }



    return 0;
}
