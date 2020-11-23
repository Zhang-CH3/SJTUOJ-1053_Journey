#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 100005;
int n, depth[MAXN], son[MAXN];
double p[MAXN], ans = 0;
bool visited[MAXN];

struct EDGE{
	int v;
};

vector<EDGE> adj[MAXN];

void AddEdge(int u, int v){
	adj[u].push_back((EDGE){v});
	adj[v].push_back((EDGE){u});
}

/*bool IsLeaf(u){
	return (adj[u].size() == 1 && u != 1);
}*/

void search(int root){
	visited[root] = true;
	son[root] = adj[root].size();
	for(int i=0;i<adj[root].size();i++){
		if(visited[adj[root][i].v])son[root]--;
	}
	for(int i=0;i<adj[root].size();i++){
		int v = adj[root][i].v;
		if(visited[v]) continue;
		p[v] = p[root] / son[root];
		depth[v] = depth[root] + 1;
		//printf("%d\t%d\t%0.2lf\n", v, depth[v], p[v]); 
		search(v);
	}
}

int main(){
	cin >> n;
	int u, v;
	for(int i=1;i<n;i++){
		depth[i] = 0;
		p[i] = 1;
		visited[i] = false;
		scanf("%d%d", &u, &v);
		AddEdge(u, v);
	}
	depth[n] = 0;
	p[n] = 1;
	visited[n] = false;
	search(1);
	for(int i=2;i<=n;i++){
		if(adj[i].size() == 1){
			ans += (depth[i] * p[i]);
		}
	}
	ans += 1e-4;
	printf("%0.2lf", ans);
	return 0;
}
