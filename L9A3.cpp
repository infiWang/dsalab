#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <ext/pb_ds/priority_queue.hpp>
#include <cstdio>
#include <iostream>

struct Edge {
    int u, v, w;

    Edge(int _u = 0, int _v = 0, int _w = 0) {
        u = _u, v = _v, w = _w;
    }

    bool operator < (const Edge tEdge) const {
        return w > tEdge.w;
    }

    Edge operator = (const Edge tEdge) {
        u = tEdge.u, v = tEdge.v, w = tEdge.w;
        return tEdge;
    }
}
emptyEdge;

struct Vertex {
    std::vector<Edge> inEdge, out;

    Vertex() {
        inEdge.clear(), out.clear();
    }
};

inline int qRead() {
    int ans = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}

inline void addEdge(Vertex* graph,Edge cmpEdge) {
    int u = cmpEdge.u;
	for(std::vector<Edge>::iterator it = graph[u].out.begin();it < graph[u].out.end();it++) {
		if(it -> v == cmpEdge.v && it -> w > cmpEdge.w) {
            *it = cmpEdge;
            return;
		}
	}
    graph[u].out.push_back(cmpEdge);
}

void dijkstra(int S,int N,Vertex graph[],int* dis) {
    bool isAccurate[1 + N];
    memset(isAccurate,false,sizeof(isAccurate));
    for(int i = 1;i <= N;i++)
    {
        dis[i] = 0x7FFFFFFF;
    }
    dis[0] = dis[S] = 0;
    __gnu_pbds::priority_queue<Edge> heap;
    heap.push(Edge(0, S, 0));

    while(!heap.empty())
    {
        int u = heap.top().v; heap.pop();
        if(isAccurate[u]) continue;
        isAccurate[u] = true;
        for(std::vector<Edge>::iterator it = graph[u].out.begin();it < graph[u].out.end();it++)
        {
            int u = (*it).u, v = (*it).v, w = (*it).w;
            if(!isAccurate[v] && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                heap.push(Edge(u, v, dis[v]));
            }
        }
    }
}

int main()
{
    //freopen("in","r",stdin);
	int N,M,S;
    std::cin >> N >> M >> S;
    Vertex graph[1 + N];

    for(int i = 1;i <= M;i++) {
        int Fi = qRead(), Gi = qRead(), Wi = qRead();
        addEdge(graph,Edge(Fi, Gi, Wi));
    }
	
    int disS[1 + N];

    dijkstra(S,N,graph,disS);

    for(int i = 1;i <= N;i++)
    {
        printf("%i ",disS[i]);
    }
	return 0;
}