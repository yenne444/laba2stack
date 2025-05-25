#include <iostream>
#include "../StackH/Stack.h"

int main()
{
    double init[] = {1.0, 2.0, 3.0, 4.0};
    
    Stack p(init, 4, StackContainer::List);
    Stack q(init, 4, StackContainer::Vector);

    q = p;

    std::cout << "Stack size: " << q.size() << "\n";

    q.push(9);
    q.push(12);

    std::cout << "Stack size: " << q.size() << "\n";

    std::cout << "Stack p:" << "\n";

    while(!p.isEmpty())
    {
        std::cout << "Pop: " << p.top() << "\n";
        p.pop();
    }

    std::cout << "Stack q:" << "\n";

    while(!q.isEmpty())
    {
        std::cout << "Pop: " << q.top() << "\n";
        q.pop();
    }
}