// BOJ 3197��: ������ ȣ�� - GG
// �ֳ��� ���� ���� Ǯ�̷� DFS�� ���, ���⵵ ����
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
    // ���ϰ� ���� ������ ������ ��� ���ư�. ���Ͽ��� ����
    while(swanQ.size()){
		tie(y, x) = swanQ.front(); 
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
            visited_swan[ny][nx] = 1;
            if(a[ny][nx] == '.')swanQ.push({ny, nx}); // �ٽ�: ���̸� swanQ�� ��� �ְ�
            else if(a[ny][nx] == 'X') swan_tempQ.push({ny, nx}); // �ٽ�: ���϶� ������ swanQ.size()�� �������� �ʱ� ������ swan_tempQ�� �־�
            else if(a[ny][nx] == 'L') return true; // 2���� ������ �������� true
        }
    }
	return false; // �� �������� false
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
            if(a[i][j] == 'L'){swanY = i; swanX = j;} // �ϳ��� ���� �����̹Ƿ� ����
            if(a[i][j] == '.' || a[i][j] == 'L') { // �ٽ� �ڵ�: ������ �ִ� ��ġ�� ���̹Ƿ� waterQ�� ��� �湮ó�� �ʼ�
                visited[i][j] = 1;
                waterQ.push({i, j});
            }
        }
    } 
    swanQ.push({swanY, swanX}); 
    visited_swan[swanY][swanX] = 1; 
    while (true) {  
        if(move_swan()) break; // ���� ���� ����: �� �ٸ� ������ ���� ���
        water_melting();
        waterQ = water_tempQ;
        swanQ = swan_tempQ; // ���� ��Ȳ���� �� �� �ִ� ���� �� �湮�� ���¿��� ��� �ִ� swanQ�� ���� �湮�� ���� ���� swan_tempQ�� �ְ�, �̸� �ݺ��ϸ� ��
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day << "\n";
    return 0;
}
