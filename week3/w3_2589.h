// BOJ 2589번: 보물섬
#include<bits/stdc++.h>
using namespace std; 
int n, m, mx, visited[54][54]; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 
char a[54][54];
void bfs(int y, int x){
    memset(visited, 0, sizeof(visited)); 
    visited[y][x] = 1; 
    queue<pair<int, int>> q; 
    q.push({y, x}); 
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
            if(visited[ny][nx]) continue; 
            if(a[ny][nx] == 'W')continue;
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
        }
    }
    return;
}
int main(){
    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j]; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L') bfs(i, j); 
        }
    } 
    cout << mx - 1 << "\n";
}
/* 내가 한 풀이: (오래 걸림 + 로직은 같음 + 좀 더 간소화 버전이 정답)
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;
string input;
int n, m, a[51][51], visited[51][51], y, x, mx, ret, answer, s, t;
vector<pair<int, int>> landLists;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

// 최단거리니까 bfs()
void bfs() {			// 인자 y, x 넘겼어야 해
	// 육지 좌표 (s, t)를 방문 처리 후, (y, x)에 넘겨 BFS : 바로 넘겼어도 돼
	queue<pair<int, int>> q;
	visited[s][t] = 1;	//  s,t 대신 y,x 
	q.push({s, t});		//  s,t 대신 y,x 
	y = s, x = t;		//: 없어도 됨

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
			if (visited[ny][nx] || a[ny][nx] == 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
			// 여기에 바로 mx 구하는 거 했어도 돼
		}
	}
	// 만들어진 visited 맵에서 가장 큰 원소 추출: 없어도 됨
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mx = max(mx, visited[i][j]);
		}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			if (input[j] == 'L') {
				a[i][j] = 1;
				landLists.push_back({i, j});		// Land(육지, 1)인 위치 받기: 없어도 됨
				// 여기서 바로 L인 위치에 bfs 돌리고 (i, j) 같이 넘기기
			}
			else if (input[j] == 'W') a[i][j] = 0; //: 없어도 됨
		}
	}
	// 각각 육지에 대해 bfs() 돌리고 s, t에 y, x 넘기기: 없어도 됨
	for (pair<int, int> b : landLists) {
		memset(visited, 0, sizeof(visited));
		s = b.first, t = b.second;
		bfs();
	}

	// 시작 지점에서 '이동하는 거리'니까 자기 자신 빼야함
	cout << mx-1 << '\n';
	return 0;
}
*/