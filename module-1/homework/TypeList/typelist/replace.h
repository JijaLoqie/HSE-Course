#pragma once

#include "typelist.h"

template<typename TList, typename OldType, typename NewType> 
struct Replace;

template <typename Old, typename New>
struct Replace<NullType, Old, New> {
    typedef NullType NewTypeList;
};

template <typename Tail, typename Old, typename New>
struct Replace<TypeList<Old, Tail>, Old, New> {
    typedef TypeList<New, Tail> NewTypeList;
};

template <typename Head, typename Tail, typename Old, typename New>
struct Replace<TypeList<Head, Tail>, Old, New> {
    typedef TypeList<Head, typename Replace<Tail, Old, New>::NewTypeList> NewTypeList;
};
