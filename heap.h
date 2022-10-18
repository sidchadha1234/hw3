#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */

  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void trickleUp(int loc);
  void heapify(int loc);

private:
//need a vector, comparitor, and n-ary tree variable
  std::vector<T> g;
  PComparator compare;

  int n;

};



//constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  compare = c; 
  n =m; 
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc){
//trickle something up the tree when your pushing it 
int p = (loc-1)/n;
  if(loc ==0) return ;
  if(p>=0 && compare(g[loc], g[p])){  //if the parent is in bounds and g[loc] meets the neccesary conditions swap
      std::swap(g[p], g[loc]);
      loc = p;
  }else{
    return ;
  }
  trickleUp(loc); //recurse through each level of the tree
}

//heapify/trickledown
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int loc){

  unsigned int smallerChild = (n*loc)+1; // start w/ left/bestchild
  unsigned int rChild = smallerChild+1;//right child

//check everything is in bounds
  if(rChild>=g.size() && (smallerChild>g.size()-1 || g.size() == 0 )) return ;


  int i = 0;
  while(i<n){
    unsigned int curr = rChild+i;
    if(curr < g.size()){
      //if g[rchild+i] meets the nessecary conditions swap it down the tree
      if(compare(g[curr], g[smallerChild])){
            smallerChild = curr;
        }  
      }
     i++;  
    } 
  if(compare(g[smallerChild], g[loc])){ 
    std::swap(g[loc], g[smallerChild]); //check the smaller child against loc and keep recursing through the tree 
    heapify(smallerChild);

  }
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  g.push_back(item);
  //reference parent function trickleup to see how it trickles up three
  trickleUp(g.size()-1);
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Stack is empty");
  }

  return g[0]; 

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Stack is empty");
  }
  //swap the last and first element, pop the last element, and heapify/trickle it down
    std::swap(g[0],g[g.size()-1]);
    g.pop_back();
    heapify(0);

}

//check if it empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if(g.size() == 0) return true;
  return false;
}


//check the size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return g.size();
}

#endif

