#include "stack.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    Stack<int> g;
    g.push(0);
    cout<<"0 " << g.top()<<endl;

    g.push(4);
    cout<<"This should print 4: " << g.top()<<endl;
    g.pop();
    cout<< "This should print 0: " <<g.top()<<endl;
    cout<< "This should print 1: " <<g.size()<<endl;
    cout<<"This should print 0: " << g.top()<<endl;
    
}
