#include "data.h"

Data::Data()
{
    this->agregators.push_back(Agregator("ag_1"));
    this->agregators.push_back(Agregator("ag_2"));
    this->agregators.push_back(Agregator("ag_3"));
}

/*void Data::print(){
    for (int i = 0; i < agregators.size(); ++i)
        agregators.at(i).print();
}*/
