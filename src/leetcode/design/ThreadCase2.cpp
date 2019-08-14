#include <utility>

//
// Created by mrityunjaykumar on 2019-08-07.
//

# include "../../common.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;

std::condition_variable cv;
int hcount=0;
int ocount=0;
std::queue<std::mutex> global_h;
std::queue<std::mutex> global_o;

void releaseO(){
  std::cout<<"O";
}

void releaseH(){
  std::cout<<"H";
}
std::mutex h,o;

class H2O {
public:
    H2O() {
    
    }

    static void hydrogen(function<void()> releaseHydrogen) {
      	hcount+=1;
      	while (ocount < 1){
      	  	h.lock ();
      	}
      	o.unlock ();
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hcount-=1;
    }

    static void oxygen(function<void()> releaseOxygen) {
        ocount+=1;
        while (hcount < 2){
          o.lock ();
      	}
        h.unlock ();
      	 
        releaseOxygen();
        ocount-=1;
    }
    
    static void trigger_H(function<void()> fun){
      hydrogen (std::move(fun));
    }
    
    static void trigger_O(function<void()> fun){
      oxygen (std::move(fun));
    }
    
};

void solveH20Challenge()
{
  std::string input("HHH0HHHHOOHHHOO");
  for (char i : input) {
    if(i=='H') {
	  std::thread t1 (std::bind (&H2O::trigger_H, releaseH));
	  t1.detach ();
	}else{
      std::thread t1 (std::bind (&H2O::trigger_O, releaseO));
      t1.detach ();
    }
  }
}