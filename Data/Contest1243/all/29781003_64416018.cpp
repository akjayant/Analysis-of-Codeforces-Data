// clang-format off
/* Shivam Sharma
	`They call me Hei$enBerg (~_^)`
	ABV-Indian Institute of Information Technology and Management, Gwalior
	*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector< vector<ll> > vvi;
typedef pair<ll,ll> pii;
typedef map<string,ll> msi;
typedef set<ll> si;
typedef vector< pair<ll,ll> > vpii;


#define T() 	ll t;	cin>>t;		while(t--)
#define p_b		 push_back
#define p_f 		push_front
#define pop_b 		pop_back()
#define pop_f 		pop_front()
#define m_p		make_pair
#define l_b(v,l)     lower_bound (v.begin(), v.end(), l)
#define u_b(v,l)   	 upper_bound (v.begin(), v.end(), l)
#define min_pos(a)		 min_element(a.begin(),a.end())-a.begin()
#define max_pos(a) 		 max_element(a.begin(),a.end())-a.begin()
#define min_el(a) 		 *min_element(a.begin(),a.end())
#define max_el(a)		 *max_element(a.begin(),a.end())
#define cnt(a,l) 		 count(a.begin(),a.end(),l)
#define sort_a(a) 		 sort(a.begin(),a.end())
#define sort_d(a) 		 sort(a.begin(),a.end(),greater<ll>() )
#define summ(a)  	 accumulate(a.begin(),a.end(),0)
#define all(x) x.begin(),x.end()
#define inf      1e9
#define FF first
#define SS second
#define rep(i,a,b)      for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrep(i,a,b)      for(ll i=(ll)(a);i>=(ll)(b);i--)
#define mset(a,b)    	memset(a,b,sizeof(a));
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     endl            '\n'
///==========INPUT=============///
	#define     sc(a)           scanf("%lld",&a);
	#define     sc2(a,b)        scanf("%lld%lld",&a,&b);
	#define     sc3(a,b,c)      scanf("%lld%lld%lld",&a,&b,&c);
	#define     sc4(a,b,c,d)    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
///==========PRINTING=============///
	#define     prarr(arr)      rep(i,0,sizeof(arr)/sizeof(ll)) cout<<arr[i]<<" "; nl
	#define     prvec(v)        rep(i,0,v.size()) cout<<v[i]<<" "; nl
	#define     pr(x)           cout<<x<<"\n";
	#define     pr2(x, y)       cout<<x<<" "<<y<<"\n";
	#define     pr3(x, y, z)    cout<<x<<" "<<y<<" "<<z<<"\n";
///==========DEBUGGING=============///
    #define 	debug(a) 		cout<<"*"<<a<<endl;
   	#define 	debug2(a,b) 	cout<<"$"<<a<<" "<<b<<endl;
   	#define 	debug3(a,b,c) 	cout<<"$"<<a<<" "<<b<<" "<<c<<endl;
	#define 	bug 			cout<<"#"<<endl;
   	#define 	nl 				cout<<'\n';
ll powermod(ll _a,ll _b)    {
        ll _r = 1; while(_b) {if(_b % 2 == 1) _r = ( _r * _a ) ; _b /= 2; _a = ( _a * _a ) ;} return _r;
    }

// clang-format off
int main()
{
	fast
	T()
	{
		ll n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		vector<pii> ans;
		ll f=0;
		rep(i,0,n)
		{
			if(s[i]!=t[i])
			{
				ll tem=-1,p1=-1,p2=-1;
				for(ll j=i+1;j<n;j++)
				{
					if(s[j]==s[i] || t[j]==t[i])
					{
						tem=j;
						break;
					}
					if(t[j]==s[i])
					{
						p1 = j;
					}
					if(s[j]==t[i])
					{
						p2=j;
					}
				}
				if(tem==-1 && p1==-1 && p2==-1)
				{
					f=1;
					break;
				}
				if(tem!=-1)
				{
					
					if(s[i]==s[tem])
					{
						ans.p_b({tem,i});
						swap(t[i],s[tem]);
					}
					else
					{
						ans.p_b({i,tem});
						swap(s[i],t[tem]);
					}
				}
				else
				{
					if(p1!=-1 && p2==-1)
					{
						ans.p_b({p1,p1});
						ans.p_b({p1,i});
						swap(s[p1],t[p1]);
						swap(t[i],s[p1]);
					}
					else if(p2!=-1 && p1==-1)
					{
						ans.p_b({p2,p2});
						ans.p_b({i,p2});
						swap(s[p2],t[p2]);
						swap(s[i],t[p2]);
					}
					else
					{
						if(p1<p2)
						{
							ans.p_b({p1,p1});
						ans.p_b({p1,i});
						swap(s[p1],t[p1]);
						swap(t[i],s[p1]);
						}
						else
						{
							ans.p_b({p2,p2});
						ans.p_b({i,p2});
						swap(s[p2],t[p2]);
						swap(s[i],t[p2]);
						}
					}
				}
			}
		}
		if(ans.size()>2*n)
			f=1;
		if(f==1)
			cout<<"No"<<endl;
		else
		{
			cout<<"Yes"<<endl;
		//	cout<<s<<" "<<t<<endl;
			cout<<ans.size()<<endl;
			rep(i,0,ans.size())
			{
				cout<<ans[i].FF+1<<" "<<ans[i].SS+1<<endl;
			}
		}
			
			
	}
	
}
