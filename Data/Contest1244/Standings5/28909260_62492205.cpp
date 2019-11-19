#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define pa pair<ll,int>
#define ld long double
#define st first
#define nd second
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
const int MAX=100005;
ll cost[3][MAX];
const ll inf=1e18+9;
vector<int>P[MAX];
int synowie[MAX];
bool O1[MAX];
bool O2[MAX];
int aktcolor[MAX];
int color[MAX];
ll ans=inf;
void dfs1(int n)
{
    for (auto it:P[n])
    {
        if (!O1[it])
        {
            synowie[n]++;
            O1[it]=true;
            dfs1(it);
        }
    }
}

int main()
{
    BOOST;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>cost[0][i];
    for (int i=1;i<=n;i++)cin>>cost[1][i];
    for (int i=1;i<=n;i++)cin>>cost[2][i];

    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        P[a].pb(b);
        P[b].pb(a);
    }
    int root=-1;
    for (int i=1;i<=n;i++)
    {
        if (P[i].size()==1)
        {
            root=i;
            break;
        }
    }

    if (root==-1)
    {
        cout<<"-1";
        return 0;
    }
    else
    {
        O1[root]=true;
        dfs1(root);
        for (int i=1;i<=n;i++)
        {
            if (synowie[i]>1)
            {
                cout<<"-1";
                return 0;
            }
        }
        int akt=root;
        O2[akt]=true;
        vector<int>order;
        order.clear();
        order.pb(akt);
        while (synowie[akt]!=0)
        {
            for (auto it:P[akt])
            {
                if (!O2[it])
                {
                    akt=it;
                    O2[it]=true;
                    order.pb(akt);
                }
            }
        }

        int tab[3]={0,1,2};
        do
        {
            ll akt=0;
          aktcolor[order[0]]=tab[0];
          aktcolor[order[1]]=tab[1];
          aktcolor[order[2]]=tab[2];
          akt+=cost[tab[0]][order[0]];
           akt+=cost[tab[1]][order[1]];
          akt+=cost[tab[2]][order[2]];
          for (int i=3;i<order.size();i++)
          {
              for (int j=0;j<3;j++)
              {
                  if (j!=aktcolor[order[i-1]]&& j!=aktcolor[order[i-2]])
                  {
                      akt+=cost[j][order[i]];
                      aktcolor[order[i]]=j;
                      break;
                  }
              }
          }

          if (akt<ans)
          {
              /*
              cout<<"SKLAD\n";
              for (int i=0;i<order.size();i++)cout<<order[i]<<" ";
              cout<<"KONIEC\n";
              cout<<"NOW "<<akt<<" "<<tab[0]<<" "<<tab[1]<<" "<<tab[2]<<"\n";
              */
              ans=akt;
              for (int i=0;i<n;i++)
              {
                  color[order[i]]=aktcolor[order[i]];
              }
          }

        } while (next_permutation(tab,tab+3));

        cout<<ans<<"\n";
        for (int i=1;i<=n;i++)cout<<color[i]+1<<" ";


    }

      return 0;
}
