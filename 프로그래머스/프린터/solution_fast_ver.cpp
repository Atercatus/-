#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> list;
    vector<int> sorted_list;
    
    for(int i = 0; i < priorities.size(); i++){
        list.push(i);
    }
    
    while(!list.empty()){
        int front = list.front();
        list.pop();
        
        if(priorities[front] != *max_element(priorities.begin(), priorities.end())){
            list.push(front);
        } else{
            priorities[front]=0;
            sorted_list.push_back(front);
        }
    }    
    
    for(int i = 0; i < sorted_list.size(); i++){
        if(sorted_list[i] == location){
            answer = i + 1;
        }
    }
    
    return answer;
}