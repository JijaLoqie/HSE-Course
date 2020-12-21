
#include "list.h"
#include <iostream>

task::list::list() : first(nullptr),
                     last(nullptr),
                     length(0)
{}
task::list::list(const list& other)
{
    first = nullptr;
    last = nullptr;
    length = 0;
    Node* curNow = other.first;
    while (curNow)
    {
        push_back(curNow->cur);
        curNow = curNow->next;
    }
}

task::list::~list()
{
    clear();
}

struct Node
{
    int cur;
    Node* next;
    Node* prev;
};

task::list::list(size_t count, const int& value)
{
    first = nullptr;
    last = nullptr;
    length = 0;
    while (count > length)
    {
        push_back(value);
    }
}

task::list& task::list::operator=(const list& other)
{
    if (this == &other)
    {
        return *this;
    }
    resize(other.size());
    Node* curNow1 = first;
    Node* curNow2 = other.first;
    while (curNow2)
    {
        curNow1->cur = curNow2->cur;
        curNow1 = curNow1->next;
        curNow2 = curNow2->next;
    }
    return *this;
}

int& task::list::front()
{
    return first->cur;
}
const int& task::list::front() const
{
    return first->cur;
}

int& task::list::back()
{
    return last->cur;
}
const int& task::list::back() const
{
    return last->cur;
}

bool task::list::empty() const
{
    return first == nullptr;
}
size_t task::list::size() const
{
    return length;
}
void task::list::clear()
{
    while (first)
    {
        Node* n = first->next;
        delete first;
        first = n;
        length--;
    }
}

void task::list::push_back(const int& cur)
{
    if (length == 0)
    {
        first = new Node;
        first->cur = cur;
        last = first;
    }
    else if (length == 1)
    {
        Node* newNode = new Node;
        newNode->cur = cur;
        last->next = newNode;
        last = newNode;
        newNode->prev = first;
    }
    else
    {
        Node* newNode = new Node;
        newNode->cur = cur;
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    length++;
}
void task::list::pop_back()
{
    if (length != 1)
    {
        Node* lastlast = last;
        last = last->prev;
        delete lastlast;
        last->next = nullptr;
    }
    else
    {
        delete last;
        last = nullptr;
        first = nullptr;
    }
    length--;
}
void task::list::push_front(const int& cur)
{
    if (length == 0)
    {
        last = new Node;
        last->cur = cur;
        first = last;
    }
    else if (length == 1)
    {
        Node* newNode = new Node;
        newNode->cur = cur;
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
    else
    {
        Node* newNode = new Node;
        newNode->cur = cur;
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
    length++;
}
void task::list::pop_front()
{
    if (length != 1)
    {
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
    }
    else
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    length--;
}
void task::list::resize(size_t count)
{
    while (count > length)
    {
        push_back(0);
    }
    while (count < length)
    {
        pop_back();
    }
}
void task::list::swap(list& other)
{
    size_t l1 = size();
    size_t l2 = other.size();
    length = l2;
    other.length = l1;
    Node* f1 = first, *f2 = other.first;
    first = f2;
    other.first = f1;
    Node* la1 = last, *la2 = other.last;
    last = la2;
    other.last = la1;
}

void task::list::remove(const int& value)
{
    const int delcur = value;
    Node* curNow = first;
    while (curNow)
    {
        if (curNow->cur == delcur)
        {
            if (curNow == first)
            {
                curNow = curNow->next;
                pop_front();
            }
            else if (curNow == last)
            {
                pop_back();
                break;
            }
            else
            {
                Node* delCur = curNow;
                curNow = curNow->next;
                delCur->prev->next = curNow;
                curNow->prev = delCur->prev;
                delete delCur;
                delCur = nullptr;
                length--;
            }
        }
        else
        {
            curNow = curNow->next;
        }
    }
}

void task::list::unique()
{
    Node* curNow = first;
    while (curNow && curNow->next)
    {
        if (curNow->cur == curNow->next->cur)
        {
            Node* delCur = curNow->next;
            if (delCur == last)
            {
                pop_back();
            }

            else
            {
                curNow->next = delCur->next;
                delCur->next->prev = curNow;
                delete delCur;
                length--;
            }
        }
        else
        {
            curNow = curNow->next;
        }
    }
}
void task::list::sort()
{
    for (size_t i = 0; i < length; i++)
    {
        Node* curNow = first;
        while (curNow && curNow->next)
        {
            if (curNow->cur > curNow->next->cur)
            {
                std::swap(curNow->cur, curNow->next->cur);
            }
            curNow = curNow->next;
        }
    }
}
void task::list::print()
{
    Node* curNow = first;
    while (curNow)
    {
        std::cout << curNow->cur << " ";
        curNow = curNow->next;
    }
    std::cout << std::endl;
}

