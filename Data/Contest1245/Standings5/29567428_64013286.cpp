#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long cd,x[2300],cur,c[2340],kq,y[2340],k[2340],lab[2340];
#define pi pair<long long,pair<long long,long long> >
#define pi1 pair<long long,long long>
vector <long long> result;
vector <pi1> kq1;
pi a[3000000];
long long dad(long long u)
{
		while (lab[u] > 0)
		{
				u = lab[u];
		}
		return u;
}
void united(long long u , long long v)
{
		if (lab[u] > lab[v])
		{
				swap(u , v);
		}
		lab[u] += lab[v];
		lab[v] = u;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
		cin >> cd;
		for (long long i = 1 ; i <= cd ; i++)
		{
				cin >> x[i] >> y[i];
		}
		long long cur = 0;
		for (long long i = 1 ; i <= cd ; i++)
		{
				cin >> c[i];
				cur++;
				lab[i] = lab[cd+1] = -1;
				a[cur] = pi(c[i] , make_pair(cd + 1 , i));
		}
		for (long long i = 1 ; i <= cd ; i++)
		{
				cin >> k[i];
		}
		for (long long i = 1 ; i <= cd ; i++)
		{
				for (long long e = i+1 ; e <= cd ; e++)
				{
						cur++;
						long long cost = (k[i] + k[e]) * (abs(x[i] -x[e]) + abs(y[i] - y[e]));
						a[cur] = pi(cost , make_pair(i , e));
				}
		}
		sort(a + 1 , a + cur + 1);
		for (long long i = 1 ; i <= cur ; i++)
		{
				long long u = a[i].second.first;
				long long v = a[i].second.second;
				long long dadu = dad(u) , dadv = dad(v);
				if (dadu != dadv)
				{
						united(dadu , dadv);
						kq += a[i].first;
						if (u == cd + 1 || v == cd + 1)
						{
								result.push_back(v);
						}
						else
						{
								kq1.push_back(pi1(u,v));
						}
				}
		}
		cout << kq<<'\n';
		cout <<result.size()<<'\n';
		while (result.size() != 0)
		{
				cout <<result.back()<<' ';
				result.pop_back();
		}
		cout <<'\n';
		cout <<kq1.size()<<'\n';
		while (kq1.size() != 0)
		{
				cout <<kq1.back().first<<" "<<kq1.back().second<<'\n';
				kq1.pop_back();
		}

}
