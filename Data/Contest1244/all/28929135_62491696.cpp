#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll cost[100005][4];
vector<int>adjacent[100005];
int n;
int answer[100005];
bool visited[100005];
vector<int>pp;

void chec(int u)
{
    visited[u] = true;
    pp.push_back(u);

    for(int i = 0 ; i < adjacent[u].size() ; i++)
    {
        if(visited[adjacent[u][i]] == false)
        {
            chec(adjacent[u][i]);
        }
    }
}

ll check(int index)
{
    ll ct = 0;
    if(index == 1)
    {
        int array[4] = {0,1,2,3};
         int num = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(num > 3) num = 1;
            ct += cost[pp[i]][array[num]];
            num++;
        }
        return ct;
    }
        if(index == 2)
    {
        int array[4] = {0,2,1,3};
        int num = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(num > 3) num = 1;
        ct += cost[pp[i]][array[num]];
            num++;
        }
        return ct;
    }
        if(index == 3)
    {
        int array[4] = {0,3,1,2};
        int num = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(num > 3) num = 1;
           ct += cost[pp[i]][array[num]];
            num++;
        }
        return ct;
    }
        if(index == 4)
    {
        int array[4] = {0,3,2,1};
        int num = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(num > 3) num = 1;
            ct += cost[pp[i]][array[num]];
            num++;
        }
        return ct;
    }
        if(index == 5)
    {
        int array[4] = {0,2,3,1};
        int num = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(num > 3) num = 1;
          ct += cost[pp[i]][array[num]];
            num++;
        }
        return ct;
    }
        if(index == 6)
    {
        int array[4] = {0,1,3,2};
        int num = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(num > 3) num = 1;
           ct += cost[pp[i]][array[num]];
            num++;
        }
        return ct;
    }
}

int main(){
   // int n;
    cin>>n;
    for(int i = 1 ; i <= 3 ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cin>>cost[j][i];
        }
    }

    for(int i = 0 ; i < n - 1 ; i++)
    {
        int u,v;
        cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    int nodea ;
    for(int i = 1 ; i <= n ; i++)
    {
        if(adjacent[i].size() > 2)
            {
                cout<<-1<<endl;
                return 0;
            }
        if(adjacent[i].size() == 1)
        {
            nodea = i;
        }
    }

    ll ans = 1000000000000000000;

    pp.push_back(0);
    chec(nodea);


    for(int i = 1 ; i <= 6 ; i++)
    {
         ans = min(ans,check(i));
    }

  cout<<ans<<endl;

    for(int i = 1 ; i <= 6 ; i++)
    {
        if(check(i) == ans)
        {
            if(i == 1)
            {
                 int array[4] = {0,1,2,3};
                    int num = 1;
                for(int i = 1 ; i <= n ; i++)
                {
                    if(num > 3) num = 1;
                    answer[pp[i]] = array[num];
                    num++;
                }

                for(int i = 1 ; i<= n ; i++)
                {
                    cout<<answer[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
            if(i == 2)
            {
                int array[4] = {0,2,1,3};
                    int num = 1;
                for(int i = 1 ; i <= n ; i++)
                {
                    if(num > 3) num = 1;
                    answer[pp[i]] = array[num];
                    num++;
                }


                for(int i = 1 ; i<= n ; i++)
                {
                    cout<<answer[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
            if(i == 3)
            {
                int array[4] = {0,3,1,2};
                    int num = 1;
                for(int i = 1 ; i <= n ; i++)
                {
                    if(num > 3) num = 1;
                    answer[pp[i]] = array[num];
                    num++;
                }


                for(int i = 1 ; i<= n ; i++)
                {
                    cout<<answer[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
            if(i == 4)
            {
                int array[4] = {0,3,2,1};
                    int num = 1;
                for(int i = 1 ; i <= n ; i++)
                {
                    if(num > 3) num = 1;
                    answer[pp[i]] = array[num];
                    num++;
                }


                for(int i = 1 ; i<= n ; i++)
                {
                    cout<<answer[i]<<" ";
                }
                cout<<endl;
                return 0;   
            }
            if(i == 5)
            {
                int array[4] = {0,2,3,1};
                    int num = 1;
                for(int i = 1 ; i <= n ; i++)
                {
                    if(num > 3) num = 1;
                   answer[pp[i]] = array[num];
                    num++;
                }


                for(int i = 1 ; i<= n ; i++)
                {
                    cout<<answer[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
            if(i == 6)
            {
                int array[4] = {0,1,3,2};
                    int num = 1;
                for(int i = 1 ; i <= n ; i++)
                {
                    if(num > 3) num = 1;
                    answer[pp[i]] = array[num];
                    num++;
                }


                for(int i = 1 ; i<= n ; i++)
                {
                    cout<<answer[i]<<" ";
                }
                cout<<endl;
                return 0;  
            }
        }
    }
  



}