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
        vector <pii> rez;
        int ans = 1;
        FOR(i,0,n-1)
            if (s[i]!=t[i])
            {
                int nasao=0;
                FOR(j,i+1,n-1)
                    if (s[i]==s[j])
                    {
                        int pom=t[i];
                        t[i]=s[j];
                        s[j]=pom;
                        rez.pb({j+1,i+1});
                        nasao=1;
                        break;
                    }
                    else
                        if (t[i]==t[j])
                        {
                            int pom=s[i];
                            s[i]=t[j];
                            t[j]=pom;
                            rez.pb({i+1,j+1});
                            nasao=1;
                            break;
                        }
                        else
                            if (s[i]==t[j])
                            {
                                int pom=s[j];
                                s[j]=t[j];
                                t[j]=pom;
                                pom=t[i];
                                t[i]=s[j];
                                s[j]=pom;
                                rez.pb({j+1,j+1});
                                rez.pb({j+1,i+1});
                                nasao=1;
                                break;
                            }
                            else
                                if (t[i]==s[j])
                                {
                                    int pom=t[j];
                                    t[j]=s[j];
                                    s[j]=pom;
                                    pom=s[i];
                                    s[i]=t[j];
                                    t[j]=pom;
                                    rez.pb({j+1,j+1});
                                    rez.pb({i+1,j+1});
                                    nasao=1;
                                    break;
                                }
                if (!nasao)
                {
                    ans=0;
                    break;
                }
            }

        if (!ans)
        {
            printf("No\n");
            continue;
        }
        else
        {
            printf("Yes\n%d\n",rez.size());
            for (auto i:rez)
                printf("%d %d\n",i.fr,i.sc);
        }
    }


    return 0;
}
