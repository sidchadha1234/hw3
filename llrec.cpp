#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){



  if(head==nullptr){ //if head is null set everyhting to null and return
    smaller = nullptr;
    larger = nullptr;
   return ;
  }

  else{
    llpivot(head->next, smaller, larger, pivot);//recursive call to next place
    if(head->val<=pivot){ //if it is smaller or equal to pivot, put it in smaller
      head->next = smaller;
      smaller=head;
    }
    if(head->val>pivot){ //if it is great than pivot, put it in larger
      head->next = larger;
      larger=head;
    }
    head = nullptr; //set head to null 
  }
}
