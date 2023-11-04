// g++ test33201.cpp -o test33201 -std=c++11
#include <iostream>
#include <string>

template <class T>
class Foo;

template <class T>
std::ostream &operator<<(std::ostream &os, const Foo<T> &sth);

template <class T>
class Foo
{
public:
    Foo() : data_(0), data2_(0), ptr_(nullptr) {}
    void set_data_inner(T data, int data2, Foo<T> *next_ptr)
    {
        data_ = data;
        data2_ = data2;
        ptr_ = next_ptr;
    }
    Foo<T> *&next() { return ptr_; }

private:
    T data_;
    int data2_;
    Foo<T> *ptr_;
    friend std::ostream &operator<< <>(std::ostream &os, const Foo<T> &sth);
};

template <>
class Foo<int>
{
public:
    Foo() : data_(0), data2_(0), ptr_(nullptr) {}
    void set_data_inner(int data, int data2, Foo<int> *next_ptr)
    {
        data_ = data;
        data2_ = data2;
        ptr_ = next_ptr;
    }
    Foo<int> *&next()
    {
        std::cout << "[next()]";
        return ptr_;
    }

private:
    int data_;
    int data2_;
    Foo<int> *ptr_;
    friend std::ostream &operator<< <>(std::ostream &os, const Foo<int> &sth);
};

template <class T>
void set_data_by_ptr(Foo<T> *here, T data, int data2, Foo<T> *next_ptr)
{
    here->set_data_inner(data, data2, next_ptr);
}

template <class T>
void set_data_by_ref(Foo<T> &here, T data, int data2, const Foo<T> &next_ref)
{
    here.set_data_inner(data, data2, &next_ref);
}

int main()
{
    Foo<int> *pp, a, b, c;
    a.set_data_inner(10, 20, &b);
    b.set_data_inner(11, 21, &c);
    c.set_data_inner(12, 22, nullptr);
    for (pp = &a; pp != nullptr; pp = pp->next())
        std::cout << *pp;
    std::cout << "[end]" << std::endl;

    Foo<double> *qq, d, e, f;
    set_data_by_ptr<double>(&d, 10.5, 30, &e);
    set_data_by_ptr<double>(&e, 11.5, 31, &f);
    set_data_by_ptr<double>(&f, 12.5, 32, nullptr);
    for (qq = &d; qq != nullptr; qq = qq->next())
        std::cout << *qq;
    std::cout << "[end]" << std::endl;

    Foo<char *> *rr, g, h, i;
    set_data_by_ptr<char *>(&g, (char *)"10.5i", 40, &h);
    set_data_by_ptr<char *>(&h, (char *)"11.5i", 41, &i);
    set_data_by_ptr<char *>(&i, (char *)"12.5i", 42, nullptr);
    for (rr = &g; rr != nullptr; rr = rr->next())
        std::cout << *rr;
    std::cout << "[end]" << std::endl;

    Foo<int> *head = new Foo<int>(), *list = head;
    for (int i = 0; i < 10; i++)
    {
        Foo<int> *next = new Foo<int>();
        next->set_data_inner(i * i, i + 100, nullptr);
        head->next() = next;
        head = next;
        // head->next() = new Foo<int>();
        // head->next()->set_data_inner(i * i, i + 100, nullptr);
        // head = head->next();
    }
    Foo<int> *empty_head = list;
    list = list->next();
    delete empty_head;

    std::cout << std::endl;
    for (int counter = 0; list != nullptr; list = list->next())
    {
        std::cout << *list;
        if ((counter++) % 5 == 4)
            std::cout << std::endl;
    }
    std::cout << "[end]" << std::endl;
    return 0;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Foo<T> &sth)
{
    os << "(" << sth.data_ << ", " << sth.data2_ << ") -> ";
    return os;
}

/*
(10, 20) -> [next()](11, 21) -> [next()](12, 22) -> [next()][end]
(10.5, 30) -> (11.5, 31) -> (12.5, 32) -> [end]
(10.5i, 40) -> (11.5i, 41) -> (12.5i, 42) -> [end]
[next()][next()][next()][next()][next()][next()][next()][next()][next()][next()][next()]
(0, 100) -> [next()](1, 101) -> [next()](4, 102) -> [next()](9, 103) -> [next()](16, 104) ->
[next()](25, 105) -> [next()](36, 106) -> [next()](49, 107) -> [next()](64, 108) -> [next()](81, 109) ->
[next()][end]
*/
