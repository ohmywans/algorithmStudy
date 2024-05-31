/* BOJ 2583번: 영역 구하기 - 도식화해서 회전시켜 원래 알고 있던 좌표 모양대로 품
- 또, 주어진 좌표를 '<=' 보다는 '<' 로 lx, ly, rx, ry 범위 적용함 (코드 보면 알거야) */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result;
int M, N, K, lx, ly, rx, ry, ret, cnt, a[104][104], visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

// DFS 알고리즘
void dfs(int y, int x) {
	visited[y][x] = 1;		// 현재 위치 방문 도장 찍기
	cnt += a[y][x];			// 면적 구하기: cnt에 값이 1인 면 누적해서 더함
	
	// 4방향 이동
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; // ny = next_y
		int nx = x + dx[i]; // nx = next_x
		if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue; // underflow, overflow 방지
		if (a[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> K;
	// 전체 영역 원소는 1로 초기화
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = 1;
		}
	}
	// 반복횟수: 직사각형 개수, 해당되는 영역 값: 0으로 초기화
	for (int i = 0; i < K; i++) {
		cin >> lx >> ly >> rx >> ry;
		for (int j = ly; j < ry; j++) {
			for (int k = lx; k < rx; k++) {
				a[j][k] = 0;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] && visited[i][j] == 0) {
				cnt = 0;				// 새로운 분리된 영역 올 때마다 cnt 초기화
				dfs(i, j);				// DFS 알고리즘 수행
				ret++;					// 분리된 영역의 수 ret
				result.push_back(cnt);	// 리턴된 cnt 값을 vector에 삽입
			}
		}
	}
	sort(result.begin(), result.end());	// 오름차순 정렬 후 출력
	cout << ret << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	} cout << '\n';
		
	return 0;
}

/*
내 코드와 다른 점: 나는 직사각형이 아닌 영역은 1로 초기화하고 직사각형은 0으로 정의
정답코드는 반대로 하심. 그리고 1이면 탐색 못하게 했고, dfs 함수 자체를 int로 리턴하여
해당 값을 영역 면적으로 계산되도록 하심.

#include<bits/stdc++.h> 
using namespace std;  
#define y1 aaaa // <bits/stdc++.h> 라이브러리에 누군가 y1 변수명을 못 쓰게해서 이렇게 임의로 정의해줘야 사용 가능
int a[104][104], m, n, k, x1, x2, y1, y2, visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<int> ret; 
int dfs(int y, int x){ // 다양한 형태로 출력하는 함수를 만드는 연습 필요
    visited[y][x] = 1; 
    int ret = 1; 
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1) continue; 
		if(a[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    } 
	cout << y << " : " << x << ret << '\n'; // 디버깅
    return ret; 
}
int main() { 
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k; 
    for(int i = 0; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;  
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                a[y][x] = 1; 
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != 1 & visited[i][j] == 0) { 
                ret.push_back(dfs(i, j));
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for(int a : ret) cout << a << " "; 
    return 0; 
}
*/