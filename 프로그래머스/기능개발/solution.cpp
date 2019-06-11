#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cur_pos = 0;
    int ret_tmp = 0;
    int cur_day = 1;

    // 반복문을 돌며 현재 위치의 progresses 원소가 100이 넘을려면 몇일이 지나야하는지 체크
    while(cur_pos < progresses.size()){
        progresses[cur_pos] += speeds[cur_pos] * cur_day;

        if(progresses[cur_pos] >= 100){
            ret_tmp++;
            cur_pos++;
            cout << "ret_tmp: " << ret_tmp << endl;
        } 
        else{
            if(ret_tmp > 0){
                answer.push_back(ret_tmp);
                ret_tmp = 0;
            }

            // 100을 넘기기 위해서 얼마나 많은 날이 지나야하는지 체크
            int sub = (100 - progresses[cur_pos]);
            int div = sub / speeds[cur_pos];
            if((sub % speeds[cur_pos]) > 0){
                div++;
            }
            cout << cur_day << endl;
            cur_day += div;
            cout << cur_day << endl;

        }
    }
    answer.push_back(ret_tmp);

    return answer;
}