#include<bits/stdc++.h>
using  namespace  std;

//断言工具函数：如果val为假则输出s然后中断程序
void  Assert(bool  val,string  s){
        if(!val){
                cout<<"断言失败："<<s<<endl;
        }
}

template  <typename  E>  class  List  {  //  List  ADT
private:
        void  operator  =(const  List&)  {}            //  Protect  assignment
        List(const  List&)  {}                      //  Protect  copy  constructor
public:
        List()  {}                    //  Default  constructor
        virtual  ~List()  {}  //  Base  destructor

        //  Clear  contents  from  the  list,  to  make  it  empty.
        virtual  void  clear()  =  0;

        //  Insert  an  element  at  the  current  location.
        //  item:  The  element  to  be  inserted
        virtual  void  insert(const  E&  item)  =  0;

        //  Append  an  element  at  the  end  of  the  list.
        //  item:  The  element  to  be  appended.
        virtual  void  append(const  E&  item)  =  0;

        //  Remove  and  return  the  current  element.
        //  Return:  the  element  that  was  removed.
        virtual  E  remove()  =  0;

        //  Set  the  current  position  to  the  start  of  the  list
        virtual  void  moveToStart()  =  0;

        //  Set  the  current  position  to  the  end  of  the  list
        virtual  void  moveToEnd()  =  0;

        //  Move  the  current  position  one  step  left.  No  change
        //  if  already  at  beginning.
        virtual  void  prev()  =  0;

        //  Move  the  current  position  one  step  right.  No  change
        //  if  already  at  end.
        virtual  void  next()  =  0;

        //  Return:  The  number  of  elements  in  the  list.
        virtual  int  length()  const  =  0;

        //  Return:  The  position  of  the  current  element.
        virtual  int  currPos()  const  =  0;

        //  Set  current  position.
        //  pos:  The  position  to  make  current.
        virtual  void  moveToPos(int  pos)  =  0;

        //  Return:  The  current  element.
        virtual  const  E&  getValue()  const  =  0;
};

//  Singly  linked  list  node
template  <typename  E>  class  Link  {
public:
        E  element;            //  Value  for  this  node
        Link  *next;                //  Pointer  to  next  node  in  list
        //  Constructors
        Link(const  E&  elemval,  Link*  nextval  =NULL)  {
                
element = elemval;
next = nextval;

        }
        Link(Link*  nextval  =NULL)  {
                
next = nextval;

        }
};

template  <typename  E>  class  LList:  public  List<E>  {
private:
        Link<E>*  head;              //  Pointer  to  list  header
        Link<E>*  tail;              //  Pointer  to  last  element
        Link<E>*  curr;              //  Access  to  current  element
        int  cnt;                              //  Size  of  list

        void  init()  {                //  Intialization  helper  method
                    
curr = head = tail = new Link<E>;
cnt = 0;

        }

        void  removeall()  {      //  Return  link  nodes  to  free  store
                    
while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
}

        }

public:
        LList(int  size=100)  {
                init();        //  Constructor
        }
        ~LList()  {
                removeall();        //  Destructor
        }

        //  使用空格分隔输出线性表中的所有数据，并最终换行
        //无数据时直接输出空行
        void  print(){
                
Link<E>* cur = head->next;
for (int i = 0; i < cnt; i++) {
        cout << cur->element << " ";
        cur = cur->next;
}
cout << endl;

        }

        void  clear()  {
                removeall();        //  Clear  list
                init();
        }

        //  Insert  "it"  at  current  position
        void  insert(const  E&  it)  {
                
curr->next = new Link<E>(it, curr->next);
if (tail == curr) tail = curr->next;
cnt++;

        }

        void  append(const  E&  it)  {  //  Append  "it"  to  list
                
tail = tail->next = new Link<E>(it, NULL);
cnt++;

        }

        //  Remove  and  return  current  element
        E  remove()  {
                Assert(curr->next  !=  NULL,  "No  element");  //如当前元素不存在，将直接报错，并终止程序
                
E it = curr->next->element;
if (tail == curr->next) tail = curr;
else curr->next = curr->next->next;
cnt--;
return it;

        }

        //  Place  curr  at  list  start
        void  moveToStart()  {
                
curr = head;

        }

        //  Place  curr  at  list  end
        void  moveToEnd()  {
                
curr = tail;

        }

        //  Move  curr  one  step  left;  no  change  if  already  at  front
        void  prev()  {
                
if (curr = head) return;
Link<E>* ltemp = head;
while (ltemp->next != curr) {
ltemp = ltemp->next;
}
curr = ltemp;
delete ltemp;

        }

        //  Move  curr  one  step  right;  no  change  if  already  at  end
        void  next()  {
                
if (curr != tail) curr = curr->next;

        }

        //  Return  length
        int  length()  const    {
                
return cnt;

        }

        //  Return  the  position  of  the  current  element
        int  currPos()  const  {
                
Link<E>* temp = head;
int i=0;
while (curr != temp) {
        i++;
        temp = temp->next;
}
return i;

        }

        //  Move  down  list  to  "pos"  position
        void  moveToPos(int  pos)  {
                Assert  ((pos>=0)&&(pos<=cnt),  "Position  out  of  range");
                
curr = head;
for (int i = 0; i < pos; i++) curr = curr->next;
//  Move  curr  to  "pos"  position

        }

        //  Return  current  element
        const  E&  getValue()  const  {
                Assert(curr->next  !=  NULL,  "No  value");
                
return curr->next->element;

        }
};


//读取测试指令，进行测试
void  test(LList<int>  &llist)  {
        int  act;
        int  pos,value;
        do  {
                //读取指令  指令说明：1  插入  2  删除  3  获取值  4  查找
                cin>>act;
                switch(act)  {
                case  1://在pos位置插入值value
                        cin>>pos>>value;
                        llist.moveToPos(pos);
                        llist.insert(value);
                        llist.print();
                        break;
                case  2://删除pos位置的元素
                        cin>>pos;
                        llist.moveToPos(pos);
                        llist.remove();
                        llist.print();
                        break;
                case  3://获取指定位置的值
                        cin>>pos;
                        llist.moveToPos(pos);
                        cout<<llist.getValue()<<endl;
                        break;
                case  4://查询特定值所在位置，如果存在输出位置，否则不输出
                        cin>>value;
                        for(llist.moveToStart();  llist.currPos()<llist.length();  llist.next())  {
                                if(llist.getValue()==value)  {
                                        cout<<llist.currPos()<<endl;
                                        break;
                                }
                        }
                        break;
                case  0:
                        return;
                }
        }  while(true);
}

int  main()  {
        LList  <int>llist;
        test(llist);//测试
        return  0;
}
