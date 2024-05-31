// BOJ 3197번: 백조의 호수 - GG
// 주난의 난과 같은 풀이로 DFS할 경우, 복잡도 터짐
#include <bits/stdc++.h>
using namespace std;
const int max_n = 1501;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1}; 
int visited_swan[max_n][max_n], visited[max_n][max_n], R, C, day, swanY, swanX, y, x;
char a[max_n][max_n]; 
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
string s;
void Qclear(queue<pair<int, int>> &q){
   queue<pair<int, int>> empty;
   swap(q,empty);
}  
void water_melting() {
    while(waterQ.size()) {
		tie(y, x) = waterQ.front();  
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])continue;
            if(a[ny][nx] == 'X'){
                visited[ny][nx] = 1; 
                water_tempQ.push({ny, nx});
                a[ny][nx] = '.'; 
            } 
        }
    }
}
bool move_swan(){
    // 빙하가 오기 전까지 백조가 계속 나아감. 빙하오면 막힘
    while(swanQ.size()){
		tie(y, x) = swanQ.front(); 
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
            visited_swan[ny][nx] = 1;
            if(a[ny][nx] == '.')swanQ.push({ny, nx}); // 핵심: 물이면 swanQ에 계속 넣고
            else if(a[ny][nx] == 'X') swan_tempQ.push({ny, nx}); // 핵심: 빙하라서 못가면 swanQ.size()가 증가하지 않기 때문에 swan_tempQ에 넣어
            else if(a[ny][nx] == 'L') return true; // 2마리 백조가 만났으면 true
        }
    }
	return false; // 안 만났으면 false
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'L'){swanY = i; swanX = j;} // 하나의 백조 기준이므로 저장
            if(a[i][j] == '.' || a[i][j] == 'L') { // 핵심 코드: 백조가 있는 위치도 물이므로 waterQ에 담고 방문처리 필수
                visited[i][j] = 1;
                waterQ.push({i, j});
            }
        }
    } 
    swanQ.push({swanY, swanX}); 
    visited_swan[swanY][swanX] = 1; 
    while (true) {  
        if(move_swan()) break; // 무한 루프 기저: 또 다른 백조를 만날 경우
        water_melting();
        waterQ = water_tempQ;
        swanQ = swan_tempQ; // 현재 상황에서 갈 수 있는 물은 다 방문한 상태에서 비어 있는 swanQ에 다음 방문할 빙하 영역 swan_tempQ를 넣고, 이를 반복하면 됨
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day << "\n";
    return 0;
}
