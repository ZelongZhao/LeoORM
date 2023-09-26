//
// Created by 赵泽龙 on 2023/9/27.
//

#pragma once

#include <vector>
#include <string>

#define ORMAP(_MY_CLASS_, ...)                            \
template <typename VISITOR>                               \
void __Accept (VISITOR &visitor)                          \
{                                                         \
    visitor.Visit (__VA_ARGS__);                          \
}                                                         \
template <typename VISITOR>                               \
void __Accept (VISITOR &visitor) const                    \
{                                                         \
    visitor.Visit (__VA_ARGS__);                          \
}                                                         \


class Visitor {
public:
    std::vector<std::string> serializedValues;

    template<typename... Args>
    inline void visit(Args &...args) {
        _visit(args...);
    }

protected:
    template<typename T, typename... Args>
    inline void _visit(T &property, Args &...args) {
        _visit(property);
        _visit(args...);
    }

    template<typename T>
    inline void _visit(T &property) {
        serializedValues.push_back(std::to_string(property));
    }

    template<>
    inline void _visit<std::string>(std::string &property){
        serializedValues.emplace_back ("'" + property + "'");
    }
};

class foo{
public:
    int a;
    std::string s;

    ORMAP(foo,a,s)
};

