//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

vector<pair<int,int>>v;
int c[2005];
int k[2005];
int arr[2005];
int sizee[2005];
int n;
int matrix[2006][2006]={};
int root(int i)
{
    while(arr[i]!= i)
    {
        arr[i]=arr[arr[i]]; 
        i=arr[i];
    }
    return i;
}
void merge(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(arr[root_A]==arr[root_B])
        return;
    if(sizee[root_A] < sizee[root_B])
    {
        arr[root_A] = arr[root_B];
        sizee[root_B] += sizee[root_A];
    }
    else
    {
        arr[root_B] = arr[root_A];
        sizee[root_A] += sizee[root_B];
    }
}
vector<int>tree1[2005];
vector<pair<int,pair<int,int>>>treebysize;
int vis[2005];
int32_t main()
{
    IOS;
    cin>>n;
    for(int i=0;i<2005;i++)
    {
        arr[i]=i;
        sizee[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int i=0;i<n;i++)
        cin>>k[i];
    vector<pair<int,pair<int,int>>> v1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int cost=(k[i]+k[j])*(abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second));
            v1.push_back({cost,{i,j}});
        }
    }
    for(int i=0;i<n;i++)
        v1.push_back({c[i],{i,n}});
    sort(v1.begin(),v1.end());
    int money=0;
    int deg[2006]={};
    vector<int> anss;
    for(int i=0;i<v1.size();i++)
    {
        if(root(v1[i].second.first)==root(v1[i].second.second))
            continue;
        money+=v1[i].first;
        merge(v1[i].second.first,v1[i].second.second);
        treebysize.push_back({v1[i].first,{v1[i].second.second,v1[i].second.first}});
        deg[v1[i].second.second]++;
        deg[v1[i].second.first]++;
        if(v1[i].second.first==n)
        {
            anss.push_back(v1[i].second.second);
        }
        if(v1[i].second.second==n)
        {
            anss.push_back(v1[i].second.first);
        }
        matrix[v1[i].second.second][v1[i].second.first]=1;
        matrix[v1[i].second.first][v1[i].second.second]=1;
    }
    int a=treebysize.size();
    int b=anss.size();
    cout<<money<<endl;
    cout<<b<<endl;
    for(int j:anss)
        cout<<j+1<<" ";
    cout<<endl;
    cout<<a-b<<endl;
    if(a-b==0)
        return 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(matrix[i][j])
                cout<<i+1<<" "<<j+1<<endl;
    }
}