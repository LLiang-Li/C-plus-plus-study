#pragma once
#include<iostream>
#include <string>

class Duck {
	std::string name;
	int weight;
  
	public:

    Duck(std::string, int weight) {
		this->name = name;
		this->weight = weight;
	}
 
	operator std::string() {
		return name + " weighs " + std::to_string(this->weight);
	}
 
 
  
	int compareTo(Duck* object) {
 
		Duck* otherDuck = object;
  
		if (this->weight <= otherDuck->weight) {
			return 0;
		} else  {
			return 1;}
		// } else { // this.weight > otherDuck.weight
		// 	return 1;
		// }
	}
};

void sort(Duck* start, int low, int high)
{
    Duck temp("temp",0);
    for (int  i = low; i < high; i++)
    {
        for (int j = high - 1; j >i; j--)
        {
            if (start[j].compareTo(&start[j - 1]) )
            {
                temp = start[j - 1];
                start[j - 1] = start[j];
                start[j] = temp;
            }
        }
    }
        
}