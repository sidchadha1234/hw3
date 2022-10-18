#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};
          
//empty constructor/destructor because no private variables

template <typename T>
Stack<T>::Stack(){

}

template <typename T>
Stack<T>::~Stack(){

}

//return the size
template <typename T>
size_t Stack<T>::size() const{
  return std::vector<T>::size(); //scope like this
}

//check if its empty
template <typename T>
bool Stack<T>::empty() const{
  return std::vector<T>::empty();
}

//push it to the back
template <typename T>
void Stack<T>::push(const T& item){
  std::vector<T>::push_back(item);
}

//pop from the back
template <typename T>
void Stack<T>::pop(){
  if(std::vector<T>::size() == 0){
    throw std::underflow_error("Stack is empty");
  }
  std::vector<T>::pop_back();
  
}

//get the back since thats where everythings happening (LIFO)
template <typename T>
const T& Stack<T>::top() const{
  if(std::vector<T>::size() == 0){
    throw std::underflow_error("Stack is empty");
  }
  return std::vector<T>::back();
}



#endif