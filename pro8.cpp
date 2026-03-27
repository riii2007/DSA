#include<iostream>
using namespace std;

class Stack{
    int arr[10];
    int size;
    int top;
    public:
    Stack(int x){
        size=x;
        top=-1;
    }
    virtual void push(int value){
        if(top==size-1){
            cout<<"Stack is FULL\n";
            return;
        }
        arr[++top]=value;
        cout<<value<<" pushed into stack\n";
    }
    virtual void pop(){
        if(top==-1){
            cout<<"Stack is EMPTY\n";
            return;
        }
        cout<<arr[top--]<<" popped from stack\n";
    }
    virtual int topElement(){
        if(top==-1){
            cout<<"Stack is EMPTY\n";
            return -1;
        }
        return arr[top];
    }
    virtual bool isEmpty(){
        return top==-1;
    }
    virtual bool isFull(){
        return top==size-1;
    }
};
class StackDerived:public Stack{
    public:
    StackDerived(int x):Stack(x){}
    void push(int value) override{
        Stack::push(value);
    }
    void pop() override{
        Stack::pop();
    }
    int topElement() override{
        return Stack::topElement();
    }
    bool isEmpty() override{
        return Stack::isEmpty();
    }
    bool isFull() override{
        return Stack::isFull();
    }
};
int main(){
  int size;
    cout<<"Enter stack size: ";
    cin>>size;

    StackDerived stack(size);
    int choice, value;
    do{
        cout<<"\n1. Push\n2. Pop\n3. Top Element\n4. Check if Empty\n5. Check if Full\n6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout<<"Top element: "<<stack.topElement()<<endl;
                break;
            case 4:
                cout<<"Stack is "<<(stack.isEmpty() ? "Empty" : "Not Empty")<<endl;
                break;
            case 5:
                cout<<"Stack is "<<(stack.isFull() ? "Full" : "Not Full")<<endl;
                break;
            case 6:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    }while(choice!=6);
}