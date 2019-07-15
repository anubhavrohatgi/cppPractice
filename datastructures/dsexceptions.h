#ifndef DSEXCEPTIONS_H
#define DSEXCEPTIONS_H


#include <iostream>

namespace ds {

enum dsexceptions {
    FAIL_ACCESS = 200,
    FAIL_ALLOC,
    INVALID_INDEX,
    OUT_OF_BOUNDS
};


}//end of namespace ds

#endif // DSEXCEPTIONS_H
