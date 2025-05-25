#include <stdexcept>
#include <algorithm>
#include "../StackH/Stack.h"
#include "../StackH/IStackImplementation.h"
#include "../StackH/ListStack.h"
#include "../StackH/VectorStack.h"

Stack::Stack(StackContainer container) : _containerType(container)
{
    switch (container)
    {
        case StackContainer::List: 
            _pimpl = new ListStack();
            break;
        case StackContainer::Vector: 
            _pimpl = new VectorStack();
            break;
        default:
            throw std::runtime_error("Invalid container type");
    }
}

Stack::Stack(const ValueType* valueArray, const int arraySize, StackContainer container) : _containerType(container)
    {
    switch (container)
    {
        case StackContainer::List: 
            _pimpl = new ListStack(valueArray, arraySize);
            break;
        case StackContainer::Vector:
            _pimpl = new VectorStack(valueArray, arraySize);
            break;
        default:
            throw std::runtime_error("Invalid container type");
    }
}

Stack::Stack(const Stack& other)
{
    _containerType = other._containerType;
    switch (_containerType)
    {
        case StackContainer::List: 
            _pimpl = new ListStack(*dynamic_cast<ListStack*>(other._pimpl));
            break;
        case StackContainer::Vector: 
            _pimpl = new VectorStack(*dynamic_cast<VectorStack*>(other._pimpl));
            break;
        default:
            throw std::runtime_error("Invalid container type");
    }
}

Stack& Stack::operator=(const Stack& other)
{
    Stack temp = Stack(other);
    std::swap(this->_containerType, temp._containerType);
    std::swap(this->_pimpl, temp._pimpl);
    return *this;
}

Stack::~Stack()
{
    delete _pimpl;
}

void Stack::push(const ValueType& value)
{
    _pimpl->push(value);
}

void Stack::pop()
{
    _pimpl->pop();
}

const ValueType& Stack::top() const
{
    return _pimpl->top();
}

bool Stack::isEmpty() const
{
    return _pimpl->isEmpty();
}

int Stack::size() const
{
    return _pimpl->size();
}