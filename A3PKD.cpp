#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUParent(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findUParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        u = findUParent(u);
        v = findUParent(v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
};
class Graph
{
    vector<vector<pair<int, int>>> adjList;
    vector<string> vertex;
    int vertices, edges;

public:
    Graph()
    {
        cout << "Enter no. of vertices:";
        cin >> vertices;
        cout << "Enter no. of edges: ";
        cin >> edges;
        for (int i = 0; i < vertices; i++)
        {
            string temp;
            cout << "Enter City " << i + 1 << " : ";
            cin >> temp;
            vertex.push_back(temp);
        }
        adjList.resize(vertices);
    }

    void input()
    {
        for (int i = 0; i < edges; i++)
        {
            int src, dest, wt;
            cout << "Enter Source vertex no.(0 - based) : ";
            cin >> src;
            cout << "Enter Destination vertex no.(0 - based) : ";
            cin >> dest;
            cout << "Enter weight between the edges: ";
            cin >> wt;
            adjList[src].push_back({dest, wt});
            adjList[dest].push_back({src, wt});
        }
    }

    void Dijakstra()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(vertices, INT_MAX);
        int start;
        cout << "Enter the starting vertex: ";
        cin >> start;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int u = p.second;
            int dis = p.first;
            for (auto it : adjList[u])
            {
                int v = it.first;
                if (dis + it.second < dist[v])
                {
                    dist[v] = dis + it.second;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Minimum distance of all the cities from source are as follows: ";
        for (int i = 0; i < vertices; i++)
        {
            cout << vertex[start] << "--> " << vertex[i] << " : " << dist[i] << endl;
        }

        cout << endl
             << endl;
    }

    void Prims()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(vertices, 0);

        int start;
        cout << "Enter starting vertex: ";
        cin >> start;
        pq.push({0, start});
        int minCost = 0;
        vector<int> path;

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int u = p.second;
            int wt = p.first;
            if (visited[u])
            {
                continue;
            }
            minCost += wt;
            path.push_back(u);
            visited[u] = 1;
            for (auto it : adjList[u])
            {
                int v = it.first;
                int w = it.second;
                if (!visited[v])
                {
                    pq.push({w, v});
                }
            }
        }

        cout << "Minimum cost of spanning tree is: " << minCost << endl;
        cout << "Path is: ";
        cout << vertex[start] << " ";
        for (auto it : path)
        {
            if (it == start)
            {
                continue;
            }
            cout << "-> " << vertex[it] << " ";
        }

        cout << endl;
    }

    void Kruskal()
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < vertices; i++)
        {
            for (auto it : adjList[i])
            {
                edges.push_back({it.second, {i, it.first}});
            }
        }

        sort(edges.begin(), edges.end());
        DisjointSet ds(vertices);
        int minCost = 0;
        for (auto it : edges)
        {
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if (ds.findUParent(u) != ds.findUParent(v))
            {
                minCost += w;
                ds.unionByRank(u, v);
            }
        }

        cout << "Minimum cost of spanning tree is: " << minCost << endl;
    }
};

int main()
{

    Graph g;
    g.input();
    g.Dijakstra();

    g.Prims();

    g.Kruskal();
    return 0;
}
