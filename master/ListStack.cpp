#include "../StackH/ListStack.h"

ListStack::ListStack(const ValueType* valueArray, const int arraySize) : lst(std::list<ValueType>(valueArray, valueArray + arraySize))
{

}

void ListStack::push(const ValueType& value)
{
    lst.push_back(value);
}

void ListStack::pop()
{
    lst.pop_back();
}

const ValueType& ListStack::top() const
{
    return lst.back();
}

bool ListStack::isEmpty() const
{
    return lst.empty();
}

int ListStack::size() const
{
    return lst.size();
}