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
        std::cout << "OK\n";
        this->data = data; 
    }
    friend void swap(Node<T>& first, Node<T>& second)
    {
        Node<T> copy = first;
        first = second;
        second = copy;
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
        Node<T>* element = nullptr;
        try
        {
            element = new Node<T>(data);
        }
        catch(const std::bad_alloc& ba)
        {
            std::cout << "Oh noes\n";
            //std::cerr << ba.what() << '\n';
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "RIP\n";
        }
        std::cout << "Cool\n";
        if (len != 0)
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
    /*void push_back(Node<T>* element)
    {
        if (len != 0)
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
    }*/
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
        }
        len++;
    }
    Node<T>* pop_back()
    {
        Node<T>* element = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        element->prev = nullptr;
        len--;
        return element;
    }
    Node<T>* pop_front()
    {
        Node<T>* element = head;
        head->next->prev = nullptr;
        head = head->next;
        element->next = nullptr;
        len--;
        return element;
    }
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
    void clear()
    {
        Node<T>* mobile = head;
        while (mobile->next != nullptr)
        {
            mobile = head->next;
            delete head;
            head = mobile;
        }
        len = 0;
        delete mobile;
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
};

#endif