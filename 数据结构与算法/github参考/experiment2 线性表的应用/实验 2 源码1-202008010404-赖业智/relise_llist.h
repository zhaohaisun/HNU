#pragma once
#include <iostream>
#include "llist.h"
#include <assert.h>
using namespace std;

template  <typename  E>  class  Link {
public:
    E  element;            //  Value  for  this  node
    Link* next;                //  Pointer  to  next  node  in  list
    //  Constructors
    Link(const  E& elemval, Link* nextval = NULL) {
        element = elemval;
        next = nextval;
    }
    Link(Link* nextval = NULL) {
        next = nextval;
    }
};

template  <typename  E>  class  LList : public  List<E> {
private:
    Link<E>* head;              //  Pointer  to  list  header
    Link<E>* tail;              //  Pointer  to  last  element
    Link<E>* curr;              //  Access  to  current  element
    int  cnt;                              //  Size  of  list
    void  init() {                //  Intialization  helper  method
        curr = head = tail = new Link<E>;
        cnt = 0;
    }

    void  removeall() {      //  Return  link  nodes  to  free  store
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList(int  size = 100) {
        init();        //  Constructor
    }
    ~LList() {
        removeall();        //  Destructor
    }

    // 使用空格分隔输出线性表中的所有数据，并最终换行
    //无数据时直接输出空行
    void  print() {
        Link<E>* cur = head->next;
        if (head == NULL) { cout << endl; }
        for (int i = 0; i < cnt; i++) {
            cout << cur->element << " ";
            cur = cur->next;
        }
        cout << endl;
        return;
    }

    void  clear() {
        removeall();        //  Clear  list
        init();
    }

    //  Insert  "it"  at  current  position
    void  insert(const  E& it) {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next;
        cnt++;
    }

    void  append(const  E& it) {  //  Append  "it"  to  list
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }

    //  Remove  and  return  current  element
    E  remove() {
        assert(curr->next != NULL);  //如当前元素不存在，将直接报错，并终止程序
        E it = curr->next->element;
        Link<E>* temp = curr->next;
        if (tail == curr->next) tail = curr;
        curr->next = curr->next->next;
        delete temp;
        cnt--;
        return it;

    }

    //  Place  curr  at  list  start
    void  moveToStart() {
        curr = head;
    }

    //  Place  curr  at  list  end
    void  moveToEnd() {
        curr = tail;
    }

    //  Move  curr  one  step  left;  no  change  if  already  at  front
    void  prev() {
        if (curr = head) return;
        Link<E>* ltemp = head;
        while (ltemp->next != curr) {
            ltemp = ltemp->next;
        }
        curr = ltemp;
    }

    //  Move  curr  one  step  right;  no  change  if  already  at  end
    void  next() {
        if (curr != tail) curr = curr->next;
    }

    //  Return  length
    int  length()  const {
        return cnt;
    }

    //  Return  the  position  of  the  current  element
    int  currPos()  const {
        Link<E>* temp = head;
        int i;
        for (i = 0; curr != temp; i++) {
            temp = temp->next;
        }
        return i;
    }

    //  Move  down  list  to  "pos"  position
    void  moveToPos(int  pos) {
        assert((pos >= 0) && (pos <= cnt));
        curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;
    }

    //  Return  current  element
    const  E& getValue()  const {
        assert(curr->next != NULL);
        return curr->next->element;
    }
};
