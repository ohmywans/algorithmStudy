// BOJ 16234번: 인구 이동 - sum, vector v가 핵심
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <math.h>
using namespace std;

int visited[54][54], a[54][54], n, l, r, sum, cnt; 
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1}; 
vector<pair<int,int>> v;

void dfs(int y, int x, vector<pair<int,int>> &v){ 
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || visited[ny][nx])continue;
		// 이전 위치, 현재 위치 간 인구 수 차이가 범위를 충족하는지
        if(abs(a[ny][nx]- a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){ 
            visited[ny][nx] =1;
            v.push_back({ny,nx}); // 범위를 만족하는 위치를 v에 담고
            sum += a[ny][nx];	  // 그 위치의 값을 누적해서 합함
            dfs(ny,nx,v);
        }
    }
	return;
}

int main() { 
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    while (true) {
        bool flag = 0;	// 인구 이동이 일어났는지 여부
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    dfs(i,j,v);
                    if(v.size() == 1) continue;  // 인구 이동 필요X
					// 인구 이동
                    for(pair<int,int> b : v){ 
                        a[b.first][b.second] = sum / v.size();
                        flag = 1; // 인구 이동 발생(1)
                    }
                } 
            }
        }
        if(!flag) break;  // 인구 이동이 필요 없으면 종료
        cnt++;
    } 
    cout<< cnt << "\n";
    return 0;
}
