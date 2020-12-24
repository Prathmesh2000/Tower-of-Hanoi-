#include<iostream>
#include<cmath>
using namespace std;
int i;
void towerOfHanoi(int n, char source, char aux, char destination){
	
	if(n==1){
		i++;
		cout<<i<<") Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
		return;
	}
	
	towerOfHanoi(n-1, source, destination, aux);
	i++;
	cout<<i<<") Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
	towerOfHanoi(n-1, aux, source , destination);
}

int main(){
	
	int n;
	cout<<"Enter the no. of disks : ";
	cin>>n;
	cout<<endl;
	cout<<"Total no of moves allwed :"<<pow(2,n)-1<<endl<<endl;
	towerOfHanoi(n, 'A', 'B', 'C');
	
	return 0;
}
