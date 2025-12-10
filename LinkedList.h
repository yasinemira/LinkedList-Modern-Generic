#include <iostream>
#include <memory>

/**
 * Linked-List implementation using modern C++*
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
    
    LinkedList() = default;

    LinkedList(T val)
    {
        auto node = std::make_shared<Node<T>>(val);
        m_head = node;
        m_tail = node;
        ++m_length;
    }

    // Time-complexity: O(1)
    // changed the return type from void to LinkedList<T>&
    // for enriching the code with a cascade call capability
LinkedList<T>& append(int val) 
{
    auto newNode = std::make_shared<Node<T>>(val);

    if (m_head == nullptr) { 
        // To avoid segfault in case the linked-list was empty in the beginning.
        m_head = newNode;
        m_tail = newNode;
    } else {
        // If the linked-list was already populated.
        m_tail->next = newNode;
        m_tail = newNode;
    }
    
    ++m_length;
    return *this;
}

    // Time-complexity: O(n)
    void pop()
    {
        if (!m_head) {
            throw std::out_of_range("no node available/linked-list is empty!");
        }

        if (m_length == 1) {
            m_head.reset();
            m_tail.reset();
            --m_length;
        }

        auto temp = m_head;
        while (temp->next != m_tail) {
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
        if (m_length == 0) {
            m_head = newNode;
            m_tail = newNode;
        }
        else {
            newNode->next = m_head;
            m_head = newNode;
        }
        ++m_length;
    }

    // Time-complexity: O(1)
    void popFirst()
    {
        if (!m_head) {
            throw std::out_of_range("no node available/the linked-list is empty!");
        }
        if (m_length == 1) {
            m_head.reset();
            m_tail.reset();
        }else {
            m_head = std::move(m_head->next);
        }
        --m_length;
    }

    // Time-complexity: O(n)
    T get(int index)
    {
        if (index < 0 || index >= m_length) {
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
        ++m_length;
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
        --m_length;
    }

    void reverse()
    {
        if (m_length <= 0) {
            throw std::runtime_error("Invalid operation!");
        }
        
        if(m_length == 1) {
            return;
        }

        //first, swap head and tail
        auto temp = m_head;
        m_head = m_tail;
        m_tail = temp;

        //second, introduce "before" and "after" trackers
        sp<Node<T>> before = nullptr;
        sp<Node<T>> after = nullptr;

        // before - temp - after pointers will move in harmony
        while (temp != nullptr) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    sp<Node<T>> getHead() const
    {
        //removed the throw expressions for sake of exercise applications
        return m_head;
    }

    sp<Node<T>> getTail() const
    {   
        //removed the throw expressions for sake of exercise applications
        return m_tail;
    }

    int getLength() const
    {
        return m_length;
    }

    void printLinkedList() const
    {
        auto temp = m_head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    static const LinkedList<T> createLinkedList()
    {
        //initializing with some dummy values and also indirectly testing the linkedlist-related functions
        auto ll = LinkedList(11);
        ll.append(16);
        ll.append(5);
        ll.prepend(77);
        ll.pop();
        ll.append(-2);
        ll.prepend(11);
        (void)ll.getHead()->value;
        (void)ll.getTail()->value;
        ll.set(2, 24);
        ll.printLinkedList();
        return ll;
    }

private:
    sp<Node<T>> m_head{nullptr};
    sp<Node<T>> m_tail{nullptr};
    int m_length{0};
};
 