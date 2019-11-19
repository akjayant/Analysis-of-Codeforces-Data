#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)(1e7))
#define MAX_X ((int)(1e6 + 2))
#define pi (2.0*acos(0))
#define M ((ll)(1e9 + 7))
#define NN ((ll)(305))
#define N ((int)(1e6 + 5))
#define eps (0)
#define log 20


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;


typedef tree < pair < int, int >,  null_type,  less < pair < int, int > >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).

int tot;
o_set ss;

void add_el(pair < int , int > p , int fin)
{
    pair < int , int > q = p;
    q.second = -1;
    int j = ss.order_of_key(q);
    if(j<ss.size()){
        q = *(ss.find_by_order(j));
        if(q.first==p.first){
            p.second += q.second;
            ss.erase(q);
        }
    }

    ss.insert(p);
}

int arr[N];

vector < int > v[N];
vector < pair < int , int > > pos[N];

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i<=m; i++)
    {
        scanf("%d",&arr[i]);
        v[arr[i]].push_back(i);
    }
    for(int i = 1; i<=n; i++)
    {
        int last = 0;
        for(int j = 1; j<v[i].size(); j++)
        {
            if(v[i][j]!=v[i][j-1]+1)
            {
                pos[i].push_back({v[i][last],v[i][j-1]});
                last = j;
            }
        }
        if(v[i].size()>0) pos[i].push_back({v[i][last],v[i].back()});
    }
    if(n==1)
    {
        for(int i = 1; i<=m; i++)
        {
            if(arr[i]==1)
            {
                printf("0\n");
                return 0;
            }
        }
        printf("1\n");
        return 0;
    }

    //cout<<"asd\n";
    int add = 0;

    ll ans = n;
    tot = 0;

    for(int i = 2; i<=n; i++)
    {
        add++;
        for(auto p:pos[i])
        {
            int from = p.first, too = p.second, cnt = 0;
            while(ss.size()>0)
            {
                int j = ss.order_of_key({from-add,-1});
                if(j<ss.size())
                {
                    pair < int, int > ppp = *(ss.find_by_order(j));
                    if(ppp.first+add>=from && ppp.first+add<=too)
                    {
                        ss.erase(ppp);
                        cnt += ppp.second;
                        //add_el({too+1-add,ppp.second},m+1);
                    }
                    else
                        break;
                }
                else
                    break;
            }
            if(cnt>0) add_el({too+1-add,cnt},m+1);
        }
        //cout<<"oj\n";
        int dhu;
        if(pos[i].size()>0)
        {
            if(pos[i][0].first==1)
            {
                dhu = pos[i][0].second+1;
            }
            else
                dhu = 1;
        }
        else
            dhu = 1;

        add_el({dhu-add,1},m+1);

        tot++;

        //cout<<ss.size()<<endl;

        while(ss.size()>0){
            int j = ss.size();
            //cout<<j<<endl;
            pair < int , int > p = *(ss.find_by_order(j-1));

            if(p.first+add>m+1){
                ss.erase(p);
                tot -= p.second;
            }
            else break;
        }

        //cout<<"yo\n";

        ans += tot;
    }


    ss.clear();

    tot = 0;
    add = 0;
//    for(int i = 1; i<=n; i++){
//        reverse(pos[i].begin(),pos[i].end());
//    }
    //cout<<"asdasdas\n";
    for(int i = n-1; i>0; i--)
    {
        add++;
        for(auto p:pos[i])
        {
            int from = p.first, too = p.second, cnt = 0;
            while(ss.size()>0)
            {
                int j = ss.order_of_key({from-add,-1});
                if(j<ss.size())
                {
                    pair < int, int > ppp = *(ss.find_by_order(j));
                    if(ppp.first+add>=from && ppp.first+add<=too)
                    {
                        ss.erase(ppp);
                        cnt += ppp.second;
                        //add_el({too+1-add,ppp.second},m+1);
                    }
                    else
                        break;
                }
                else
                    break;
            }
            if(cnt>0) add_el({too+1-add,cnt},m+1);
        }
        //cout<<"oj\n";
        int dhu;
        if(pos[i].size()>0)
        {
            if(pos[i][0].first==1)
            {
                dhu = pos[i][0].second+1;
            }
            else
                dhu = 1;
        }
        else
            dhu = 1;

        add_el({dhu-add,1},m+1);

        tot++;

        //cout<<ss.size()<<endl;

        while(ss.size()>0){
            int j = ss.size();
            //cout<<j<<endl;
            pair < int , int > p = *(ss.find_by_order(j-1));

            if(p.first+add>m+1){
                ss.erase(p);
                tot -= p.second;
            }
            else break;
        }

        //cout<<"yo\n";

        ans += tot;
    }
    printf("%lld\n",ans);
    return 0;
}
