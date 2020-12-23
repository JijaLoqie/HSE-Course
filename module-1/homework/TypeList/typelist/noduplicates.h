#pragma once

#include "erase.h"
#include "typelist.h"

template<typename TList>
struct NoDuplicates;

template <>
struct NoDuplicates<NullType> {
    typedef NullType NewTypeList;
};

template <typename Head, typename Tail>
struct NoDuplicates<TypeList<Head, Tail>> {
private:
    typedef typename NoDuplicates<Tail>::NewTypeList tailNoDublicates;
    typedef typename Erase<tailNoDublicates, Head>::NewTypeList resultWithoutHead;

public:
    typedef TypeList<Head, resultWithoutHead> NewTypeList;
};
