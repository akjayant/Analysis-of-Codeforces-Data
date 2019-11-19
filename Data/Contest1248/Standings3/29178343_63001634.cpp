#include <bits/stdc++.h>

using namespace std;

#define taskname "1248D1"
#define forinc(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define fordec(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define foreach(i, x) for (auto &i : x)
#define ms(x, n) memset(x, n, sizeof(x))
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define fi first
#define se second
#define pb push_back
#define pf push_front

template<typename TH>
void _dbg(const char* sdbg, TH h)
{
	cerr << sdbg << " = " << h << "\n";
}

template<typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t)
{
	while (*sdbg != ',') cerr << *sdbg++;
	cerr << " = " << h << ",";
	_dbg(sdbg + 1, t...);
}

#define db(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define chkpt cerr << "--- Checkpoint here ---\n";

const int N=5e2+2,INF=1e9;

int n,a[N],s[N],minPref[N],minSuf[N];
int st[4*N],lz[4*N];

void Build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=s[l];
        lz[id]=0;
        return;
    }
    Build(id*2,l,(l+r)/2);
    Build(id*2+1,(l+r)/2+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
}

void PushDown(int id,int l,int r)
{
    if(lz[id]==0)
    {
        return;
    }
    st[id]+=lz[id];
    if(l!=r)
    {
        lz[id*2]+=lz[id];
        lz[id*2+1]+=lz[id];
    }
    lz[id]=0;
}

void Increase(int id,int l,int r,int i,int j,int val)
{
    PushDown(id,l,r);
    if(r<i||l>j)
    {
        return;
    }
    if(i<=l&&r<=j)
    {
        lz[id]=val;
        PushDown(id,l,r);
        return;
    }
    Increase(id*2,l,(l+r)/2,i,j,val);
    Increase(id*2+1,(l+r)/2+1,r,i,j,val);
    st[id]=min(st[id*2],st[id*2+1]);
}

int Query(int id,int l,int r,int i,int j)
{
    PushDown(id,l,r);
    if(r<i||l>j)
    {
        return INF;
    }
    if(i<=l&&r<=j)
    {
        return st[id];
    }
    return min(Query(2*id,l,(l+r)/2,i,j),Query(2*id+1,(l+r)/2+1,r,i,j));
}

int Calc()
{
    forinc(i,1,n)
    {
        s[i]=s[i-1]+a[i];
    }
    forinc(i,1,n)
    {
        minPref[i]=min(minPref[i-1],s[i]);
    }
    fordec(i,n,1)
    {
        minSuf[i]=min(minSuf[i+1],s[i]);
    }
//    Build(1,1,n);
    int res=0;
    int l=0,r=1;
    forinc(i,1,n)
    {
        // [r..n] [1..l]
//        Increase(1,1,n,r,n,-s[l]);
//        int tmp1=Query(1,1,n,n,n);
//        Increase(1,1,n,1,l,tmp1);
        int newMinSuf=minSuf[r]-s[l];
        int tmp=s[n]-s[l];
        int newMinPref=minPref[l]+tmp;
        if(min(newMinSuf,newMinPref)>=0)
        {
            res++;
        }
//        if(Query(1,1,n,1,n)>=0)
//        {
//            res++;
//        }
//        Increase(1,1,n,r,n,s[l]);
//        Increase(1,1,n,1,l,-tmp1);
        l++;
        r++;
    }
    return res;
}

void Solve()
{
    cin>>n;
    forinc(i,1,n)
    {
        char c;
        cin>>c;
        if(c=='(')
        {
            a[i]=1;
        }
        else
        {
            a[i]=-1;
        }
        s[i]=s[i-1]+a[i];
    }
    if(s[n]!=0)
    {
        cout<<0<<'\n'<<1<<' '<<1<<'\n';
        return;
    }
//    swap(a[7],a[8]);
//    db(Calc());
    int maxVal=0;
    int bestI=0,bestJ=0;
    forinc(i,1,n)
    {
        forinc(j,i,n)
        {
            swap(a[i],a[j]);
            int tmp=Calc();
            if(tmp>maxVal)
            {
                maxVal=tmp;
                bestI=i;
                bestJ=j;
            }
            swap(a[i],a[j]);
        }
    }
//    cout<<maxVal<<'\n';
    cout<<maxVal<<'\n'<<bestI<<' '<<bestJ<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen(taskname".INP","r",stdin);
//	freopen(taskname".OUT","w",stdout);
	#endif // ONLINE_JUDGE
	Solve();
    return 0;
}
