#include <iostream>

using namespace std;


class stackOverFlowException{

    int size;
    public:
        stackOverFlowException(int size){
            this->size=size;
        }
        void print(){
            cout<<"All size are allocated = "<<size<<endl;

        }
};
class stackEmptyException{};

template < class T>
class Stack {

    T* ptr;
    int size;
    int allocsize;

    public:
    Stack(const Stack & another){
        size = another.size;
        allocsize = another.allocsize;
        for(int i=0 ; i<allocsize ; i++){
            ptr[i]= another.ptr[i];
        }

    }
    Stack operator=(Stack &another){
        if(*this!=another){
            this->size = another.size;
            this->allocsize = another.allocsize;
            for(int i=0 ; i<allocsize ; i++){
            this->ptr[i]= another.ptr[i];
            }

        }
        return *this;
    }
    Stack(int size1){
        ptr = new T [size1];
        size = size1;
    }
    void push(T value){
        try{
            if(allocsize==size)
            throw stackOverFlowException(size);
            if(allocsize==0){
                ptr[0]=value;
            }
            else{
                ptr[allocsize]=value;
            }
            allocsize++;

        }
        catch(stackOverFlowException s){
            s.print();
        }
    }
    T Top(){
        return ptr[allocsize-1];
    }
    void pop(){
        try {
            if(allocsize==0)
            throw stackEmptyException();
            allocsize--;
        }
        catch(stackEmptyException s ){
            cout<<"stack is empty"<<endl;
        }

    }
    int Size(){
        return allocsize;
    }
    bool empty(){
        if(allocsize==0){
            return true;
        }
    }
    ~Stack(){
        delete [] ptr;
    }
    void printStack(){
        for(int i=allocsize-1 ;  i>=0; i--){
            cout<<ptr[i]<<endl;

        }
    }

};



void manageStack(){
    int size , choose=1 , value;
    cout<<"enter size number of stack"<<endl;
    cin>>size;
    Stack<int> s(size);
    cout<<"1- push "<<endl;
    cout<<"2- pop "<<endl;
    cout<<"3- Top "<<endl;
    cout<<"4- Exit"<<endl;


    while(choose>0 && choose<4){
        cout<<"enter choose from above"<<endl;
        cin>>choose;
        if(choose==1){
            cout<<"enter the elemnt to push to stack"<<endl;
            cin>>value;
            s.push(value);
        }
        else if(choose==2){
            s.pop();
        }
        else if(choose==3){
            cout<<"The Top is : ";
            cout<<s.Top()<<endl;
        }
        cout<<"Stack content"<<endl;
        s.printStack();

       
    }
    


}



int main(){
    manageStack();
}
