#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> ii;
vector<ii> G[N];
int dis[N];
void dijkstra(int node){

    dis[node] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, node});
    while(not q.empty()){
        int u = q.top().second;
        int d = q.top().first;
        q.pop();
        if(d > dis[u])continue;
        for(ii nodo : G[u]){
            int v = nodo.first;
            int cost = nodo.second;
            if(dis[u] + cost < dis[v]){
                dis[v] = dis[u] + cost;
                q.push({dis[v], v});
            }
        }
    }

}


int main(){
    int n, m;
    cin >> n >> m;
    int u, v, cost;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> cost;
        G[u].push_back({v, cost});
    }

    // caminos en infinito
    for(int i = 0; i < n; i++){
        dis[i] = 1e9;
    }
    int node = 0;
    dijkstra(node);

    // mostrar el vector de distancias
    for(int i = 0; i < n; i++){
        cout << "dis de " << node << " a " << i << " es :" << dis[i] << '\n';
    }




    return 0;
}
