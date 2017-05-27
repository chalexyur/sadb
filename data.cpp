#include "data.h"

Data::Data()
{
   // this->agregators.push_back(Agregator("ag_1"));
}

void Data::print(){
    for (int i = 0; i < agregators.size(); ++i)
        agregators.at(i).print();
}
