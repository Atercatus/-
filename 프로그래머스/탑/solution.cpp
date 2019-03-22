#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    stack<int> s;
    
    for(int i = heights.size() - 1; i >= 0; i--){
        while(!s.empty() && heights[s.top()] < heights[i]){
            answer[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        answer[s.top()] = 0;
        s.pop();
    }
    
    return answer;
}