#pragma once

using ValueType = double;

class IStackImplementation;

enum class StackContainer
{
    Vector = 0,
    List,
};

class Stack
{
    public:
        Stack(StackContainer container = StackContainer::List);
        Stack(const ValueType* valueArray, const int arraySize,
            StackContainer container = StackContainer::List);

        explicit Stack(const Stack& other);
        Stack& operator=(const Stack& other);

        ~Stack();

        void push(const ValueType& value);
        void pop();
        const ValueType& top() const;
        bool isEmpty() const;
        int size() const;

    private:
        IStackImplementation* _pimpl = nullptr;
        StackContainer _containerType;
};