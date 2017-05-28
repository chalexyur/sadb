#include "data.h"

void Data::print(){
    for (unsigned i = 0; i < room.size(); ++i)
        room.at(i).print();
}
