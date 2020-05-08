#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <class NodeGenericType>
struct node {
    NodeGenericType data;
    struct node<NodeGenericType> *next;
};

template <class QueueGenericType>
class Queue {
private:
    struct node<QueueGenericType> *front;
    struct node<QueueGenericType> *rear;
    long _size;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        _size = 0;
    }
    ~Queue() {
        clear();
    }
    // name should be 'enqueue'
    void push(QueueGenericType newData) {
        struct node<QueueGenericType> *newNode = new node<QueueGenericType>;
        newNode->data = newData;
        newNode->next = nullptr;
        if (rear != nullptr) {
            rear->next = newNode;
            rear = newNode;
        } else {
            front = rear = newNode;
        }
        _size++;
    }
    // name should be 'dequeue'
    QueueGenericType pop() {
        struct node<QueueGenericType> *clear;
        QueueGenericType poppedData;
        if (front != nullptr) {
            poppedData = front->data;
            clear = front;
            front = front->next;
            free(clear);
            _size--;
        } else {
            throw std::string("empty queue!");
        }
        return poppedData;
    }
    // this method should not be injected in Queue structure
    QueueGenericType at(long index) {
        if (index < (long)0 || index >= _size) {
            throw std::string("out of range!");
        }
        struct node<QueueGenericType> *current = front;
        while (index-- && (current != nullptr)) {
            current = current->next;
        }
        return current->data;
    }
    long size() {
        return _size;
    }
    void clear() {
        struct node<QueueGenericType> *clear;
        while (front != nullptr) {
            clear = front;
            front = front->next;
            free(clear);
        }
        front = nullptr;
        rear = nullptr;
        _size = 0;
    }
};

#endif