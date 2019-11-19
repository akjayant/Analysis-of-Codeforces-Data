#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
 
int dfn[N];
 
set < pair < int, int > > s;
set< int > unv;
long long n, m;
 
int bfs(int x){
 
	queue< int > q;
	q.push(x);
	int cont = 0;
   unv.erase(x);
	while( !q.empty()){
		cont++;
		int id = q.front();
		q.pop();
		
		for( auto it = unv.begin(); it != unv.end(); ){
			int v = *it++;
			if( s.count({id,v}) || id == v ) continue;
			unv.erase(v);
			q.push(v);
		}
	}
	return cont;
}
 
 
 
int main() 
{
	scanf("%lld %lld", &n, &m);
	long long rem = m - (n * ( n - 1 ) / 2);
 
	if( rem >= n ){
		printf("1\n%lld\n", n);
		return 0;
	}
	
	for(int i = 1; i<=n; i++)
		unv.insert(i);
	for(int i = 0; i<m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		s.insert({x,y});
		s.insert({y,x});
	}
 
	vector < int > sc;
	for(int i = 1; i<=n; i++)
		if( unv.count(i) ){
			sc.push_back(bfs(i));
		}
 
	sort( sc.begin(), sc.end());
 
	printf("%d\n", int(sc.size()) - 1);
    return 0;
}