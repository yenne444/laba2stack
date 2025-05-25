#pragma once

#include <list>
#include "IStackImplementation.h"

class ListStack : public IStackImplementation
{
    public:
        ListStack() = default;
        ListStack(const ValueType* valueArray, const int arraySize);
        explicit ListStack(const ListStack& other) = default;
        ListStack& operator=(const ListStack& other) = default;

        virtual void push(const ValueType& value) override;
        virtual void pop() override;
        virtual const ValueType& top() const override;
        virtual bool isEmpty() const override;
        virtual int size() const override;
        virtual ~ListStack() = default;

    private:
        std::list<ValueType> lst;
};