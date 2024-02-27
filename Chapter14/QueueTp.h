#pragma once
#include <queue>

template <class T>
class QueueTp
{
private:
    std::queue<T> items;

public:
    bool isempty() const { return items.empty(); }
    int queuecount() const { return items.size(); }
    bool enqueue(const T& item);
    bool dequeue(T& item);
};

template <class T>
inline bool QueueTp<T>::enqueue(const T &item)
{
    items.push(item);
    return true;
}

template <class T>
inline bool QueueTp<T>::dequeue(T &item)
{
    if(isempty())
    {
        std::cerr << "Queue is empty!\n";
        return false;
    }
    item = items.front();
    items.pop();
    return true;
}
