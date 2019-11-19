#include<bits/stdc++.h>

using namespace std;

#define NMAX 2003

const long long MOD = 1000000007;

long long clase[NMAX];

long long getClase(long long nodo) {
    if(clase[nodo] == -1)
        return nodo;
    clase[nodo] = getClase(clase[nodo]);
    return clase[nodo];
}

int main() {
    for(long long i = 0; i < NMAX; i++)
        clase[i] = -1;
    long long n;
    cin>>n;
    priority_queue<pair<long long, pair<long long, long long> > > pq;
    long long x[n], y[n];
    for(long long i = 0; i < n; i++)
        cin>>x[i]>>y[i];

    long long c[n];
    for(long long i = 0; i < n; i++) {
        cin>>c[i];
        pq.push(make_pair(-c[i], make_pair(i, n)));
    }

    long long k[n];
    for(long long i = 0; i < n; i++) {
        cin>>k[i];
        for(long long j = 0; j < i; j++) {
            long long coste = (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            pq.push(make_pair(-coste, make_pair(j, i)));
        }
    }

    //cerr<<"FRONT: "<<pq.top().first<<endl;

    long long sol = 0;

    vector<long long> c_conexiones;
    vector<pair<long long, long long> > e_conexiones;

    while(!pq.empty()) {
        long long c = pq.top().first;
        long long a = pq.top().second.first;
        long long b = pq.top().second.second;
        pq.pop();

        if(getClase(a) != getClase(b)) {
            //cerr<<"ANADO "<<a<<' '<<b<<": "<<getClase(a)<<' '<<getClase(b)<<endl;
            sol -= c;
            clase[getClase(a)] = b;

            if(b == n)
                c_conexiones.push_back(a);
            else
                e_conexiones.push_back(make_pair(a, b));
        }
    }
    cout<<sol<<endl;
    cout<<c_conexiones.size()<<endl;
    for(long long i = 0; i < (long long)c_conexiones.size(); i++)
        cout<<c_conexiones[i]+1<<' ';
    cout<<endl;
    cout<<e_conexiones.size()<<endl;
    for(long long i = 0; i < (long long)e_conexiones.size(); i++)
        cout<<e_conexiones[i].first+1<<' '<<e_conexiones[i].second+1<<endl;
}