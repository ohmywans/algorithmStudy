// BOJ 15686번: 치킨 배달 - GG
/*
실패 요인
- 매 케이스마다 변동되는 c의 개수에 따라 치킨집의 위치를 순서 상관없이 담아야하는데 
 해당 개수만큼의 위치를 뽑는 로직을 모르겠음
- 2의 개수를 담아서 또 4방향 탐색하면서 1을 발견할때 거리 계산하는 로직 구현 시 함수가 또 필요한가? 싶었음 - go2()
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m, a[54][54], result = 987654321;
vector<vector<int>>chickenList;
vector<pair<int, int>> _home, chicken;

void combi(int start, vector<int> v){
    if(v.size() == m){
        chickenList.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1)_home.push_back({i, j});
            if(a[i][j] == 2)chicken.push_back({i, j});
        }
    }
    vector<int> v;
    combi(-1, v);
    for(vector<int> cList : chickenList){
        int ret = 0;
        for(pair<int, int> home : _home){
            int _min = 987654321;
            for(int ch : cList){
                int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                _min = min(_min, _dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }
    cout << result << "\n";
    return 0;
}
