#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

//a functor that compares Events by time

typedef struct EventLess {
    bool operator()(Event* c1, Event* c2){
      return (c1->time < c2->time); 
    }
} EventLess;
	
#endif
