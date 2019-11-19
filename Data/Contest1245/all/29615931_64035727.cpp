#include <bits/stdc++.h>
using namespace std;

class DSU {
    private:
        int* id; 
        int* size; 
        int* stations_id; 
        int* costs; 
        
    public:
        DSU ( int vertices, long long* c) {
            id = new int[ vertices ];
            size = new int[ vertices ]; 
            stations_id = new int[ vertices ]; 
            costs = new int[ vertices ]; 
            for ( int i = 0; i < vertices; ++i ) {
                id[ i ] = i; 
                size[ i ] = 1; 
                stations_id[ i ] = i; 
                costs[ i ] = c[ i ]; 
            }
        }
        
        int find_parent ( int v ) {
            if ( id[ v ] == v ) {
                return v; 
            }
            
            int parent_v = find_parent( id[ v ] ); 
            id[ v ] = parent_v; 
            return id[ v ]; 
        }  
        
        int get_size ( int u ) {
            return size[ find_parent( u ) ]; 
        }
        
        int get_cost ( int u ) {
            return costs[ find_parent( u ) ]; 
        }
        
        int get_station_id ( int u ) {
            return stations_id[ find_parent( u ) ];
        }
        bool are_connected ( int u, int v ) {
           return find_parent( u ) == find_parent( v );     
        }
        
        void merge ( int u, int v ) {
            int parent_u = find_parent( u );
            int parent_v = find_parent( v ); 
            int new_station_id; 
            int new_station_cost; 
            if ( get_cost( u ) < get_cost( v ) ) {
                new_station_id = get_station_id( u ); 
                new_station_cost = get_cost( u ); 
            } else {
                new_station_id = get_station_id( v );
                new_station_cost = get_cost( v ); 
            }
            
            if ( size[ parent_u ] < size[ parent_v ] ) {
                id[ parent_u ] = parent_v; 
                size[ parent_v ] += size[ parent_u ]; 
                stations_id[ parent_v ] = new_station_id;
                costs[ parent_v ] = new_station_cost;
            } else {
                id[ parent_v ] = parent_u; 
                size[ parent_u ] += size[ parent_v ]; 
                stations_id[ parent_u ] = new_station_id;
                costs[ parent_u ] = new_station_cost;
            }
        }
};

struct Edge {
    int u; 
    int v; 
    long long weight; 
    
    bool operator < ( Edge &other ) {
        return this->weight < other.weight;
    }
};


int main() {
    int n; 
    cin >> n;
    
    long long x[ n ]; 
    long long y[ n ]; 
    for ( int i = 0; i < n; ++i ) {
        cin >> x[ i ] >> y[ i ]; 
    }
    long long c[ n ]; 
    for ( int i = 0; i < n; ++i ) {
        cin >> c[ i ]; 
    }
    long long k[ n ]; 
    for ( int i = 0; i < n; ++i ) {
        cin >> k[ i ]; 
    }
    
    vector<Edge> edges;
    edges.reserve( n*(n - 1)/2 );
    for ( int i = 0; i < n; ++i ) {
        for ( int j = i + 1; j < n; ++j ) {
            long long cost = (abs(x[i] - x[j]) + abs(y[i] - y[j]))*(k[i] + k[j]);
            edges.push_back( {i, j, cost} ); 
        }
    }
    sort( edges.begin(), edges.end() ); 
    
    long long total_cost = 0; 
    for ( int i = 0; i < n; ++i ) {
        total_cost += c[ i ]; 
    }
    
    DSU disjoint_set( n, c ); 
    bool added_edges[ edges.size() ] = { false }; 
    int components = n; 
    int connections = 0; 
    for ( int i = 0; i < edges.size(); ++i ) {
        int u = edges[ i ].u; 
        int v = edges[ i ].v; 
        long long weight = edges[ i ].weight; 
        if ( !disjoint_set.are_connected( u, v )  &&  
        weight < max( disjoint_set.get_cost( u ), disjoint_set.get_cost( v ) ) ) {
            total_cost -= max( disjoint_set.get_cost( u ), disjoint_set.get_cost( v ) );
            total_cost += weight; 
            disjoint_set.merge( u, v ); 
            added_edges[ i ] = true;
            components--;
            connections++; 
        }
    }
    
    cout << total_cost << endl; 
    cout << components << endl; 
    bool printed[ n ] = { false }; 
    for ( int i = 0; i < n; ++i ) {
        if ( !printed[ disjoint_set.get_station_id( i ) ] ) {
            cout << disjoint_set.get_station_id( i ) + 1 << " ";
            printed[ disjoint_set.get_station_id( i ) ] = true; 
        }
    }
    cout << endl;
    
    cout << connections << endl; 
    for ( int i = 0; i < edges.size(); ++i ) {
        if ( added_edges[ i ] ) {
            cout << edges[ i ].u + 1 << " " << edges[ i ].v + 1 << endl;
        }
    }
    
    return 0;
}
