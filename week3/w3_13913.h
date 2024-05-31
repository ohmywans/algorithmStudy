// BOJ 13913��: ���ٲ��� 4 with ��ư
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
// ������ �Լ� �߰�
void traceBack(int node) {
    if(node == s) { // �������� �����ϸ� ret�� �߰��ϰ� ��ȯ
        ret.push_back(node);
        return;
    }
    traceBack(from[node]); // ���� ����� ���� ���� ������
    ret.push_back(node); // ������ �� ���� ��带 ret�� �߰�
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
                    from[next] = now; // ���� ��尡 ��𿡼� �Դ��� ���
                    cnt[next] += cnt[now];
                } else if (visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[d] - 1 << '\n';
    traceBack(d); // d���� ������ ����

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    } cout << '\n';
    return 0;
}
// BOJ 13913��: ���ٲ��� 4 - GG
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

// // pair ��� 3���� Ž�� �����ϱ�
// #include <utility>
// pair<int, int> d[] = { {1, 1}, {1, -1}, {2, 0} };
// for (int i = 0; i < 3; i++) {
//     int nx = here * d[i].first + d[i].second;
// } // �̷��Ե� here + 1, here - 1, here * 2 ǥ�� ����
