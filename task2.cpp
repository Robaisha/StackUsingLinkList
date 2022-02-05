#include<iostream>
using namespace std;
class node{
	int data;
	node *next;
	public:
		node *top;
		int i;
		int arr[4];
		node(){
			top=NULL;
			next=NULL;
			i=0;
		}
		int storepush(){
			arr[i]=top->data;
			i++;
		}
		void push(int data){              //add node
			node* temp;
			temp = new node;
			if (!temp)
			{
				//cout<<"\nStack Overflow\n";
				exit(1);
			}
			temp->data = data;
			temp->next = top;
			top = temp;
			storepush();
			cout<<temp->data<<" is pushed on stack\n";
        }
		int pop(){                      //delete nodes
		    if(top==NULL){
		    	cout<<"Stack underflow\n";
		    	return false;
			}
			else{
				node *temp=new node;
				temp=top;
				top=top->next;
				temp->next=NULL;
				delete(temp);
				return top->data;
			}
		}
		void display(){
			node *temp=top;
			if(top==NULL){
				cout<<"Stack underflow\n";
			}
			else{
				while(temp!=NULL){
					cout<<temp->data;
					if(temp->next!=NULL){
						cout<<"->";
					}
					temp=temp->next;
				}
		    }
		}
		int peek(){
			if(isempty()){
				cout<<"\nStack is empty\n";
			}
			else{
				return top->data;
			}
		}
		bool isempty(){
			if(top==NULL){
				return true;
			}
			else{
				return false;
			}
		}
};
int main(){
	node obj;
	int x=0;
	obj.push(11);
	obj.push(10);
	obj.push(9);
	obj.push(8);
	cout<<endl;
	cout<<"Forward Direction: ";
	obj.display();
	cout<<"\nBackward direction: ";
	for(int i=0;i<4;i++){
		if(i==3){
			cout<<obj.arr[i];
		}
		else{
			cout<<obj.arr[i]<<"->";
	    }
	}
	for(int i=0;i<4;i++){
		obj.pop();
	}
}
