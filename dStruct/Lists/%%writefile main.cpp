%%writefile main.cpp
#include <iostream>
#include <cstdio>

class Node{
  public:
    int data;
    Node* next;

    Node(int d){
      data = d;
      next = NULL;
    };
};

class List{
  protected:
    Node* head;
    Node* last;

  public:
    List(){
      head = NULL;
      last = NULL;
    };

    ~List(){
      while(!isEmpty()){
        Node* aux = head;
        head = head->next;
        delete aux;
      };
    };

    void append(int data){
      if(isEmpty()){
        head = new Node(data);
        last = head;
      }else{
        Node* aux = new Node(data);
        last->next = aux;
        last = aux;
      };
    };

    bool isEmpty(){
      return head==NULL;
    };

    bool insert(int pos, int data){
      if(pos==0){
        if(isEmpty()){
          head = new Node(data);
          last = head;
        }else{
          Node * aux = new Node(data);
          aux->next = head;
          head = aux;
        };
        return true;
      }else{};
    };

    bool removeFirst(){
      if(!isEmpty()){
        Node * aux = head;
        head = head->next;
        delete aux;
        if(isEmpty()){
          last = NULL;
        };
        return true;
      };
      return false;
    };

    bool removeLast(){
      if(!isEmpty()){
        if(head==last){
          delete head;
          head = NULL;
          last = NULL;
        }else{
          Node* aux = head;
          while(aux->next!=last){
            aux = aux->next;
          };
          delete last;
          last = aux;
          last->next = NULL;
        };
        return true;
      }
      return false;
    };

    int get( int index ){
      Node* a = head;
      while(index>0 && a!=NULL){
        index--;
        a = a->next;
      };
      if(a!=NULL)
        return a->data;
      throw -1;
    };

    void invert(){
      if(!isEmpty() && head != last ){
        Node* a = head;
        Node* n = NULL;
        Node* p = NULL;
        while(a != NULL){
          n = a->next;
          a->next = p;
          p = a;
          a = n;
        };
        a = head;
        head = last;
        last = a;
      };
    };


  void invertV2(){
      Node* aux;
      
      Node* RealLast = last;

      while(head != RealLast){
          aux = head;
          aux->next = RealLast->next;
          RealLast->next = aux;
          head = head->next;

      }
      last = aux;
      
  }


    void print(std::ostream& os){
      Node* a=head;
      while(a!=NULL){
        os << a->data << ',';
        a = a->next;
      };
    };
};

std::ostream& operator<< (std::ostream& os, List& l){
  l.print(os);
  return os;
};


int main(){
  List l;
  for(int i=0; i<10; i++){
    int x;
    //std::cout << "Ingrese dato:";
    //std::cin >> x;
    l.append(i);
  };
  for(int i = 0; i<10;i++){
  std::cout << l.get(i) << ' '<<std::endl;
  
}
  //l.invert();
l.invertV2();
for(int i = 0; i<10;i++){
  std::cout << l.get(i) << ' '<<std::endl;
  
}
  std::cout << l<<std::endl;
};