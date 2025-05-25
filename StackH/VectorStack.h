#pragma once

#include <vector>
#include "IStackImplementation.h"

class VectorStack : public IStackImplementation
{
    public:
        VectorStack() = default;
        VectorStack(const ValueType* valueArray, const int arraySize);
        explicit VectorStack(const VectorStack& other) = default;
        VectorStack& operator=(const VectorStack& other) = default;

        virtual void push(const ValueType& value) override;
        virtual void pop() override;
        virtual const ValueType& top() const override;
        virtual bool isEmpty() const override;
        virtual int size() const override;
        virtual ~VectorStack() = default;

    private:
        std::vector<ValueType> vec;
};