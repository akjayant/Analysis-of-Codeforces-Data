#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
#define p pair<ll,ll>
#define MAX 15000001
#define vc vector<char>
#define fi first
#define se second
ll MOD=1e9+7;
int LIM=1e5+10;
vv adj(LIM);
v value(LIM);
ll sum=0;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    v arr(n+1);
    map<int,int> count;
    for (int i=1; i<=n; i++)
    {
        cin>>arr[i];
        count[arr[i]]++;
    }
    v b(1);
    v c(1);
    for (auto it=count.begin(); it!=count.end(); it++)
    {
        c.push_back(it->first);
        b.push_back(it->second);
    }
    int m=(int)b.size()-1; 
    ll left=b[1];
    ll right=b[m];
    ll posl=1;
    ll posr=m;
    ll rem=k;
    ll l=c[1],r=c[m];
    int iter=0;
    while (1)
    {
        if (l>=r)
            break;
        iter++;
        if (left<=right)
        {
            ll need=(c[posl+1]-c[posl])*left;
            if (need<=rem)
            {
                posl++;
                left+=b[posl];
                l=c[posl];
                rem-=need;
            }
            else
            {
                ll move=rem/left;
                l+=move;
                break;
            }
            // cout<<left<<" "<<right<<" "<<rem<<" "<<l<<endl;
        }
        else
        {
            ll need=(c[posr]-c[posr-1])*right;
            if (need<=rem)
            {
                posr--;
                right+=b[posr];
                r=c[posr];
                rem-=need;
            }
            else
            {
                ll move=rem/right;
                r-=move;
                break;
            }            
        }
        // cout<<l<<" "<<r<<" "<<rem<<" "<<iter<<"a"<<endl;
        if (l>=r)
            break;
    }
    cout<<r-l<<endl;

    return 0;   

} 