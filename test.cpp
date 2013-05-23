#include <iostream>
#include <string>
#include <vector>
using namespace std;

class simulate_dfa
{

	public:
	int start_state, end_state; 
	int state;
	string str;
	void enter_state_information();
	void simulate();
};


void simulate_dfa::simulate()
{
int a=0;
int c;

cout<<"\nThe states through which the machine goes form starting state are:\n";
cout<<"A";
while(a!=(int)str.length())
{

	switch(state)
	{
		case 1:
			c = str[a]-'0';
			if(c==0) {state =2;cout<<"\tB";}			
			else if(c==1) {state =1;cout<<"\tA";}
			else if(c==2) {state =2;cout<<"\tB";}
			break;
		case 2:
			c = str[a]-'0';
			if(c==0) {state =5;cout<<"\tE";}			
			else if(c==1) {state =1;cout<<"\tA";}
			else if(c==2) {state =3;cout<<"\tC";}
			break;
		case 3:
			c = str[a]-'0';
			if(c==0) {state =1;cout<<"\tA";}			
			else if(c==1) {state =5;cout<<"\tE";}
			else if(c==2) {state =4;cout<<"\tD";}
			break;
		case 4:
			c = str[a]-'0';
			if(c==0) {state =3; cout<<"\tC";}		
			else if(c==1) {state =4;cout<<"\tD";}
			else if(c==2) {state =5;cout<<"\tE";}
			break;
		case 5:
			c = str[a]-'0';
			if(c==0) {state =5;cout<<"\tE";}		
			else if(c==1) {state =4;cout<<"\tD";}
			else if(c==2) {state =1;cout<<"\tA";}
			break;
	}
	a++;
}
	if(state==5)
	cout<<"\nString is accepted";
	else
	cout<<"\nString not accepted";


}
void simulate_dfa::enter_state_information()
{
	cout<<"\nEnter the start state and end state:\n";
	cin>>start_state>>end_state;
	state=start_state;                                          
	cout<<"\nEnter the input string:\n";
	cin>>str;
	
}

int main()
{
	cout<<"aa\n";
	
	/*
	typedef int array[10];
	
	array a;
	array b[5];
	
	for(int j = 0;j<5;j++)
	{
	for(int i = 0; i<10;i++)
	{
		
		b[j][i]= i;
		
		cout<<b[j][i]<<endl;
		
	}
	}*/
	
	int (*p)[10];
	
		//for(int i = 0; i<10;i++)
	{
		
		(*p)[2] = 2;
		
		cout<<(*p)[2]<<endl;
	}
	
	
	/*vector<int *> a;
	int u =9;
	int ** v = new int* [5]();
	//v=&u
	for(int i = 0; i<5;i++)
	{
		 
	     a.push_back(v[i]);
	}
	
	for(vector<int*>::iterator it = a.begin(); it!=a.end(); ++it)
	{
		cout<<*(*it)<<" ";
		
	}*/
/*
int** a = new int*[5]();//bracket for making all elements to zero
for(int i = 0;i<5;i++)
{
	a[i] = new int [10];
 //array of pointers to pointers

for(int i = 0; i<5;i++)
{
	for(int j = 0; j<10;j++)
	cin>>a[i][j];
	
	cout<<endl;
}}*/

return 0;
}
