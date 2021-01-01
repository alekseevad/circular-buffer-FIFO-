#ifndef _FIFO1_HPP_
#define _FIFO1_HPP_
#include <iostream>

template <typename T>
struct Node {
    T value_;
    Node* next_;
};

template <class T>
class Queue
{
public:
    Queue() 
    {}

    Queue(int size) : border_(size)
    {
        index_ = 0;
        for (size_t i = 0; i < border_; ++i) {
            if (index_ == 0) {
                head_ = new Node<T>;
                tail_ = head_;
                index_++;
            }
            else {
                tail_->next_ = new Node<T>;
                tail_ = tail_->next_;
                index_++;
            }
        }
        index_ = 0;
    }

    ~Queue()
    {
        deleteQueue();
    }

    void addItem(T value)
    {
        if (index_ == border_) {
            index_ = 1;
            head_->value_ = value;
            tail_ = head_;
        }
        else {
            if (index_ == 0) {
                Node<T>* current = head_;
                tail_ = current;
                current->value_ = value;
                ++index_;
            }
            else {
                Node<T>* current = tail_->next_;
                current->value_ = value;
                tail_ = current;
                ++index_;
            }
        }
    }   

    void deleteQueue()
    {
        while (index_ > 0) {
            Node<T>* temp;
            temp = head_;
            if (temp->next_ != nullptr) {
                head_ = temp->next_;
            }
            delete temp;
            --index_;
        }
    }

private:
    Node<T>* head_, * tail_;
    int index_;
    int border_;

    template <typename T1>
    friend std::ostream& operator<< (std::ostream& out, const Queue<T1>& que);

    template <typename T1>
    friend std::istream& operator>> (std::istream& in, Queue<T1>& que);

};

template <typename T1>
std::ostream& operator<< (std::ostream& out, const Queue<T1>& que)
{
    out << "Queue: " << std::endl;
    Node<T1>* current = que.head_;
    for (size_t i = 1; i <= que.border_; ++i) {
        out << i << ": " << current->value_ << std::endl;
        current = current->next_;
    }
    return out;
}

template <typename T1>
std::istream& operator>> (std::istream& in, Queue<T1>& que)
{
    T1 value;
    in >> value;
    que.addItem(value);
    return in;
}

#endif