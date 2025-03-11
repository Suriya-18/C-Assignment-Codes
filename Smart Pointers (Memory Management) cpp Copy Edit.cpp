#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    Test() { cout << "Constructor Called\n"; }
    ~Test() { cout << "Destructor Called\n"; }
    void show() { cout << "Test Show Function\n"; }
};

int main() {
    {
        unique_ptr<Test> ptr1 = make_unique<Test>();
        ptr1->show();
    } // ptr1 is destroyed automatically here

    shared_ptr<Test> ptr2, ptr3;
    {
        shared_ptr<Test> ptr4 = make_shared<Test>();
        ptr2 = ptr4;
        ptr3 = ptr4;
        cout << "Shared Count: " << ptr4.use_count() << endl;
    } // ptr4 goes out of scope, but ptr2 and ptr3 still hold references

    cout << "Shared Count After Scope: " << ptr2.use_count() << endl;
    return 0;
}
