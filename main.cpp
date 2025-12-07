#include <iostream>
#include <algorithm>
#include <memory>

/**
 * LINKED-LIST EXERCISES
 */

template <typename T>
using sp = std::shared_ptr<T>;

template <typename T>
struct Node
{
    Node(T val)
        : value{val},
          next{nullptr}
    {
    }

    T value;
    sp<Node> next;
};

template <typename T>
class LinkedList
{
public:
    LinkedList(T val)
    {
        auto node = std::make_shared<Node<T>>(val);
        m_head = node;
        m_tail = node;
        ++m_length;
    }

    // Time-complexity: O(1)
    void append(T val)
    {
        auto newNode = std::make_shared<Node<T>>(val);
        m_tail->next = newNode;
        m_tail = newNode;
        ++m_length;
    }

    // Time-complexity: O(n)
    void pop()
    {
        if (!m_head)
        {
            throw std::out_of_range("no node available/linked-list is empty!");
        }

        if (m_length == 1)
        {
            m_head.reset();
            m_tail.reset();
            --m_length;
        }

        auto temp = m_head;
        while (temp->next != m_tail)
        {
            temp = temp->next;
        }
        m_tail = temp;
        m_tail->next = nullptr;
        --m_length;
    }

    // Time-complexity: O(1)
    void prepend(T val)
    {
        auto newNode = std::make_shared<Node<T>>(val);
        if (m_length == 0)
        {
            m_head = newNode;
            m_tail = newNode;
        }
        else
        {
            newNode->next = m_head;
            m_head = newNode;
        }
        ++m_length;
    }

    // Time-complexity: O(1)
    void popFirst()
    {
        if (!m_head)
        {
            throw std::out_of_range("no node available/the linked-list is empty!");
        }
        if (m_length == 1)
        {
            m_head.reset();
            m_tail.reset();
        }
        else
        {
            m_head = m_head->next;
        }
        --m_length;
    }

    // Time-complexity: O(n)
    T get(int index)
    {
        if (index < 0 || index >= m_length)
        {
            throw std::out_of_range("Invalid index!");
        }

        sp<Node<T>> temp = m_head;
        for (size_t i = 0; i < index; ++i) {
            temp = temp->next;
        }

        std::cout << "Value at the index #" << index << " is: " << temp->value << std::endl;
        return temp->value;
    }

    // Time-complexity: O(n)
    void set(int index, T val)
    {
        if (index < 0 || index >= m_length) {
            throw std::out_of_range("Invalid index!");
        }

        auto temp = m_head;
        for (size_t i = 0; i < index; ++i) {
            temp = temp->next;
        }
        temp->value = val;
        std::cout << "Value at the index #" << index << " is now: " << val << std::endl;
    }

    // Time-complexity: O(n)
    void insert(int index, T val) {
        if (index < 0 || index > m_length) {
            throw std::out_of_range("Invalid index!");
        }

        auto newNode = std::make_shared<Node<T>>(val);
        auto temp = m_head;

        if (index == 0) {
            prepend(val);
            return;
        }

        if (index == m_length) {
            append(val);
            return;
        }

        // go to the index to insert
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Time-complexity: O(n)
    void remove(int index) {
        if (index < 0 || index >= m_length) {
            throw std::out_of_range("Invalid index!");
        }
        
        if (index == 0) {
            popFirst();
            return;
        }

        if (index == m_length - 1) {
            pop();
            return;
        }

        auto temp = m_head;
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }

    T getHead() const
    {
        if (!m_head)
        {
            throw std::out_of_range("no node available/linked-list is empty!");
        }
        std::cout << "head:" << m_head->value << std::endl;
        return m_head->value;
    }

    T getTail() const
    {
        if (!m_tail)
        {
            throw std::out_of_range("no node available/linked-list is empty!");
        }
        std::cout << "tail: " << m_tail->value << std::endl;
        return m_tail->value;
    }

    int getLength() const
    {
        std::cout << "length: " << m_length << std::endl;
        return m_length;
    }

    void printLinkedList() const
    {
        auto temp = m_head;
        while (temp)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

private:
    sp<Node<T>> m_head;
    sp<Node<T>> m_tail;
    int m_length{0};
};

int main()
{
    auto ll = LinkedList(5);
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

    return 0;
}