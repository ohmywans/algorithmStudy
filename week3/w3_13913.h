// BOJ 13913번: 숨바꼭질 4 with 뤼튼
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 200000
using namespace std; 
int here, s, d, visited[MAX+4], from[MAX+4];
long long cnt[MAX+4];
vector<int> ret;
void FAST_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 역추적 함수 추가
void traceBack(int node) {
    if(node == s) { // 시작점에 도달하면 ret에 추가하고 반환
        ret.push_back(node);
        return;
    }
    traceBack(from[node]); // 현재 노드의 이전 노드로 역추적
    ret.push_back(node); // 역추적 중 현재 노드를 ret에 추가
}
int main() {
    FAST_IO();
    cin >> s >> d;
    if (s == d) {
        cout << 0 << '\n';
        cout << d << '\n';
        exit(0);
    }
    visited[s] = 1;
    cnt[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int now = q.front(); q.pop();
        for (int next : {now+1, now-1, now*2}) {
            if (next >= 0 && next <= MAX) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    from[next] = now; // 현재 노드가 어디에서 왔는지 기록
                    cnt[next] += cnt[now];
                } else if (visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[d] - 1 << '\n';
    traceBack(d); // d부터 역추적 시작

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    } cout << '\n';
    return 0;
}
// BOJ 13913번: 숨바꼭질 4 - GG
#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
const int max_n = 200004;
int visited[max_n], prev[max_n], n, k, ret, here, cnt, next;   
vector<int> v; 
queue<int> q;  
int main() { 
    cin >> n >> k; 
    visited[n] = 1; 
    q.push(n);  
    while(q.size()){
        here = q.front();  
        q.pop();
        if(here == k){
            ret = visited[k]; 
            break;
        }
		for(int next : {here + 1, here - 1, here * 2}){
            if(next >= max_n || next < 0 || visited[next]) continue;  
            visited[next] = visited[here] + 1; 
            prev[next] = here; 
            q.push(next); 
		} 
    }   
    for(int i = k; i != n; i = prev[i]){
        v.push_back(i);
    }
    v.push_back(n);
    cout << ret - 1<< '\n'; 
    reverse(v.begin(), v.end());
	for(int i : v) cout << i << ' '; 
    return 0;
}

// // pair 기반 3방향 탐색 구현하기
// #include <utility>
// pair<int, int> d[] = { {1, 1}, {1, -1}, {2, 0} };
// for (int i = 0; i < 3; i++) {
//     int nx = here * d[i].first + d[i].second;
// } // 이렇게도 here + 1, here - 1, here * 2 표현 가능
