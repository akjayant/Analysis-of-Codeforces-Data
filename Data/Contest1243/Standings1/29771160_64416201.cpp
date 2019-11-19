#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <array>
#include <string>
#include <queue>
#include <random>
#include <memory>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::set<size_t>> edges(n);

    for(size_t i = 0; i < m; ++i)
    {
        size_t from, to;
        std::cin >> from >> to;
        --from; --to;

        edges[from].insert(to);
        edges[to].insert(from);
    }

    size_t num_cliques = 0;
    std::vector<char> cliqued(n);

    for(size_t i = 0; i < n; ++i)
    {
        if(!cliqued[i])
        {
            cliqued[i] = true;

            std::vector<size_t> verts;
            std::set<size_t> curr = edges[i];

            for(size_t j = 0; j < n; ++j)
            {
                if(curr.find(j) == curr.end())
                {
                    verts.push_back(j);
                    cliqued[j] = true;
                }
            }

            while(!verts.empty())
            {
                size_t vert = verts.back();
                verts.pop_back();

                size_t verts_size = verts.size();

                for(size_t w : curr)
                {
                    if(edges[vert].find(w) == edges[vert].end())
                    {
                        verts.push_back(w);
                        cliqued[w] = true;
                    }
                }

                for(size_t j = verts_size; j < verts.size(); ++j)
                {
                    curr.erase(verts[j]);
                }
            }

            ++num_cliques;
        }
    }

    std::cout << (num_cliques - 1);

    return 0;
}
