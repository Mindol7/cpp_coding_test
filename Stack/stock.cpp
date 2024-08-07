#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> stack;
    
    for(int i = 0; i<prices.size(); ++i){
        if(i == 0){
            stack.push(i);
            continue;
        }

        while((!stack.empty()) && prices[i] < prices[stack.top()]){
            answer[stack.top()] = i - stack.top();
            stack.pop();    
        }
        stack.push(i);
    }
    
    while(!stack.empty()){
        answer[stack.top()] = prices.size() - stack.top() - 1;
        stack.pop();
    }
    return answer;
}

int main(){
    vector<int> v1 = solution({1,6,9,5,2});

    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}