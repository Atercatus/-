#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arr) {
    int answer = 0;
    int cnt = 0;
    stack<char> s;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == '('){
            s.push('(');
        } else { // arr[i] == ')'
            s.pop();
           if(arr[i-1] == '(') {// 레이저
               answer += s.size();
            } else {
                answer++;
            }
        }
    }
    
    return answer;
}