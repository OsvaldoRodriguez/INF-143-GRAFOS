#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef long long ll;
typedef pair<ll, int> ii;
vector<ii> G[N];
ll dis[N];
int parent[N];
void dijkstra(int node){ // O (m log n)

    dis[node] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0LL, node});
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
                parent[v] = u;
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
        u--;
        v--;
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }

    // caminos en infinito
    for(int i = 0; i < n; i++){
        dis[i] = 2e18;
    }
    int node = 0;
    dijkstra(node);


    stack<int> s;
    int idx = n - 1;
    if(dis[idx] != 2e18){
        s.push(idx);
        while(idx != 0){
            idx = parent[idx];
            s.push(idx);
        }

        while(not s.empty()){
            cout << s.top() + 1 << ' ';
            s.pop();

        }
    }else
        cout << -1 << '\n';






    return 0;
}
