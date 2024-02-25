// stack.h -- class declaration for the stack ADT
typedef unsigned long Item;

class stack
{
private:
    enum { MAX = 10 }; // constant specific to class
    Item *pitems;
    int size; // number of elements in stack
    int top;  // index for top stack item

public:
    stack(int n = MAX); // creates stack with n elements
    stack(const stack &st);
    ~stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item); // add item to stack
    bool pop(Item &item);        // pop top into item
    stack &operator=(const stack &st);
};
