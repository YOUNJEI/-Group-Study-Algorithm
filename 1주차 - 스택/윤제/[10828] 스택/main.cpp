// 백준 10828 스택
// https://www.acmicpc.net/problem/10828

/*
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

#define _DATA int                 // _DATA template
#define MAX_SIZE 10000

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
        _temp = this->_d[this->cur-1];
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
            return this->_d[this->cur-1];
    }
};

int main(void) {
    // 테스트 케이스 입출력 구현
    int _loopn;
    int n;
    string s;
    Stack _stack;
    vector<int> _vi;

    cin >> _loopn;
    // cin buffer clear
    cin.clear();

    for (int i = 0; i < _loopn; i++) {
        cin >> s;

        if (s == "push") {          // PUSH
            cin >> n;
            _stack.push(n);
        }
        else if (s == "pop") {      // POP
            _vi.push_back(_stack.pop());
        }
        else if (s == "size") {     // SIZE
            _vi.push_back(_stack.size());
        }
        else if (s == "empty") {    // EMPTY
            _vi.push_back(_stack.empty());
        }
        else if (s == "top") {      // TOP
            _vi.push_back(_stack.top());
        }
    }

    for (int i = 0; i < _vi.size(); i++) {
        cout << _vi[i] << endl;
    }

    return 0;
}
