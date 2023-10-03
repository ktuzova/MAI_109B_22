
#ifndef DO_HPP_INCLUDED
#define DO_HPP_INCLUDED

#include "Record.hpp"

#include <iostream>
#include <algorithm>
#include <ctime> 
#include <cstdlib> 

class Do {

    public:
	void bubbleSort(Record table[], int n);
 
	int binarySearch(Record table[], int n, int target);
};

#include "../src/Do.cpp"


#endif
