#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <condition_variable>

using namespace std;
std::mutex mtx;
std::condition_variable cv;
int zero_state;
int print_no;
std::vector<int> numbers;
bool done;

void printNumberx(int x){
  printf("%d:",x);
}
//class ZeroEvenOdd {
//private:
//    int n;
//
//
//public:
//    ZeroEvenOdd(int n) {
//        this->n = n;
//        print_no=1;
//        zero_state=0;
//    }
//
//    // printNumber(x) outputs "x", where x is an integer.
//    void zero(function<void(int)> printNumber) {
//        while (print_no<=n) {
//            std::unique_lock<std::mutex> lck(mtx);
//            while (zero_state != 0 && print_no<=n)
//              cv.wait(lck);
//            if(print_no>n)
//              break;
//            printNumber(0);
//            zero_state = 1;
//            cv.notify_all();
//            while (zero_state != 0)
//              cv.wait(lck);
//
//            if(!done)
//              printNumber(0);
//
//            zero_state = 2;
//            cv.notify_all();
//            while (zero_state != 0 && print_no<=n)
//              cv.wait(lck);
//      }
//    }
//
//    void even(function<void(int)> printNumber) {
//        while (print_no<=n) {
//        std::unique_lock<std::mutex> lck(mtx);
//        while (zero_state != 2 && print_no<=n && !done)
//          cv.wait(lck);
//        if(print_no>n)
//          break;
//        if(!done)
//            printNumber(print_no);
//        if(print_no==n)
//          done= true;
//        zero_state = 0;
//        print_no++;
//        cv.notify_all();
//      }
//    }
//
//    void odd(function<void(int)> printNumber) {
//        while (print_no<=n) {
//        std::unique_lock<std::mutex> lck(mtx);
//        while (zero_state != 1 && print_no<=n && !done)
//          cv.wait(lck);
//        if(print_no>n)
//          break;
//        if(!done)
//            printNumber(print_no);
//        if(print_no==n)
//          done= true;
//        zero_state = 0;
//        print_no++;
//        cv.notify_all();
//      }
//    }
//};

class ZeroEvenOdd {
private:
    int n;
    mutex z_0,z_1,z_2;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        print_no=0;
        z_0.unlock();
        z_1.lock();
        z_2.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
      for (int i = 1; i <= n; ++i) {
        z_0.lock();
        printNumber(0);
        if (i % 2) {
          z_1.unlock();
        } else {
          z_2.unlock();
        }
      }
    }

    void even(function<void(int)> printNumber) {
      for (int i = 2; i <= n; i+=2) {
        z_2.lock();
        printNumber(i);
        z_0.unlock();
      }
    }

    void odd(function<void(int)> printNumber) {
      for (int i = 1; i <= n; i+=2) {
        z_1.lock();
        printNumber(i);
        z_0.unlock();
      }
    }
};

void printThreadEvenOdd(){
//  auto zz = ZeroEvenOdd(51);
//  std::thread th1(std::bind(&ZeroEvenOdd::zero,zz,printNumberx));
//  std::thread th2(std::bind(&ZeroEvenOdd::odd,zz,printNumberx));
//  std::thread th3(std::bind(&ZeroEvenOdd::even,zz,printNumberx));
//  th1.join();
//  th2.join();
//  th3.join();
}