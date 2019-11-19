#include <bits/stdc++.h>
#define ll long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define fni(x,y,z) for(int i=(int)x;i>=(int)y;i-=(int)z)
#define fnj(x,y,z) for(int j=(int)x;j>=(int)y;j-=(int)z)
#define fpi(x,y,z) for(int i=(int)x;i<=(int)y;i+=(int)z)  
#define fpj(x,y,z) for(int j=(int)x;j<=(int)y;j+=(int)z)
#define fpk(x,y,z) for(int k=(int)x;k<=(int)y;k+=(int)z)  
#define fnk(x,y,z) for(int k=(int)x;k>=(int)y;k-=(int)z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 1000000;
#define maxn 300005
#define mod (int)10e9+7
int find(string s)
{
    int l = s.size(),temp = 0,ans = 0,fn;
    int dpf[l],dpb[l],mx =0,pos[l],mi = 0;
    fpi(0,l-1,1) dpb[i] = INT_MAX;
    fpi(0,l-1,1)
    {
        if(i==0)
        {
            if(s[i]=='(') {dpf[i] = 1;}
            else {dpf[i] = -1;}
        }
        else
        {
            if(s[i]=='(')
            {
                dpf[i] = dpf[i-1] + 1;
            }
            else
            {
                dpf[i] = dpf[i-1] - 1;
            }
        }
        if(dpf[i]<=mi) {pos[i] = 1;mi = dpf[i];}
        else pos[i] = 0;
        //d(i<<" "<<dpf[i]<<" "<<pos[i])
    }
    fni(l-1,0,1)
    {
        if(i==l-1)
        {
            if(s[i]=='(') dpb[i] = 1;
            else dpb[i] = -1;
        }
        else
        {
            if(s[i]=='(')
            {
                dpb[i] = dpb[i+1] + 1;
            }
            else
            {
                dpb[i] = dpb[i+1] - 1;
            }
        }
    }
    fni(l-1,0,1)
    {
        if(i==0)
        {
            if(dpb[i]>=mx && dpb[i]==0) ans++;
        }
        else
        {
            if(dpb[i]>=mx)
            {
                if(dpb[i]+dpf[i-1]==0 && pos[i-1])
                {
                    ans++;
                }
                mx = max(dpb[i],mx);
            }
        }
    }
    return ans;
}
void solve()
{
    int n,ans=-5,r,temp;
    cin>>n;
    string s;
    cin>>s;
    int l = s.size();
    //swap(s[7],s[6]);
    fpi(0,n-1,1)
    {
        fpj(0,n-1,1)
        {
            swap(s[i],s[j]);
            temp = find(s);    
            if(temp>ans)
            {
                l = i+1;
                r = j+1;
                ans = temp;
            }
            swap(s[i],s[j]);
        }
    }
    d(ans)
    d(l<<" "<<r)
}
int main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t=1;
    //cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
