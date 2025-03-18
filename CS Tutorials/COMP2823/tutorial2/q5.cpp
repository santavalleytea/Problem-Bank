#include <iostream>
#include <stack>

using namespace std;

class QueueWithStacks {
private:
    stack<int> st1;
    stack<int> st2;

public:
    void enqueue (int val) {
        st1.push(val);
    }

    void dequeue () {
        if (st2.empty()) {
            if (st1.empty()) {
                cout << "Queue empty, cannot dequeue\n";
                return;
            }

            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        st2.pop();
    }

    int front() {
        if (st2.empty()) {
            if (st1.empty()) {
                cout << "Queue empty, no front element\n";
                return -1;
            }

            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool isEmpty() {
        return st1.empty() && st2.empty();
    }
};


int main() {
    QueueWithStacks q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << endl; // Should print 1
    q.dequeue();

    cout << "Front: " << q.front() << endl; // Should print 2
    q.dequeue();

    cout << "Front: " << q.front() << endl; // Should print 3
    q.dequeue();

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}