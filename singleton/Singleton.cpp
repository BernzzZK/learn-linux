#include <iostream>
#include <mutex>
using namespace std;

// //Eager Initialization(饿汉模式)
// class singletonEI {
// public:
//     static singletonEI& getInstance() {
//         return instance;
//     }

//     singletonEI(const singletonEI&) = delete;
//     singletonEI& operator=(const singletonEI&) = delete;

//     void hello() {
//         cout << "hello, you just create an instance" << endl;
//     }

// private:
//     singletonEI() = default;
//     static singletonEI instance;
// };

// singletonEI singletonEI::instance;

// //Lazy Initialization(懒汉模式)
// class singletonLI {
// public:
//     static singletonLI& getInstance() {
//         static singletonLI instance;
//         return instance;
//     }

//     singletonLI(const singletonLI&) = delete;
//     singletonLI& operator=(const singletonLI&) = delete;

//     void hello() {
//         cout << "hello, this is an another way to create an instance" << endl;
//     }
    
// private:
//     singletonLI() = default;
// };

//Lazy Initialization(懒汉模式 using mutex)
class singletonLI {
public:
    static singletonLI* getInstance() {
        if(instance == nullptr){
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr)
                instance = new singletonLI();
        }
        return instance;
    }

    singletonLI(const singletonLI&) = delete;
    singletonLI& operator=(const singletonLI&) = delete;

    void hello() {
        cout << "hello, this is an another way to create an instance which used mutex" << endl;
    }
    
private:
    singletonLI() = default;
    static singletonLI* instance;
    static mutex mtx; 
};
singletonLI* singletonLI::instance = nullptr;
mutex singletonLI::mtx;

int main() {
    singletonLI::getInstance()->hello();
    return 0;
}