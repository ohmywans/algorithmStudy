// BOJ 16637번: 괄호 추가하기
#include <bits/stdc++.h>
using namespace std;  
vector<int> num; 
vector<char> oper_str; 
int n, ret = -987654321;
string s; 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   
} 
// b와 c의 계산을 위해 a라는 연산 기호 사용
int oper(char a, int b, int c){
    if(a == '+') return b + c; 
    if(a == '-') return b - c; 
    if(a == '*') return b * c;  
    return 0;
} 

void go(int here, int _num){
    // 출력 테스트
    cout << here << " : " << _num << '\n';
    
    // here: num 벡터의 인덱스 인데, 맨 끝 인덱스에 오면
    if(here == num.size() - 1){ 
        ret = max(ret, _num); 
        return;
    }
    // 첫번째 괄호: 이것만 처리하면 괄호가 있는 것처럼 먼저 계산됨
    // _num (+-*/) num[here+1] = 현재 인덱스의 수 (계산) 다음 인덱스의 수
    go(here + 1, oper(oper_str[here], _num, num[here + 1]));
    
    // 두번째 괄호: 맨 끝 인덱스에 도달하기 전,전까지 두번째 괄호 계산
    if(here + 2 <= num.size() - 1){
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]); 
        go(here + 2, oper(oper_str[here], _num, temp));  
    } 
    return;
} 
int main(){
    fastIO();
    cin >> n;  
    cin >> s; 
    for(int i = 0; i < n; i++){
        if(i % 2 == 0)num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);
    } 
    go(0, num[0]);  
    cout << ret << "\n";
    return 0;
} 