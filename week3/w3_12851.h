// BOJ 12851번: 숨바꼭질 2 - GG, 정답 코드 처음부터 끝까지 거를 타선 X
// 기존 BFS와 달리 3방향 탐색 + 좌표가 아닌 단일 인덱스 기반 이동
#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000; // 10만보다 더 해야하는 이유: 10만보다 넘어서 갔다가 다시 돌아오는 경우가 더 빠를 수 있어서
int visited[MAX+4];
long long cnt[MAX+4];
int main() {
    int n, m;
    cin >> n >> m;
    // <반례>: "수빈 = 동생"이면, 0초에 1가지임을 출력
    if(n == m){
        puts("0"); puts("1"); // #include <stdio.h> ()안의 문자열을 출력하고, \n을 함께 출력하는 함수
        return 0; 
    } 
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        // 각각의 계산값이 next가 됨
        for (int next : {now-1, now+1, now*2}) {
            // 범위 내에 있으면
            if (0 <= next && next <= MAX) { 
                if (!visited[next]) {
                    q.push(next); 
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now]; // 0으로 초기화된 원소가 초기값 1부터 누적해서 더하면 최종적으로 경우의 수를 나타내게 됨
                } else if (visited[next] == visited[now] + 1) { // 설명 참조
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[m] - 1 << '\n';
    cout << cnt[m] << '\n';
    return 0;
}