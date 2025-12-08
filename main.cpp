#include <iostream>
#include <memory>

#include "LinkedList.h"

int main()
{
    auto ll = LinkedList<int>::createLinkedList();
    ll.getHead();
    ll.getTail();
    ll.printLinkedList();
    ll.getLength();

    std::cout << "\n----Append elements----\n";
    {
        ll.append(10);
        ll.append(8);
        ll.append(2);
        ll.getHead();
        ll.getTail();
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Pop----\n";
    {
        ll.pop();
        ll.getHead();
        ll.getTail();
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Prepend----\n";
    {
        ll.prepend(6);
        ll.getHead();
        ll.getTail();
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Pop first----\n";
    {
        ll.popFirst();
        ll.getHead();
        ll.getTail();
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Get elements----\n";
    {
        ll.prepend(16);
        ll.append(-5);
        ll.getHead();
        ll.getTail();
        ll.get(2);
        // Fail on-purpose: ll.get(3);
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Set elements----\n";
    {
        ll.printLinkedList();
        ll.prepend(77);
        ll.pop();
        ll.append(-2);
        ll.printLinkedList();
        ll.getHead();
        ll.getTail();
        ll.set(3, 24);
        // Fail on-purpose: ll.set(3);
        ll.printLinkedList();
    }

    std::cout << "\n----Reverse the linked list----\n";
    ll.reverse();
    ll.printLinkedList();

    return 0;
}