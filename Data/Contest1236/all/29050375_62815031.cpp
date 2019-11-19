#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back 
#define ins insert
#define rs resize
#define br break;
#define cont continue;
#define vi vector<ll>
#define vll vector<long long>
#define si set<ll>
#define sll set<long long>
#define pii pair<ll,ll>
#define pll pair<long long, long long>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vec vector
#define cend cout<<endl;
#define sc second
#define fr first
#define retz return 0;
#define ll_MAX (ll)(1e9*1e9)
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b)  for(int i=a; i<=b; i++)
#define repd(i,a,b) for(int i=a; i>=b; i--)
#define ps(arr, n) for(int i=1; i<n; i++)arr[i]+=arr[i-1];
#define inp(arr, n)for(int i=0; i<n; i++)cin>>arr[i];
#define out(arr, n)for(int i=0; i<n; i++)cout<<arr[i];
#define inp1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define out1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define loop(q) for(auto it:q)
#define loop1(q) for(auto&it:q)
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////


void solve()
{
	int n,m,k;
	cin >> n >> m >> k;
	vector<set<int>> qr(n+1), qc(m+1);
	set<pii> q;
	rep(i,0,k-1)
	{
		int l,r;
		cin >> l >> r;
		qr[l].insert(r);
		qc[r].insert(l);
		q.insert({l,r});
	}
	int t = 0;
	int x = 1;
	int y = 1;
	int cx = 2, cy = 1, cx1 = n, cy1 = m;
	int steps = 0;
	int ans=0;
	while(1)
	{
		if(t==0)
		{
			int temp;
			if(qr[x].size()==0)
				temp=cy1;
			else{
				auto it = qr[x].lower_bound(y);
				if(it==qr[x].end())
				{
					temp = cy1;
				}else temp=*it-1;
			}
			temp = min(temp, cy1);
			if(temp==y && steps>0)
				break;
			ans+=temp-y;
			steps++;
			cy1=temp-1;
			y=temp;
		}

		if(t==1)
		{
			int temp;
			if(qc[y].size()==0)
				temp=cx1;
			else{
				auto it = qc[y].lower_bound(x);
				if(it==qc[y].end())
				{
					temp = cx1;
				}else temp=*it-1;
			}
			temp = min(temp,cx1);
			if(temp==x && steps>0)
				break;
			ans+=temp-x;
			steps++;
			cx1 = temp-1;
			x=temp;
		}

		if(t==2)
		{
			int temp;
			if(qr[x].size()==0)
				temp=cy;
			else{
				auto it = qr[x].lower_bound(y);
				if(it==qr[x].begin())
				{
					temp = cy;
				}else {it--;
					temp=*it+1;}
			}
			temp = max(temp,cy);
			if(temp==y && steps>0)
				break;
			ans+=-temp+y;
			steps++;
			cy=temp+1;
			y=temp;
		}


		if(t==3)
		{
			int temp;
			if(qc[y].size()==0)
				temp=cx;
			else{
				auto it = qc[y].lower_bound(x);
				
				if(it==qc[y].begin())
				{
					temp = cx;
				}else {it--;temp=*it+1;}
			}
			temp = max(temp,cx);
			if(temp==x && steps>0)
				break;
			ans+=-temp+x;
			steps++;
			cx = temp+1;
			x=temp;
		}

		t++;
		t%= 4;
		//cout<<x<<" "<<y<<" "<<ans<<endl;
		//out << cx << " " << cx1 << " " << cy << " " << cy1 << endl;
	}
	if(n*m-ans-1==k)cout<<"Yes";
	else cout<<"No";
}



int32_t main()
{
    speed
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}