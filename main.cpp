#include <iostream>
#include "Visitor.hpp"


auto main() -> int {
    foo a;
    a.a = 1;
    a.s = "fdsafads";
    Visitor v;
    v.visit(a.a,a.s);
    for(const auto &it : v.serializedValues){
        std::cout<<it<<std::endl;
    }
}

