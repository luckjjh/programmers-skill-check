#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    vector<bool> tempV;
    for (int i = 0;i < 3;i++) {
        tempV.push_back(true);
    }
    for (int i = 0;i < nums.size() - 3;i++) {
        tempV.push_back(false);
    }

    sort(tempV.begin(), tempV.end());

    do {
        int curSum = 0;
        for (int i = 0;i < tempV.size();i++) {
            if (tempV[i] == true) {
                curSum += nums[i];
            }
        }
        bool check = true;
        cout << curSum << endl;
        for (int i = 2;i < (curSum / 2 + 1);i++) {
            if (curSum % i == 0) {
                check = false;
                break;
            }
        }
        if (check) {
            answer++;
        }
    } while (next_permutation(tempV.begin(), tempV.end()));


    return answer;
}