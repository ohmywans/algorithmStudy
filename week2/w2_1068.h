// BOJ 1068번: 트리 - (문제 이해 어려웠음): 내 생각엔, 입력으로 주어진 값의 크기에 따라 작을수록 부모 노드가 되는 듯. 
// -1인 자리는 무조건 루트가 되고, 트리를 만들면 인덱스로 표현해서 input을 만들 수 있는 듯
#include<bits/stdc++.h>
using namespace std;
int n, r, temp, root;
vector<int> adj[54];
int dfs(int here){
    int ret = 0;					 // ret  : 리프노드의 수
    int child = 0;					 // child: 자식노드의 수
    for(int there : adj[here]){		 // there는 here 노드에 연결된 index가 됨
        if(there == r) continue;	 // 만약 there가 삭제한다는 노드 r이면 패스
        ret += dfs(there);			 // 연결된 index에 대해 리턴된 값을 누적해서 더함
        child++;					 // 자식노드 1 추가 
    }
    if(child == 0) return 1; 		 // 자식노드 없으면 현재 자신 노드에 대한 1 리턴 (일종의 visited[])
    return ret;						 // ret 값 리턴
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1)root = i;		 // temp가 -1이면 그 index는 루트가 됨
        else adj[temp].push_back(i); // temp 값에 해당 index가 연결되어 들어감
    }
    cin >> r;
    if(r == root){					 // 지우는 index인 r이 루트이면 0개 출력, 종료
        cout << 0 << "\n";return 0;
    }
    cout << dfs(root) << "\n";		 // 탐색은 무조건 루트 먼저니까 루트 넣고 dfs를 int로 리턴받음
    return 0;
}