#ifndef _FIFO1_HPP_
#define _FIFO1_HPP_
#include <iostream>

template <typename T>
struct Node{
        T value_;
        Node  *next_;
};

template <class T>
class Queue
{
private:
    Node<T> *head_, *tail_;
    int size_;
    int border_;

    template <typename T1> 
    friend std::ostream& operator<< (std::ostream &out, const Queue<T1> &que);

    template <typename T1>
    friend std::istream& operator>> (std::istream &in, Queue<T1> &que);
public:
    
    Queue(int size) : border_(size)
    {
        size_ = 0;
        head_ = nullptr;
        tail_ = nullptr;
    }

    void addItem(T value) 
    {
        if(size_ == border_) {
            std::cerr << "Boof is full" << std::endl;
        } else {
            if(size_ == 0) {
                Node<T> *current = new Node<T>;
                head_ = current;
                tail_ = current;
                current->value_ = value;
                current->next_ = nullptr;
                ++size_;
            } else {
                Node<T> *current = new Node<T>;
                current->value_ = value;
                tail_->next_ = current;
                tail_ = current;
                ++size_;
            }
        }
    }

    ~Queue()
    {
        while(size_ > 0) {
            Node<T> *temp;
            temp = head_;
            if(temp->next_ != nullptr){
                head_ = temp->next_;
            }
            delete temp;
            --size_;             
        }
    }
};

template <typename T1>
std::ostream& operator<< (std::ostream &out, const Queue<T1> &que)
{
    out << "Queue: " << std::endl; 
    Node<T1> *current = que.head_;
    for(size_t i = 1; i <= que.size_; ++i) {
        out << i << ": " << current->value_ << std::endl;
        current = current->next_;
    }
    return out;
}

template <typename T1>
std::istream& operator>> (std::istream &in, Queue<T1> &que)
{
    T1 value;
    for(size_t i = 1; i <= que.border_; ++i) {
        in >> value;
        que.addItem(value);
    }
    return in;
}

#endif