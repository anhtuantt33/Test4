#include<iostream> 
using namespace std; 
template <class E> 
struct Node{
    E element; 
    Node<E> * next; 
    Node(E e = E(), Node<E> * n = 0): element(e), next(n){}
}; 

template <class E> 
class SList{
    Node<E> * head; 
    int size;
    int maxSize; 
public: 
    SList (E e){
    head = new int [e];
    size = 0;
  }
    SList(): head(0), size(0){}
    bool isEmpty() const {return size==0;}
    Node<E> * & getLink(int i){
        if (i<0||i>size) throw "Chi so sai\n"; 
        if (!i) return head; 
        Node<E> * v = head; 
        for (int j = 0; j<i-1; j++)
            v = v->next; 
        return v->next; 
    }
    void add (int i, E e){
        if (i<0||i>size) throw "Chi so sai\n"; 
        getLink(i) = new Node<E> (e, getLink(i)); 
        size++; 
    }
    void remove (int i){
        if (i<0||i>=size)throw "Chi so sai\n"; 
        Node<E> * v = getLink(i); 
        getLink(i) = getLink(i+1);
        delete v;  
        size--; 
    }
    int getSize()const {return size; }
    void print () const {
        for (Node<E> * v = head; v; v = v->next) cout << v->element << " "; 
        cout << endl; 
    }
    void clear()
    {
        while(head) remove(0);
    }
    ~SList(){clear();}
    E getElement(int i)
    {
        if (i<0||i>=size) throw "Chi so sai\n"; 
        return getLink(i)-> element;
    }
    void replace(int i,E e)
    {
        if (i<0||i>=size) throw "Chi so sai\n"; 
        getLink(i)-> element =e;
    }
    bool find (E e) const{
        for (Node<E> * v = head; v; v = v->next) if (v->element == e) return true; 
        return false; 
    }
    Node<E>* search (E e) const{
        for (Node<E> * v = head; v; v = v->next) if (v->element == e) return v; 
        return 0; 
    }
    void removeKey(const E e){
      int i = search(e);
      if(i==1)throw "khong tim thay phan tu de xoa";
      remove (i);
  };
  bool isEqual(int i,int j){
    if(i<0 || i>= size||j<0||j>=size) throw "chi so sai";
    return head[i] = head[j];
  };
  void swapList(int i,int j){
    if(i<0 || i>= size||j<0||j>=size) throw "chi so sai";
    E tmp = head[i];
    head[i] = head[j];
    head[j] = tmp;
  };
  int countKey(E e){
    int count = 0;
    for (int i=0;i<size;i++)
    if(head[i] == e)
    count++;
  };
  SList(const SList<E> & r){
    maxSize = r.maxSize;
    size = r.size;
    head = new E[maxSize];
    for(int i=0;i<maxSize;i++)
    head[i]=r.head[i];
  }
  bool isFull(){return size == maxSize;}
  void add3(E e){
    if(isFull()) throw "danh sach day khong the chen them";
    int i = 0;
    for(;i<size;i++)
     if(e<=head[i])
     break;
		for (int j = size; j > i; j--) head[j] = head[j - 1];
		head[i] = e;
		size++;
  }; 
  void remove3(E i) 
	{
		if (isEmpty()==true) throw "Danh sach rong, khong the xoa";
		if (i<0 || i>size - 1) throw "Chi so sai";
		for (int j = i; j < size - 1; j++) head[j] = head[j + 1];
		size--;
	};
  void replace3 (int i,E e){
    if(i<0 || i>=size) throw "chi so sai ";
    remove3(i);
    add3(e);
  }
}; 
int main(){
    SList<int> l; 
    cout << l.isEmpty() << endl; 
    l.add(0, 2); l.print(); 
    l.add(0, 5); l.print(); 
    l.add(0, 7); l.print(); 
    l.remove(2); l.print(); 
    cout << l.getElement(0) << endl; 
    l.replace(0, 20); 
    cout << l.getElement(0) << endl;
    return 0; 
}
