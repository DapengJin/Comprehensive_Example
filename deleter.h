//
// Created by 45184 on 2020/5/31.
//

#ifndef COMPREHENSIVE_EXAMPLE_DELETER_H
#define COMPREHENSIVE_EXAMPLE_DELETER_H

#endif //COMPREHENSIVE_EXAMPLE_DELETER_H

struct deleter{
    template<class T>
    void operator () (T *p){delete p;};
};