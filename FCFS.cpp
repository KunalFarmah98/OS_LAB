#include<iostream>
using namespace std;


int waiting_time(int n, int p[], int at[], int bt[] ,int st[],int wt[])
{
	
	int w=0;
	
	for(int i=1; i<n; i++){
		wt[i] = st[i]-at[i];
		w+=wt[i];
	}
	
	return w;
	
}





int main(){
	int n;
	cout<<"\n Enter number of processes: ";
	cin>>n;
	int p[20];
	int at[20];
	int bt[20];
	
	for(int i=0; i<n; i++){
		p[i]==i+1; // process number
		cout<<"\n Enter Arrival time and Burst Time of process"<<i+1;
		cin>>at[i]>>bt[i];
	}
	
	int wt[n];
	wt[0]=0; //frst process starts instantly
	int ct[n+1];
	ct[0]=bt[0]; // first process completes instantly
	
	int st[n];
	st[0]=0;
	

	for(int i=1; i<n; i++){
		ct[i]=ct[i-1]+bt[i];
	}
	
		for(int i=1; i<n; i++){
		st[i] = ct[i-1]; 
	}
	
	// setting waiting time for all processes;
	int waitTime = waiting_time(n,p,at,bt,st,wt);
	
	int ta[n];
	int ta_=0;
	for(int i=0; i<n; i++){
		ta[i]=bt[i]+wt[i];
		ta_+=ta[i];
	}
	
	
	cout<<"\n Turn Arround Time is: "<<ta_<<endl;
	cout<<"\n Waiting Time is: "<<waitTime<<endl;

	
	
	
	
}

