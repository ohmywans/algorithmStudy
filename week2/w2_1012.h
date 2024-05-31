// BOJ 1012번: 유기농 배추 - 마지막에 디버깅으로 행렬들이 초기화되고 있지 않음을 알아냄
						   
#include <iostream>
using namespace std;

// T: TC 개수
// N, M, K: 가로, 세로의 길이, 위치의 개수
// y, x: 좌표 (y, x)
// sy, sx: 입력 받을 배추의 위치 (sy, sx)
// a[][]: 배추 위치가 담긴 배추 밭 행렬
// visited[][]: 방문 여부가 담긴 a[][]와 동일한 크기의 행렬

int T, N, M, K, y, x, sy, sx, a[50][50], visited[50][50];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

// DFS 알고리즘 & Connected component
void dfs(int y, int x) {
	// 현재 위치 방문 도장 찍기
	visited[y][x] = 1;
	
	// 4방향 이동
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; // ny = next_y
		int nx = x + dx[i]; // nx = next_x
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue; // underflow, overflow 방지
		if (a[ny][nx] == 0) continue;	// 배추가 없는 위치이거나
		if (visited[ny][nx]) continue;  // 이미 방문한 위치이면 패스~
		dfs(ny, nx);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T; 	
	while(T--) { 						// TC 개수만큼 while문 반복
		cin >> N >> M >> K;
		int ret = 0;					// 지렁이 마리수 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				a[i][j] = 0;			// TC 바뀔때마다 해당 행렬 초기화
				visited[i][j] = 0;		// (")
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> sy >> sx;
			a[sy][sx] = 1;
		}
		// // 디버깅
		// for (int i = 0; i < N; i++) {
		// 	for (int j = 0; j < M; j++) {
		// 		cout << a[i][j] << " ";
		// 	}
		// 	cout << '\n';
		// }
		
		for (int from = 0; from < N; from++) {
			for (int to = 0; to < M; to++) {
				if (a[from][to] && visited[from][to] == 0) {
					dfs(from, to);
					ret++;
				}
			}
		}
		cout << ret << '\n';
	}
		
	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std; 
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int m, n, k, y, x, ret, ny, nx, t;
int a[51][51];
bool visited[51][51]; 
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;
        if(a[ny][nx] == 1 && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
    return;
}

int main(){ 
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
		// 테스트 케이스 별 초기화를 아래와 같이 함
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = 0;
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            a[y][x] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << "\n"; 
    }
    return 0;
}
*/