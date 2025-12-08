#include <iostream>
#include <memory>

#include "LinkedList.h"

int main()
{
    std::cout << "\n---- Initial linked-list ----\n";
    auto ll = LinkedList<int>::createLinkedList();

    std::cout << "\n----Append elements----\n";
    {
        ll.append(10);
        ll.append(8);
        ll.append(2);
        (void)ll.getHead()->value;
        (void)ll.getTail()->value;
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Pop----\n";
    {
        ll.pop();
        (void)ll.getHead()->value;
        (void)ll.getTail()->value;
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Prepend----\n";
    {
        ll.prepend(6);
        (void)ll.getHead()->value;
        (void)ll.getTail()->value;
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Pop first----\n";
    {
        ll.popFirst();
        (void)ll.getHead()->value;
        (void)ll.getTail()->value;
        ll.printLinkedList();
        ll.getLength();
    }

    std::cout << "\n----Get elements----\n";
    {
        ll.prepend(16);
        ll.append(-5);
        (void)ll.getHead()->value;
        (void)ll.getTail()->value;
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
        (void)ll.getHead()->value;
        (void)ll.getTail()->value;
        ll.set(3, 24);
        // Fail on-purpose: ll.set(3);
        ll.printLinkedList();
    }

    std::cout << "\n----Reverse the linked list----\n";
    ll.reverse();
    ll.printLinkedList();

    return 0;
}