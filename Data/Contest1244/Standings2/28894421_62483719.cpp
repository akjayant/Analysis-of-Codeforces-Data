#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> for_colour(100500, 0);
vector <  vector < ll>  > colour(4, for_colour);
vector <ll> degree(100500, 0);
vector < pair <ll,ll> > edges;

vector <ll> emp;
vector < vector <ll> > connections(100500);

vector <ll> answer(100500, 0);
    ll n;
        vector < ll> already(100500, -1);

ll solve(ll number_first, ll colour1, ll number_second, ll colour2, ll colour3)
{
        ll total_ans=0;
                for(ll i = 0; i<=100100; i++)
                    already[i] = -1;

            already[ number_first ] = colour1;
            already[ number_second ] = colour2;
            total_ans+=colour[ colour1 ][number_first];
            total_ans+=colour[ colour2 ][number_second];
            ll cur = number_second;
            ll i,j;
            for(i = 3; i<=n; i++) // номер вершины, которую собираемся красить
            {
                ll Next = -1;
                for(j=0; j<connections[cur].size(); j++)
                {
                    ll Candidate = connections[cur][j];
                    if (already[Candidate]==-1)
                        Next = Candidate;
                }
                if (i%3==0)
                {
                    total_ans+=colour[colour3][Next];
                    already[Next] = colour3;
                }
                if (i%3==1)
                {
                    total_ans+=colour[colour1][Next];
                    already[Next] = colour1;
                }
                if (i%3==2)
                {
                    total_ans+=colour[colour2][Next];
                    already[Next] = colour2;
                }
                cur = Next;
            }

    return total_ans;
}



int main()
{
    cin>>n;
    ll i,j;
        for(i = 1; i<=n; i++)
            cin>>colour[1][i];

        for(i = 1; i<=n; i++)
            cin>>colour[2][i];

        for(i = 1; i<=n; i++)
            cin>>colour[3][i];


        for(i = 1; i<n; i++)
        {
            ll q, w;
            cin>>q>>w;
            edges.push_back( {q, w} );
            degree[q]++;
            degree[w]++;
            connections[q].push_back(w);
            connections[w].push_back(q);
        }
        ll cnt_ones = 0;
        for(i = 1; i<=n; i++)
            if (degree[i]==1) cnt_ones++;
        if (cnt_ones > 2)
        {
            cout<<-1;
            return 0;
        }

        ll v1, v2;

        for(i = 1; i<=n; i++)
        {
            if (degree[i] == 1)
            {
                v1 = i;
                v2 = connections[v1][0];
                break;
            }
        }
        /*
    cout<<"cand"<<endl;
        cout<<v1<<" "<<v2<<endl;
*/
        ll best = 1e18;

        if (solve(v1, 1, v2, 2, 3) < best  )
        {
            best = solve(v1, 1, v2, 2, 3);
            answer = already;
        }

        if (solve(v1, 2, v2, 1, 3) < best  )
        {
            best = solve(v1, 2, v2, 1, 3);
            answer = already;
        }


        if (solve(v1, 1, v2, 3, 2) < best  )
        {
            best = solve(v1, 1, v2, 3, 2);
            answer = already;
        }

        if (solve(v1, 3, v2, 1, 2) < best  )
        {
            best = solve(v1, 3, v2, 1, 2);
            answer = already;
        }


         if (solve(v1, 2, v2, 3, 1) < best  )
        {
            best = solve(v1, 2, v2, 3, 1);
            answer = already;
        }


          if (solve(v1, 3, v2, 2, 1) < best  )
        {
            best = solve(v1, 3, v2, 2, 1);
            answer = already;
        }

        cout<<best<<endl;
        for(i = 1; i<=n; i++)
            cout<<answer[i]<<" ";


    return 0;
}
