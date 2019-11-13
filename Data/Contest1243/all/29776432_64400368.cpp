//DEEPANSHU SAXENA(saxenad765)
#include <bits/stdc++.h>
#define ll long long
#define array(x,n) (x,x+n)
#define all(c) (c).begin(),(c).end()
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define odd(x) (x&1)
#define even(x) (!x&1)
#define cpresent(a,x) (find(all(a),x) != (a).end())
#define it(a,i) for(typeof((a).begin() i = (a).begin(); i != (a).end(); i++)
#define present(a,x) ((a).find(x) != (a).end())
#define fbei(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define fbe(i,x,y) for(ll i=x;i<=y;i++)
#define f(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define GCD(x,y) __gcd(x,y)
using namespace std;
//using codechef ide;
//Deepanshu Saxena
const int DP=3e5 + 100;
inline void filehandling()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
vector<ll> vector_in(ll n)
{
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    return v;
}
void vector_out(vector<ll> v)
{
    for(ll i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
ll vector_sum(vector<ll> v)
{
    ll sum;
    for(ll i=0;i<v.size();i++)
    sum+=v[i];
    return sum;
}

ll Array1[DP];
ll Array2[DP];
int main()
{
    fast
    filehandling();
    ll Test=1;
    ip(Test);
    while(Test--)
    {
        ll n;
        ip(n);
        string STRING1,STRING2;
        ip(STRING1);
        ip(STRING2);
        vector <ll> Vectorr;
        f(iteratorr,n)
        {
            if(STRING1[iteratorr] != STRING2[iteratorr])
            {
                Array2[STRING1[iteratorr] - '0']++;
                Array2[STRING2[iteratorr] - '0']++;
                Vectorr.push_back(iteratorr);
            }
        }
        bool Boolean1 = 0;
        f(iteratorr,30)
        {
            if(Array2[iteratorr] % 2)
            {
                Boolean1 = 1;
                op("No");
                break;
            }
        }
        if(Boolean1)continue;
        ll SZ = Vectorr.size();
        vector <pair<ll,ll>> OUT;
        bool Boolean2 = 0;
        f(iteratorr,SZ)
        {
            if(STRING1[Vectorr[iteratorr]] == STRING2[Vectorr[iteratorr]])continue;
            Boolean1 = 0;
            fbe(it2,iteratorr+1,SZ-1)
            {
                if(STRING2[Vectorr[iteratorr]] == STRING2[Vectorr[it2]])
                {
                    OUT.push_back(make_pair(Vectorr[iteratorr],Vectorr[it2]));
                    swap(STRING1[Vectorr[iteratorr]],STRING2[Vectorr[it2]]);
                    Boolean1 = 1;
                    break;
                }
            }
            if(Boolean1)continue;
            fbe(it2,iteratorr+1,SZ-1)
            {
                if(STRING2[Vectorr[iteratorr]] == STRING1[Vectorr[it2]])
                {
                    OUT.push_back(make_pair(Vectorr[it2],Vectorr[it2]));
                    swap(STRING1[Vectorr[it2]],STRING2[Vectorr[it2]]);
                    OUT.push_back(make_pair(Vectorr[iteratorr],Vectorr[it2]));
                    swap(STRING1[Vectorr[iteratorr]],STRING2[Vectorr[it2]]);
                    Boolean1 = 1;
                    break;
                }
            }
            if(!Boolean1)
            {
                Boolean2 = true;
                op("No");
                break;
            }
        }
        if(Boolean2)continue;
        op("Yes");
        op(OUT.size());
        f(iteratorr,OUT.size())
        {
            ops(OUT[iteratorr].first+1);
            op(OUT[iteratorr].second+1);
        }
    }
}


