// 백준 10773 스택
// https://www.acmicpc.net/problem/10773

/*
나코더 기장 재민이는 동아리 회식을 준비하기 위해서 장부를 관리하는 중이다.
재현이는 재민이를 도와서 돈을 관리하는 중인데, 애석하게도 항상 정신없는 재현이는 돈을 실수로 잘못 부르는 사고를 치기 일쑤였다.
재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지우게 시킨다.
재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다. 재민이를 도와주자!
첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)
이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며, 정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

#define _DATA int
#define MAX_SIZE 100001     // K개의 정수 100,000 +1

// Stack 클래스 구현 (배열 기반)
class Stack {
private:
    _DATA _d[MAX_SIZE];
    int cur;

public:
    // Stack의 생성자 (cur 0으로 초기화)
    Stack() { this->cur = 0; }

    // PUSH 구현
    void push(_DATA n) {
        if (cur < MAX_SIZE - 1)
            this->_d[this->cur++] = n;
    }

    // POP 구현
    _DATA pop(void) {
        if (empty())
            return -1;
        _DATA _temp;
        _temp = this->_d[this->cur - 1];
        this->cur--;
        return _temp;
    }

    // SIZE 구현
    int size(void) {
        return this->cur;
    }

    // EMPTY 구현
    bool empty(void) {
        if (this->cur == 0)
            return true;
        else
            return false;
    }

    // TOP 구현
    _DATA top(void) {
        if (empty())
            return -1;
        else
            return this->_d[this->cur - 1];
    }
};

int main(void) {
    // 테스트 케이스 입출력 구현
    int _loopn;
    int _input;
    int sum = 0;
    vector<int> _vi;
    Stack _stack;
    _vi.clear();
    
    // _loopn 입력횟수
    cin >> _loopn;
    // cin buffer clear
    cin.clear();

    for (int i = 0; i < _loopn; i++) {  // _loopn만큼 명령처리
        cin >> _input;    // _input에 입력
        
        switch (_input) {
        // 입력으로 0이 들어오면 스택의 마지막 자료 제거
        case 0:
            _stack.pop();
            break;
            
        // 0 이외 숫자는 스택에 저장
        default:
            _stack.push(_input);
            break;
        }
    }

    while (!(_stack.empty())) {
        // 스택이 empty 일때까지 sum에 합산
        sum += _stack.pop();
    }

    cout << sum;
    return 0;
}
