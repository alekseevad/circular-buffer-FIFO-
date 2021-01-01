#ifndef _FIFO2_HPP
#define _FIFO2_HPP
#include <iostream>
#include <deque>

template<class T>
class QueueORGN : public std::deque<T>
{
public:
	QueueORGN(int size) : border_(size)
	{
		is_full_ = false;
	}

	~QueueORGN()
	{
		newqueue_.~deque();
	}

	void addItem(T value) 
	{
		switch (is_full_) {
		case true:
			newqueue_.pop_front();
			newqueue_.push_back(value);
			break;
		case false:
			if (index_ == border_) {
				is_full_ = true;
				newqueue_.pop_front();
				newqueue_.push_back(value);
			}
			else {
				newqueue_.push_back(value);
				++index_;
			}
			break;
		}
	} 

	const int getMaxSize()
	{
		return border_;
	}

	const T& getValue(int i)
	{
		return newqueue_[i];
	}
private:
	int border_;
	int index_;
	std::deque<T> newqueue_;
	bool is_full_;

	template <typename T1>
	friend std::ostream& operator<< (std::ostream& out, const QueueORGN<T1>& que);

	template <typename T1>
	friend std::istream& operator>> (std::istream& in, QueueORGN<T1>& que);
};

template <typename T1>
std::ostream& operator<< (std::ostream& out, QueueORGN<T1>& que)
{
	out << "Elements: " << std::endl;
	for (int i = 0; i < que.getMaxSize(); i++)
	{
		out << i << ": ";
		out << que.getValue(i) << std::endl;
	}
	return out;
}

template <typename T1>
std::istream& operator>> (std::istream& in, QueueORGN<T1>& que)
{
	T1 value;
	in >> value;
	que.addItem(value);
	return in;
}

#endif
