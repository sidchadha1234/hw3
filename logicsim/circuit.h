#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <vector>

#include "../heap.h"
#include "event.h"
#include "gate.h"

class Circuit 
{
	public:
		Circuit();
		~Circuit();
		void test();
		bool advance(std::ostream&);
		void run(std::ostream&);
    bool parse(const char*);
    void startUml(std::ostream&);
    void endUml(std::ostream&);
		
	private:
		uint64_t m_current_time;
        std::vector<Gate*> m_gates; //pointers to wires
        std::vector<Wire*> m_wires; //pointers to gates in circuit
				Heap<Event*,EventLess> m_pq; //m_pq data member is a min-heap of Event*
        
};

#endif
