// BOJ 2636번: 치즈
#include <bits/stdc++.h>
using namespace std; 
int a[104][104], visited[104][104];
int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};   
int n, m, cnt, cnt2;
vector <pair<int,int>> v;
void go(int y,int x){
    visited[y][x] = 1;		// 1. 무조건 방문을 먼저 찍고
    if(a[y][x] == 1){		// 방문한 곳의 값이 치즈(1)이면 치즈 담는 벡터에 위치 담기
        v.push_back({y,x}); // 2. vector에 넣은 뒤
        return;				// 3. 리턴을 하기 때문에 더 안 쪽에 있는 치즈(1)로 닿지 않는 것!
    }
    for(int i=0; i<4; i++){	// ny,nx 방문 + 방문했으면 패스
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0|| ny>=n||nx<0||nx>=m||visited[ny][nx])continue; // a[ny][nx]가 1이면 v에 담기 위해 pass 조건에서 뺌
        go(ny,nx);
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
    while(true){ 
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0); // 방문 배열 필요
        v.clear(); 											 // 녹아야할 치즈(1)을 담는 곳 v
        go(0,0); 											 // 시작 위치
        cnt2 = v.size();									 // 치즈가 녹기 전의 시간
        for(pair<int, int> b : v){ 							 // go로부터 완성한 v에 대해 치즈를 녹이는(0) 곳
            a[b.first][b.second] = 0;
        }   
        bool flag = 0;										 // 치즈가 녹아있는지 체크
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != 0) flag = 1;					 // 치즈가 아직 다 안 녹았으면 flag = 1
            }
        }
        cnt++;												 // 치즈가 녹은 후의 시간++
        if(!flag) break;									 // 치즈가 다 녹아서 flag = 0이면 break
    }
    cout << cnt << '\n' << cnt2 << '\n'; 
}
