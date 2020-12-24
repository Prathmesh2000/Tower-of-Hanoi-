#include<iostream>
#include<cmath>
using namespace std;

int  step_count=0;

class Stack{
	public:
		int top;
		int capacity;
		int* array;
		
		void initilize(unsigned i);
		int isOverflow(Stack* stack);	
		int isEmpty(Stack* stack);
		void push(Stack* stack, int item);
	    int pop(Stack* stack);
};

void Stack::initilize(unsigned i){
			top = -1;
			capacity = i;
			array = new int[capacity*sizeof(int)];
			return;  
		}

int Stack::isOverflow(Stack* stack){
	return(stack->top > stack->capacity -1); 
}

int Stack::isEmpty(Stack* stack){
	return(stack->top == -1);
}

void Stack::push(Stack* stack, int item){
	if(stack->isOverflow(stack)){
		return;
	}
	stack->array[++stack->top] = item;
}

int Stack::pop(Stack* stack){
	if(stack->isEmpty(stack)){
		return INT_MIN;
	}
	return stack->array[stack->top--];
}

void print(char src, char dest, int disk){
	
	cout<<"Step-"<<++step_count<<" Move disk "<<disk<<" from "<<src<<" to "<<dest<<endl;
}

void movement_Of_Disk(Stack* source, Stack* destination, char s, char d){
	
	int pole1_Top_Disk = source->pop(source);
	int pole2_Top_Disk = destination->pop(destination);
	
	if(pole1_Top_Disk == INT_MIN){
		source->push(source, pole2_Top_Disk);
		print(d, s, pole2_Top_Disk);
	}
	
	else if(pole2_Top_Disk == INT_MIN){
		destination->push(destination, pole1_Top_Disk);
		print(s, d, pole1_Top_Disk);
	}
	
	else if(pole1_Top_Disk > pole2_Top_Disk){
		source->push(source, pole1_Top_Disk);
		source->push(source, pole2_Top_Disk);
		print(d, s, pole2_Top_Disk);
	}
	
	else{
		destination->push(destination, pole2_Top_Disk);
		destination->push(destination, pole1_Top_Disk);
		print(s, d, pole1_Top_Disk);
	}
}

void itration(int n, Stack* src, Stack* aux, Stack* dest){
	char source = 'A', auxilary = 'B', destination = 'C';
	int total_moves = pow(2,n)-1;
	
	for(int i=n;i>=1;i--){
		src->push(src,i);
	}
	
	if(n%2 == 0){
		char temp = destination;
		destination = auxilary;
		auxilary = temp;
	}
	
	for(int i=1;i<=total_moves;i++){
		if(i%3==1){
			movement_Of_Disk(src, dest, source, destination);
		}
		if(i%3==2){
			movement_Of_Disk(src, aux, source, auxilary);
		}
		if(i%3==0){
			movement_Of_Disk(aux, dest, auxilary, destination);
		}
	}
}

int main(){
	
	Stack source, aux, destination;
	int n;
	cout<<"Enter the no disks: ";
	cin>>n;
	cout<<endl;
	cout<<"Total no. of moves allowed: "<<pow(2,n)-1<<endl<<endl;
	source.initilize(n);
	aux.initilize(n);
	destination.initilize(n);
	
	itration(n, &source, &aux, &destination);
	
	return 0;
}
