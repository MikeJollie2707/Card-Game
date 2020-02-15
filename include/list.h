#ifndef DDLIST_H
#define DDLIST_H

#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() { next = nullptr; prev = nullptr; }
    Node(T const& data) 
    {
        next = nullptr; 
        prev = nullptr; 
        this->data = data; 
    }
};

template <typename T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int len;
public:
    // A pointer used to iterate.
    Node<T>* iter;

    List() { head = nullptr; tail = nullptr; iter = nullptr; len = 0; }
    ~List()
    {
        clear();
    }
    // Return pointer to the first element.
    Node<T>* front() { return head; }
    // Return pointer to the last element.
    Node<T>* back() { return tail; }

    bool empty() { return (len == 0); }
    unsigned int size() { return len; }

    void push_back(T const& data)
    {
        Node<T>* element = new Node<T>(data);
        if (len > 0)
        {
            tail->next = element;
            element->prev = tail;
            tail = element;
        }
        else
        {
            head = element;
            tail = element;
        }
        len++;
    }
    void push_back(Node<T>* element)
    {
        if (len > 0)
        {
            tail->next = element;
            element->prev = tail;
            tail = element;
        }
        else
        {
            head = element;
            tail = element;
        }
        len++;
    }
    void push_front(T const& data)
    {
        Node<T>* element = new Node<T>(data);
        if (len == 0)
        {
            head = element;
            tail = element;
        }
        else
        {
            head->prev = element;
            element->next = head;
            head = element;
        }
        len++;
    }
    void push_front(Node<T>* element)
    {
        if (len == 0)
        {
            head = element;
            tail = element;
        }
        else
        {
            head->prev = element;
            element->next = head;
            head = element;
        }
        len++;
    }
    /**
     * @brief Remove the last element, return the pointer to it.
     * 
     * @return Node<T>* The pointer to the removed Node. nullptr if the size is 0.
     */
    Node<T>* pop_back()
    {
        Node<T>* element = tail;
        if (len > 1)
        {
            tail->prev->next = nullptr;
            tail = tail->prev;
            element->prev = nullptr;
        }
        else if (len == 0) element = nullptr;

        len--;
        return element;
    }
    /**
     * @brief Remove the first element, return the pointer to it.
     * 
     * @return Node<T>* The pointer to the removed Node. nullptr if the size is 0.
     */
    Node<T>* pop_front()
    {
        Node<T>* element = head;
        if (len > 1)
        {
            head->next->prev = nullptr;
            head = head->next;
            element->next = nullptr;
        }
        else if (len == 0) element = nullptr;

        len--;
        return element;
    }
    /**
     * @brief Construct and insert an element before pos.
     * 
     * @param pos Node<T>* The pointer to an element to insert before. nullptr if insert at the back.
     * @param data const T& The data to construct.
     */
    void insert(Node<T>* pos, T const& data)
    {
        if (pos == nullptr) push_back(data);
        else if (pos == head) push_front(data);
        else
        {
            Node<T>* element = new Node<T>(data);
            pos->prev->next = element;
            element->prev = pos->prev;
            pos->prev = element;
            element->next = pos;
            len++;
        }
    }
    /**
     * @brief Insert an element before pos.
     * 
     * @param pos Node<T>* The pointer to an element to insert before. nullptr if insert at the back.
     * @param element Node<T>* The pointer to the element to insert.
     */
    void insert(Node<T>* pos, Node<T>* element)
    {
        if (pos == head)
            push_front(element);
        else if (pos == nullptr) 
            push_back(element);
        else
        {
            pos->prev->next = element;
            element->prev = pos->prev;
            pos->prev = element;
            element->next = pos;
        }
    }
    Node<T>* remove(Node<T>* pos)
    {
        if (pos == tail) 
            return pop_back();
        else if (pos == head)
            return pop_front();
        else
        {
            Node<T>* element = pos;
            pos->next->prev = pos->prev;
            pos->prev->next = pos->next;
            pos->next = nullptr;
            pos->prev = nullptr;
            len--;
            return element;
        }
    }
    /**
     * @brief Move an element to a destination.
     * 
     * @param element Node<T>* Pointer to the element you want to insert.
     * @param pos Node<T>* Pointer to the location you want to insert.
     * 
     * @exception If element is pos->prev or size < 2, the method do nothing.
     * @exception If element is not belong to the list, the behavior is undefined.
     * @exception If element is nullptr, the behavior is undefined.
     */
    void moveto(Node<T>* element, Node<T>* pos)
    {
        if (element == pos->prev || len < 2) return;
        /*if (element->next == nullptr && element->prev == nullptr)
        {
            std::cout << "Use 'insert', 'push_back' or 'push_front' instead." << std::endl;
            return;
        }*/
        if (pos == head)
        {
            element->prev->next = element->next;
            if (element != tail)
                element->next->prev = element->prev;
            else
                tail = element->prev;
            element->prev = nullptr;
            element->next = head;
            head->prev = element;
            head = element;
        }
        else if (pos == nullptr)
        {
            element->next->prev = element->prev;
            if (element != head)
                element->prev->next = element->next;
            else
                head = element->next;
            element->next = nullptr;
            element->prev = tail;
            tail->next = element;
            tail = element;
        }
        else
        {
            if (element == head)
            {
                element->next->prev = nullptr;
                head = element->next;
            }
            else if (element == tail)
            {
                element->prev->next = nullptr;
                tail = element->prev;
            }
            element->next = pos;
            element->prev = pos->prev;
            pos->prev->next = element;
            pos->prev = element;
        }
        
    }
    void clear()
    {
        iter = head;
        int counter = 0;
        if (len == 0) return;
        while (iter->next != nullptr)
        {
            iter = head->next;
            delete head;
            //std::cout << counter++ << std::endl;
            head = iter;
        }
        len = 0;
        delete iter;
    }
    Node<T>& operator[](int const& index)
    {
        iter = head;
        int count = 0;
        while (count != index)
        {
            iter = iter->next;
            count++;
        }
        return *iter;
    }
    void swap(Node<T>& first, Node<T>& second)
    {
        if (len <= 1) return;
        if (len == 2)
        {
            iter = head;
            head->prev = tail;    
            head->next = nullptr;
        
            tail->prev = nullptr;
            tail->next = head;

            head = tail;
            tail = iter;
            iter = head;
        }
        else if (len > 2)
        {
            /*std::cout << "Pair: " << std::endl;
            std::cout << "My address: " << &first << std::endl;
            std::cout << first.prev << "|" << first.next << std::endl;
            std::cout << "His address: " << &second << std::endl;
            std::cout << second.prev << "|" << second.next << std::endl;*/
            /*std::cout << "After swap: " << std::endl;
            std::cout << "My address: " << &first << std::endl;
            std::cout << first.prev << "|" << first.next << std::endl;
            std::cout << "His address: " << &second << std::endl;
            std::cout << second.prev << "|" << second.next << std::endl;*/
            /*if (&first == head || &second == head)
            {
                if (&first == head && &second == tail)
                {
                    first.next->prev = &second;
                    second.prev->next = &first;

                    first.prev = second.prev;
                    second.next = first.next;

                    head = &second;
                    tail = &first;
                }
                else if (&first == head && &second != tail)
                {
                    if (first.next != &second && first.prev != &second)
                    {
                        first.next->prev = &second;
                        second.prev->next = &first;

                        second.next->prev = &first;

                        Node<T>* temp = first.next;
                        first.next = second.next;
                        second.next = temp;

                        temp = first.prev;
                        first.prev = second.prev;
                        second.prev = temp;

                        head = &second;
                    }
                }
            }
            else if (&first == tail || &second == tail)
            {

            }
            else if (first.next == &second || first.prev == &second)
            {

            }
            else
            {
                //std::cout << "Pair: " << std::endl;
                //std::cout << "My address: " << &first << std::endl;
                //std::cout << first.prev << "|" << first.next << std::endl;
                //std::cout << "His address: " << &second << std::endl;
                //std::cout << second.prev << "|" << second.next << std::endl;
                first.prev->next = &second;
                first.next->prev = &second;
                second.prev->next = &first;
                second.next->prev = &first;
                
                Node<T>* temp = first.next;
                first.next = second.next;
                second.next = temp;

                temp = first.prev;
                first.prev = second.prev;
                second.prev = temp;

                //std::cout << "After swap: " << std::endl;
                //std::cout << "My address: " << &first << std::endl;
                //std::cout << first.prev << "|" << first.next << std::endl;
                //std::cout << "His address: " << &second << std::endl;
                //std::cout << second.prev << "|" << second.next << std::endl;
                /*T temp = first.data;
                first.data = second.data;
                second.data = temp;
            }*/

            // I'm assuming first is before second.

            if (head == &first && tail == &second)
            {
                // Set the previous nodes point to correct node
                first.next->prev = &second;
                second.prev->next = &first;
                // Set the nodes point to correct nodes
                first.prev = second.prev;
                second.next = first.next;
                // Set the first node + second node point to null
                first.next = nullptr;
                second.prev = nullptr;
                // Swap the head and tail pointer
                Node<T>* temp = head;
                head = tail;
                tail = temp;
            }
            else if (head == &first && tail != &second)
            {
                // Point the prev to the correct prev
                first.prev = second.prev;
                // Point the next to the corrent node
                first.next->prev = &second;
                // Point the next and prev to the correct node
                second.next->prev = &first;
                second.prev->next = &first;
                // Switch the next pointers
                Node<T>* temp = first.next;
                first.next = second.next;
                second.next = temp;
                // Set the second as head
                second.prev = nullptr;
                head = &second;
            }
            else if (tail == &first && head != &second)
            {
                // Do the opposite as above
                first.next = second.next;

                first.prev->next = &second;

                second.prev->next = &first;
                second.next->prev = &first;

                Node<T>* temp = first.prev;
                first.prev = second.prev;
                second.prev = temp;

                second.next = nullptr;
                tail = &second;
            }
            else if (first.next = &second && tail != &second)
            {
                // Set the next and prev to correct next prev node
                first.next = second.next;
                second.prev = first.prev;
                // Set the prev and next to correct node
                first.prev = &second;
                second.next = &first;
            }
            else if (head != &first && tail != &second)
            {
                first.next->prev = &second;
                first.prev->next = &second;

                second.next->prev = &first;
                second.prev->next = &first;

                Node<T>* temp = first.next;
                first.next = second.next;
                second.next = temp;

                temp = first.prev;
                first.prev = second.prev;
                second.prev = temp;
            }

        }
        
    }
    void print()
    {
        if (len == 0) return;
        iter = head;
        std::cout << "Size: " << len << std::endl;
        while (iter->next != nullptr)
        {
            std::cout << "My address: " << iter << std::endl;
            std::cout << "|" << iter->prev << "|";
            std::cout << "|" << &(iter->data) << "|";
            std::cout << "|" << iter->next << "|";
            std::cout << std::endl;
            iter = iter->next;
        }
        std::cout << "My address: " << iter << std::endl;
        std::cout << "|" << iter->prev << "|";
        std::cout << "|" << &(iter->data) << "|";
        std::cout << "|" << iter->next << "|";
        std::cout << std::endl;
        std::cout << "Current head: " << head << std::endl;
        std::cout << "Current tail: " << tail << std::endl;
        iter = head;
    }
};

#endif