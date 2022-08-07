#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    int cnt = -1;
    for (int i = 0;i < dartResult.length();i++) {
        if (isdigit(dartResult[i])) {
            cnt++;
            if (isdigit(dartResult[i + 1])) {
                i++;
                score.push_back(10);
                continue;
            }
            else {
                score.push_back(dartResult[i] - '0');
                continue;
            }
        }
        if (dartResult[i] == 'S') {
            continue;
        }
        else if (dartResult[i] == 'D') {
            score[cnt] = pow(score[cnt], 2);
        }
        else if (dartResult[i] == 'T') {
            score[cnt] = pow(score[cnt], 3);
        }

        if (dartResult[i] == '*') {
            score[cnt] = score[cnt] * 2;
            if (cnt != 0) {
                score[cnt - 1] = score[cnt - 1] * 2;
            }
        }
        else if (dartResult[i] == '#') {
            score[cnt] = score[cnt] * -1;
        }
    }
    for (int i = 0;i < score.size();i++) {
        answer += score[i];
    }
    return answer;
}