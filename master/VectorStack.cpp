#include "../StackH/VectorStack.h"

VectorStack::VectorStack(const ValueType* valueArray, const int arraySize) : vec(std::vector<ValueType>(valueArray, valueArray + arraySize))
{

}

void VectorStack::push(const ValueType& value)
{
    vec.push_back(value);
}

void VectorStack::pop()
{
    vec.pop_back();
}

const ValueType& VectorStack::top() const
{
    return vec.back();
}

bool VectorStack::isEmpty() const
{
    return vec.empty();
}

int VectorStack::size() const
{
    return vec.size();
}