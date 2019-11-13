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
        int n;
        cin >> n;
        string s,t;
        cin >> s;
        cin >> t;
        int p1=-1,p2=-1,ans=1;
        FOR(i,0,n-1)
            if (s[i]!=t[i])
            {
                if (p1==-1)
                    p1=i;
                else
                    if (p2==-1)
                        p2=i;
                    else
                        ans=0;
            }
        if (!ans || (p1!=-1 && p2==-1))
        {
            printf("No\n");
            continue;
        }

        if (p1==-1)
        {
            printf("Yes\n");
            continue;
        }

        if (p2!=-1)
        {
            if (s[p1]==s[p2] && t[p1]==t[p2])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }


    return 0;
}
