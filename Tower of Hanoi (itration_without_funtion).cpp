#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	int n, total_moves;
	char source = 'A', aux = 'B', destination = 'C';
	cout<<"Enter the number of disk: ";
	cin>>n;
	total_moves = pow(2,n)-1;
	cout<<total_moves<<"\n";
	
	if(n%2==0){
		char temp = aux;
		aux = destination;
		destination = temp;
	}
	
	for(int i=1;i<=total_moves;i++){
		if(i%3==1){
			cout<<"legal movement of top disk between "<<source<<" to "<<destination<<endl;
		}
		if(i%3==2){
			cout<<"legal movement of top disk between "<<source<<" to "<<aux<<endl;
		}
		if(i%3==0){
			cout<<"legal movement of top disk between "<<aux<<" to "<<destination<<endl;
		}
	}
	return 0;
}
