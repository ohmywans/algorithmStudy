// BOJ 14502번: 연구소 - GG(시간 초과)
/* 내 아이디어: 시간 초과 및 복잡함 (사실상 바이러스 관점에서 바이러스 내의 최단 거리를 고려하려 했음 -> 변수가 많다)
1. 0과 2로 저장된 곳의 최단거리가 최소(bfs)여야하고, 
2. 이를 둘러싼 1의 개수가 맨 처음 입력받은 a[][]에 비해 3개만 늘어나면 된다.
3. 2 주변에 ny, nx를 반복 계산하면서 주변 0인 자리를 1로 바꿈.
4. 위의 내용을 while문에 넣고, 1,2번을 만족하면 break가 나도록 함.
5. 최단거리는 connected component(dfs)를 배열로 구역을 나누어, 해당 구역의 최단거리를 min(prev, curr)로 저장,
6. 전체적으로 1의 개수가 기존+3개 이면 멈춤

스승님 아이디어:
0. 무식하게 풀 생각 -> 최대 범위로 시간 복잡도 계산 -> 어? 되네?
1. 3개짜리 벽을 세워 in 최대 8*8 map에 (64개)
2. 해당 케이스마다 2인 지점에서 dfs or bfs로 탐색 + 안전영역 카운팅
3. 카운팅 수 제일 많으면 출력, 다음 경우의 수 고려해서 다시 0으로 초기화
*/
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int a[10][10], visited[10][10], n, m, ret;
vector<pair<int, int>> virusList, wallList;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

// 바이러스 위치로부터 dfs() 이동
void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];.
		// 오버/언더플로우 검사 || 방문 여부 || 벽 검사
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}
int solve(){
	// 경우의 수마다 visited 배열을 초기화해줘야함 
	// (Tip): 경우의 수를 연산하는 경우 경우의 수마다 초기화를 해주는게 일반적임
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0); 
	// 담아둔 바이러스 리스트를 기반으로 dfs()
    for(pair<int, int> b : virusList){
        visited[b.first][b.second] = 1; // 방문한 바이러스 위치는 1
        dfs(b.first, b.second);
    } 
	// 안전 영역 카운팅
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
			// 침투 가능한 영역(0)이고 방문 X이면 cnt++
            if(a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    } 
    return cnt;  
}
// 무식하게 풀어도 시간 복잡도 널널해!
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) virusList.push_back({i, j}); // 바이러스 위치를 담아두면 퍼뜨리는 로직에서 위치를 쉽게 얻어올 수 있음.
            if(a[i][j] == 0) wallList.push_back({i, j});  // 벽(1)에 바이러스 침투 X, 되는 곳만 거르기 위해 따로 벡터에 담는다.
        }
    }
	// 64C3을 위한 중첩 for문 (삼중 for문은 이렇게 하는게 낫다고 하셨음)
    for(int i = 0; i < wallList.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
				// 벽을 세웠다가
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
				// 세운 벽이 타당한가를 보기 위함
                ret = max(ret, solve());
				// 새로운 경우의 수를 테스트하기 위해 다시 0으로 만듦
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}

