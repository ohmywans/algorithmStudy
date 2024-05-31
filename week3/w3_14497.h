// BOJ 14497번: 주난의 난(難) - 정답 이지만, 시간 복잡도 고려해서 효율화가 필요했음
// 내 코드 시간 복잡도: O(NM^2)
// 스승님 시간 복잡도: O(N*M) - win
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define MAX 304

using namespace std;

int N, M, x_1, y_1, x_2, y_2, a[MAX][MAX], visited[MAX][MAX], y, x, ret = 1;
string input;
bool ok;
vector<pair<int, int>> f;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void FAST_IO() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    return;
}
void DFS(int y, int x) {
    visited[y][x] = 1;
    if (a[y][x] == 1) {
        f.push_back({y, x});
        return;
    }
    for (int i = 0; i < 4; i++) {
        int sy = y + dy[i];
        int sx = x + dx[i];
        if (sy < 0 || sy >= N || sx < 0 || sx >= M) continue;
        if (visited[sy][sx]) continue;
        visited[sy][sx] = 1;
        DFS(sy, sx);
    }
    return;
}

int main() {
    FAST_IO();
    cin >> N >> M;
    cin >> y_1 >> x_1 >> y_2 >> x_2;
    y_1 -= 1; x_1 -= 1; y_2 -= 1; x_2 -= 1;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            if (input[j] == '0' || input[j] == '*') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    while (1) {
        fill(&visited[0][0], &visited[0][0]+MAX*MAX, 0);
        fill(f.begin(), f.end(), pair<int,int> (0, 0)); // AI추천: f.clear();
        DFS(y_1, x_1);
        for (pair<int, int> b : f) {
            a[b.first][b.second] = 0;
            if (b.first == y_2 && b.second == x_2) {
                ok = true; break;
            }
        }
        if (ok) break;
        ret++;
    }
    cout << ret << '\n';
    return 0;
}
/*
// 스승님 코드 - 2개의 큐 + BFS
#include <stdio.h>
#include<algorithm>
#include<queue>
using namespace std; 
char a[301][301];
int n, m, x1, y1, x2, y2; 
typedef pair<int, int> pii;
int visited[301][301];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int ret; 
queue<int> q;
int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    y1--, x1--, y2--, x2--; 
    for(int i = 0; i < n; i++){
        scanf("%s", a[i]); 
    }  
    q.push(1000 * y1 + x1);
    visited[y1][x1] = 1; 
    int cnt = 0; 
    while(a[y2][x2] != '0'){ 
        cnt++;
        queue<int> temp; 
        while(q.size()){
            int y = q.front() / 1000; 
            int x = q.front() % 1000;  
            q.pop();  
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i]; 
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue; 
                visited[ny][nx] = cnt;  
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0'; 
                    temp.push(1000 * ny + nx);
                }
                else q.push(1000 * ny + nx); 
            }
        }
        q = temp;  
    }
    printf("%d\n", visited[y2][x2]); 
}
*/