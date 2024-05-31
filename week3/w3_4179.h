// BOJ 4179번: 불! - 주어진 테케는 통과했는데 내가 만든 테케는 실패..
// 지훈이가 더 빨라야돼: '불의 최단거리 > 지훈이의 최단거리' 이어야 돼.
// 반례(*): 불이 없는 경우, 불이 전부 0이라서 최단거리도 0이 나오게 됨
// 코테에서 대부분 쉬운 1,2번을 제외하고 3번부터 이런 반례가 꼭 숨어있으니 찾는 습관 들이기 중요해!
#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
const int INF = 987654321; // INF는 최댓값으로 설정
char a[1004][1004];
int n, m, sx, sy, ret, y, x;
const int dy[4]={0,-1,0,1};
const int dx[4]={-1,0,1,0};
int fire_check[1004][1004], person_check[1004][1004];

bool in(int a,int b){	// // underflow, overflow 체크 똑같음
	return 0 <= a && a < n && 0 <= b && b < m;
} 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	queue<pair<int, int>> q;
    cin >> n >> m;  
	// 불에 대한 반례를 해결하기 위해 INF(최댓값)로 초기화
	memset(fire_check, INF, sizeof(fire_check));
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'F'){		  // 불 위치: 여러 개 등장할 수 있음! (퍼지니까)
                fire_check[i][j] = 1; q.push({i, j});
            }else if(a[i][j] == 'J'){ // 지훈이 위치: 1개라서 하나만 저장
                sy = i; sx = j; 
            }
        }
    } 
	// 불의 이동
	while(q.size()){
        tie(y, x) = q.front(); 
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(!in(ny,nx)) continue;	// underflow, overflow 체크 똑같음
			// (*) 불의 위치가 찍힌 곳 값이 초기화했던 초기값 INF가 아니거나, 벽이면 안돼
			if(fire_check[ny][nx] != INF || a[ny][nx]=='#') continue;
			fire_check[ny][nx] = fire_check[y][x] + 1;	// 여기 += 아니다!
			q.push({ny, nx});
		}
	}
	// 지훈이의 이동
	person_check[sy][sx]=1;
	q.push({sy,sx});
	while(q.size()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop(); 
		// 가장자리 왔는지 체크하는 방법! 간단하네..
		if(x == m - 1 || y == n - 1 || x == 0 || y == 0){
            ret = person_check[y][x];
            break;
		}
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 언더, 오버 플로우 안돼
			if(!in(ny,nx)) continue;
			// 방문했거나, 벽이면 안돼
			if(person_check[ny][nx] || a[ny][nx]=='#') continue; 
			// (*) 불이 더 빠르거나 같으면 안돼
			if(fire_check[ny][nx] <= person_check[y][x] + 1) continue;
			// 다 걷어내고 나서야 지훈이는 갈 수 있어
            person_check[ny][nx] = person_check[y][x] + 1;	// 여기 += 아니다!
            q.push({ny, nx});
		}
	} 
    if(ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";
	return 0;
}
/* 반례: 불이 없는 경우
3 3
...
.J.
... 
*/