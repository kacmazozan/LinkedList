#include <iostream>
using namespace std;


template<class object>
class ListNode;


template<class T>
class List;




template<class object>
class ListNode {

private:
    object element;
    ListNode * next;

    ListNode(const object & obj = object(), ListNode* n = nullptr): element{obj}, next{n} {}

    friend class List<object>;

};

template<class type>
class ListItr {
private:
    ListNode<type> * current;

    ListItr( ListNode<type> * object): current{object}{}

    friend class List<type>;
public:
    ListItr() : current{nullptr}{}

    bool isPastEnd() {
        return current == nullptr;
    }
    void advance() {
        if (!isPastEnd()) {
            current = current->next;
        }
    }
    type & retrieve() const {
        if (!isPastEnd()) {
            return current->element;
        }
        else {
            throw std::exception() ;
        }
    }
    type & retrieveNext() const {
        if (!isPastEnd()) {
            return current->next->element;
        }
        else {
            throw std::exception() ;
        }
    }
};

template<class T>
class List {
private:
    ListNode<T> * head ;
public:
    List(): head{new ListNode<T>()}{}

    bool isEmpty() {
        return head->next == nullptr;
    }
    void insertAfter( const T & obj , const ListItr<T> & itr) {
        if (itr.current != nullptr) {
            itr.current->next = new ListNode<T>(obj,itr.current->next);
        }
    }
    void insertBefore(const T & obj, const ListItr<T> & itr) {
        ListItr<T> itrPrev(head);
        while (itrPrev.current && itrPrev.current->next != itr.current) {
            itrPrev.advance();
        }
        itrPrev.current->next= new ListNode<T>(obj,itrPrev.current->next);
    }
    ListItr<T> find(const T & x) {
        ListItr<T> itr(head->next);
        while ( ! itr.isPastEnd() && itr.retrieve() != x) {
            itr.advance();
        }
        return itr;
    }
    ListItr<T> findPrevious(const T & x) {
        ListItr<T> itr(head);
        while (itr.current->next && itr.retrieveNext() != x ) {
            itr.advance();
        }
        return itr;
    }
};







int main() {
    cout <<"hello";
    return 0;
}