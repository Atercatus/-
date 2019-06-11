#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0, div = 0; i < progresses.size(); i++){
        div  = 100 - progresses[i];
        if(div % speeds[i] > 0){
            div = (div / speeds[i]) + 1;
        } else{
            div = (div / speeds[i]);
        }
        q.push(div);
    }
    
    int cur;
    int ret_tmp;
    while(!q.empty()){
        cur = q.front();
        ret_tmp = 0;

        while(cur >= q.front() && !q.empty()){
            q.pop();
            ret_tmp++;
        }
        answer.push_back(ret_tmp);
        ret_tmp = 0;
    }
    
    return answer;
}