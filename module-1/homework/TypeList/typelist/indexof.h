#pragma once

#include "typelist.h"

template<typename TList, typename TargetType>
struct IndexOf;

template <typename T>
struct IndexOf<NullType, T> {
    enum { pos = -1 };
};

template <typename T, typename Tail>
struct IndexOf<TypeList<T, Tail>, T> {
    enum { pos = 0 };
};

template <typename Head, typename Tail, typename T>
struct IndexOf<TypeList<Head, Tail>, T> {
private:
    enum { rec = IndexOf<Tail, T>::pos };

public:
    enum { pos = (rec == -1) ? -1 : 1 + rec};
};
