// BOJ 1325번: 효율적인 해킹
#include <bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int dp[10001], mx, visited[10001], n, m, a, b;
 
int dfs(int here) { // 유명한 형태의 그래프 기반 dfs 형태 (암기하기)
	visited[here] = 1;
	int ret = 1; 
	for(int there : v[here]){
		if(visited[there]) continue;
		ret += dfs(there); 
	} 
	return ret;
} 
int main() { 
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cin >> n >> m;  
	while (m--) {
     	cin >> a >> b;  
	    v[b].push_back(a);					 // 나는 a->b로 넣었는데 그러면 안되니까 b->a로 넣어준다!
	} 
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited)); // visited 초기화
		dp[i] = dfs(i); 					 // dfs[노드]의 결과(해당 노드 포함 연결된 노드 수)를 배열에 담기
		mx = max(dp[i], mx);				 // 가장 효율적인 해킹이 될 노드의 개수가 mx에 저장됨
	} 
	for (int i = 1; i <= n; i++) {
		if (mx == dp[i]) cout << i << " ";   // mx와 같은 값의 노드를 출력
	}
		return 0;
}
/* 유명하고 자주 나오는 형태의 그래프 문제 형태(dfs함수의 for문이 중요!)
int dfs(int here) {
	int ret = 1;
	for (int there : adj[here]) { // 단방향으로 연결된 자식(?)노드에 대한 개수가 ret에 리턴됨
		if (visited[there]) continue;
		visited[there] = 1;
		ret += dfs(there);
	}
	return ret;
}
int main() {
	adj[1].push_back(2);
	adj[1].push_back(3);
	visited[1] = 1;
	cout << dfs(1) << '\n';
	return 0;
}
*/
