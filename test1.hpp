struct Node{
        Node *next = nullptr;
};

template <class T>
class Test{
private:
    
    template <typename T1>
    friend std::ostream& operator<< (std::ostream& out,const Test<T1>& qwe);
    int size = 9;
public:
        
};

template <typename T1>
std::ostream& operator<< (std::ostream& out,const Test<T1>& qwe)
{
    Node *current;
    out << qwe.size;
    return out;
}