// ******************************************
// 복습 후, 코테용으로 구현해봄
// // BOJ 14502번: 연구소
// #include <iostream>
// #include <vector>
// #include <cstring> // memset 함수 이용 위함 (배열 초기화)
// using namespace std;
// #define MAX 8
// int N, M, mp[MAX][MAX], visited[MAX][MAX], ret;
// vector<pair<int, int>> virusList, wallList;
// const int dy[4] = {-1, 0, 1, 0};
// const int dx[4] = {0, 1, 0, -1};
// //**********************************************
// // Function: DFS()
// // - DFS 탐색을 통해 바이러스를 인접한 0 영역에 퍼뜨림
// //**********************************************
// void DFS(int y, int x) {
// 	for (int i = 0; i < 4; i++) {
// 		int ny = y + dy[i];
// 		int nx = x + dx[i];
// 		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
// 		if (mp[ny][nx] || visited[ny][nx]) continue;
// 		visited[ny][nx] = 1;
// 		DFS(ny, nx);
// 	}
// }
// //*******************************************
// // Function: solve()
// // - 경우의 수마다 바이러스 전파 + 안전 영역 카운팅 
// //*******************************************
// int solve() {
// 	memset(visited, 0, sizeof(visited));
// 	// 바이러스 위치에 대해 DFS 탐색, 방문 처리
// 	for (pair<int, int> b : virusList) {
// 		if (mp[b.first][b.second] == 2) {
// 			visited[b.first][b.second] = 1;
// 			DFS(b.first, b.second);
// 		}
// 	}
// 	// 안전 영역 카운팅
// 	int cnt = 0;
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < M; j++) {
// 			if (mp[i][j] == 0 && !visited[i][j]) {
// 				cnt++;
// 			}
// 		}
// 	}
// 	return cnt;
// }
// //*********************************************
// // Function: FAST_IO()
// // - c의 stdio와 cpp의 iostream을 동기화를 비활성화
// // - 보다 빠른 입출력 보장
// //*********************************************
// void FAST_IO() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);
// }
// //*********************************************
// // Function: main()
// // - System input, 바이러스 위치, 빈 칸의 위치 저장
// // - 모든 경우의 수 고려하여 3개의 벽을 세우고 초기화
// // - 각 경우마다 안전 영역 카운팅 후, 최댓값 출력
// //*********************************************
// int main() {
// 	FAST_IO();
// 	cin >> N >> M;
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < M; j++) {
// 			cin >> mp[i][j];
// 			if (mp[i][j] == 2) virusList.push_back({i, j});
// 			if (mp[i][j] == 0) wallList.push_back({i, j});
// 		}
// 	}
// 	// 64C3 연산 후 3개의 벽을 세우고 그 상태에서 solve() 함수 처리
// 	// solve() 함수 이후 새로운 경우의 수 적용을 위해 다시 0으로 초기화
// 	// ret: 안전 영역 최댓값 카운팅
// 	for (int i = 0; i < wallList.size(); i++) {
// 		for (int j = 0; j < i; j++) {
// 			for (int k = 0; k < j; k++) {
// 				mp[wallList[i].first][wallList[i].second] = 1;
// 				mp[wallList[j].first][wallList[j].second] = 1;
// 				mp[wallList[k].first][wallList[k].second] = 1;
// 				ret = max(ret, solve());
// 				mp[wallList[i].first][wallList[i].second] = 0;
// 				mp[wallList[j].first][wallList[j].second] = 0;
// 				mp[wallList[k].first][wallList[k].second] = 0;
// 			}
// 		}
// 	}
// 	cout << ret << '\n';
// 	return 0;
// }
// //*************
// //* Test case *
// //*************
// /*********************************************
// #1 input :
// 7 7
// 2 0 0 0 1 1 0
// 0 0 1 0 1 2 0
// 0 1 1 0 1 0 0
// 0 1 0 0 0 0 0
// 0 0 0 0 0 1 1
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0
// #1 Expected output :
// 27
// #1 Real output : 
// 27
// *********************************************/
// /*********************************************
// #2 input :
// 4 6
// 0 0 0 0 0 0
// 1 0 0 0 0 2
// 1 1 1 0 0 2
// 0 0 0 0 0 2
// #2 Expected output :
// 9
// #2 Real output : 
// 9
// *********************************************/
// /*********************************************
// #3 input :
// 8 8
// 2 0 0 0 0 0 0 2
// 2 0 0 0 0 0 0 2
// 2 0 0 0 0 0 0 2
// 2 0 0 0 0 0 0 2
// 2 0 0 0 0 0 0 2
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// #3 Expected output :
// 3
// #3 Real output : 
// 3
// *********************************************/
// /*********************************************
// #4 input :
// 3 3
// 0 0 2
// 1 0 0
// 0 1 0
// #4 Expected output :
// 3
// #4 Real output : 
// 3
// *********************************************/