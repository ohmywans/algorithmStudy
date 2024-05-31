// BOJ 2852번: NBA 농구 - GG (나는 너무 하나하나 접근하려했고, 쓰려는 자료구조가 한정적이었음)
/////////////////////////////////////////
#include<bits/stdc++.h> // prev, 시간 단위 낮추기, 
using namespace std;
#define prev kundol // 라이브러리 때문에 define을 걸어둠
int n, o, A, B, asum, bsum;
string s, prev; 
string print(int a){ 
    string d = "00" + to_string(a / 60); // change to 분
    string e = "00" + to_string(a % 60); // change to 초
	// 뒤에 있는 2개의 문자열만 잘라내겠다.
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}
int changeToInt(string a){
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}
void go(int &sum, string s){ // += 로 누적해서 더함
    sum += (changeToInt(s) - changeToInt(prev)); 
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> o >> s; 			   // 팀(int) >> 시간(string)
        if(A > B) go(asum, s);	   // 1팀 스코어가 높으면 asum에 1팀이 이기고 있던 시간이 저장됨
        else if(B > A)go(bsum, s); // 2팀 스코어가 높으면 bsum에 2팀이 이기고 있던 시간이 저장됨
		o == 1 ? A++ : B++;		   // A: 1팀 스코어, B: 2팀 스코어
        prev = s; 				   // prev: 이전 골 넣은 시간(string)
    }
	// 끝점 처리
    if(A > B) go(asum, "48:00");      // 1팀 스코어가 높으면 asum에 저장
    else if(B > A) go(bsum, "48:00"); // 2팀 스코어가 높으면 bsum에 저장
    cout << print(asum) << "\n"; 
    cout << print(bsum) << "\n";
}