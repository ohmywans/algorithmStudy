/* BOJ 2468번: 안전 영역 - '노트' 내용이 결정적이었음
노트: 아무 지역도 물에 잠기지 않을 수도 있다.
min_h, max_h 값이 같을 경우 안전 영역은 1개가 되어야함. 
이를 추가적으로 처리해주니 정답이 되었다. 
- 스승님의 정답코드가 로직상 더 깔끔하다! */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer;
int N, max_h, min_h, height, a[104][104], visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

// DFS 알고리즘
void dfs(int y, int x) {
	// 현재 위치 방문 도장 찍기
	visited[y][x] = 1;
	
	// 4방향 이동
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; // ny = next_y
		int nx = x + dx[i]; // nx = next_x
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // underflow, overflow 방지
		if (a[ny][nx] <= height) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	max_h = 0; min_h = 100;
	// 높이 행렬 입력 받고 최대 높이, 최소 높이 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (max_h < a[i][j]) max_h = a[i][j];
			else if (min_h > a[i][j]) min_h = a[i][j];
		}
	}
	// 예외 처리: 만약 최소 높이와 최대 높이가 같을 경우 안전 영역은 1개
	if (min_h == max_h) {
		cout << 1 << '\n';
		exit(0);
	}
	// 최소~최대 높이로 가면서 모두 DFS로 안전 영역 개수 ret 세기
	for (int k = min_h; k <= max_h; k++) {
		int ret = 0;
		
		// visited 행렬 초기화
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		
		height = k;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (a[i][j] > k && visited[i][j] == 0) {
					dfs(i, j);
					ret++;
				}
			}
		}
		answer.push_back(ret);
	}
	int result = *max_element(answer.begin(), answer.end());
	cout << result << '\n';
		
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;   
int a[101][101], e[101][101], visited[101][101], n, temp, ret = 1;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
void dfs(int y, int x, int d){
    visited[y][x] = 1; 
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue; 
        if(!visited[ny][nx] && a[ny][nx] > d) dfs(ny, nx, d);
    }
    return;
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int d = 1; d < 101; d++){
		// fill()로 visited 초기화
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); 
        int cnt = 0;  
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > d && !visited[i][j]) {
                    dfs(i, j, d); // 나처럼 d를 전역변수로 두고 해도 되지만 명시적으로 이해하기 편한건 이 방식!
                    cnt++;
                }
            }
        }
		// 어차피 경우의 수가 최대인 값만 필요하므로 두 수 간 비교로 ret에 저장
        ret = max(ret, cnt);
    }
    cout << ret << '\n';
    return 0; 
}


*/