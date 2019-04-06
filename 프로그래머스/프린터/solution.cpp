#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    stack<int> ordered_list;
    queue<int> priorities_queue;

    for(int i = 0; i < priorities.size(); i++){
        priorities_queue.push(i);
    }

    while(!priorities_queue.empty()){
        int front = priorities_queue.front();
        priorities_queue.pop();

        vector<int> tmp;

        while(!ordered_list.empty() && priorities[ordered_list.top()] < priorities[front]){
            // 맨 뒤로 보낼 것들
            // priorities_queue.push(ordered_list.front());
            tmp.push_back(ordered_list.top());
            ordered_list.pop();
        }

        // 남은 대기열을 기존 대기열 뒤에 붙인다.
        for(int i =tmp.size()-1; i >= 0; i--){
            priorities_queue.push(tmp[i]);
        }

        ordered_list.push(front);
    }

    cout << ordered_list.size() << endl;
    // location 이 가리키는 문자를 찾는다.
    while(ordered_list.top() != location){
        cout << ordered_list.top() << " ";
        ordered_list.pop();
    }

    return answer = ordered_list.size();
}

