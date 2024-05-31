/* BOJ 2178번: 미로 탐색 - 큐를 활용한 BFS 알고리즘의 전형적인 문제
			 tie() 사용을 위해 tuple 라이브러리 include 필수!!!!!
			 답안 비교: 답안과 로직 동일 / input 받을때 주석 처리한 곳 주목하기 */
#include <iostream>
#include <queue>
#include <tuple> // tie() 사용을 위함
using namespace std;

int N, M, y, x, a[104][104], visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
string input;

void bfs() {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y, x});
	
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue; // 예외 처리는 무조건 이거 먼저 와야함!
			if (a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
	cout << visited[N-1][M-1] << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			if (input[j] == '1') a[i][j] = 1;
		}
	}
	// input 받을때 string으로 위처럼 해도되고, 아래 주석처럼 해도된다.*******************
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < M; j++) {
	// 		scanf("%1d", &a[i][j]); // 1 하고 d 임. 정수 한 자리씩 받기
	// 	}
	// }
	
	
	// 입력 받은 지도 정보 디버깅
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < M; j++) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	bfs();
	
	return 0;
}


/* 정답 코드
#include<bits/stdc++.h>
using namespace std; 
const int max_n = 104; 
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x; 
int main(){ 
    scanf("%d %d", &n, &m); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    } 
    queue<pair<int, int>> q;  
    visited[0][0] = 1;
    q.push({0, 0});  
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue; 
            if(visited[ny][nx]) continue; 
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx}); 
        } 
    }
    printf("%d", visited[n - 1][m - 1]); 
    return 0;
}  
*/