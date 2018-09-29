//============================================================================
// Name        : newcoder-4044.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int rea[3];
int reb[3];

int cnta[3]; // B, C ,J
int cntb[3];

void fun(char ia, char ib){
	switch(ia){
		case 'B':
			switch(ib){
				case 'B':
					rea[1]++;
					reb[1]++;
					break;
				case 'C':
					rea[0]++;
					reb[2]++;
					cnta[0]++;
					break;
				case 'J':
					rea[2]++;
					reb[0]++;
					cntb[2]++;
					break;
			}
			break;
		case 'C':
		switch(ib){
			case 'B':
				rea[2]++;
				reb[0]++;
				cntb[0]++;
				break;
			case 'C':
				rea[1]++;
				reb[1]++;
				break;
			case 'J':
				rea[0]++;
				reb[2]++;
				cnta[1]++;
				break;
		}
		break;
		case 'J':
		switch(ib){
			case 'B':
				rea[0]++;
				reb[2]++;
				cnta[2]++;
				break;
			case 'C':
				rea[2]++;
				reb[0]++;
				cntb[1]++;
				break;
			case 'J':
				rea[1]++;
				reb[1]++;
				break;
		}
		break;
	}
}
char max(int *a){
	int t=-1;
	int i = 0;
	int index = -1;
	for (i=0;i<3;i++){
		if (t < a[i]){
			t = a[i];
			index = i;
		}
	}

	if (index == 0) return 'B';
	if (index == 1) return 'C';
	if (index == 2) return 'J';
	return 'F';
}

int main() {
	int N;
	cin>>N;
	int i = 0;
	char ia, ib;
	while (i++<N){
		cin>>ia>>ib;
		fun(ia, ib);
	}
	cout<<rea[0]<<" "<<rea[1]<<" "<<rea[2]<<endl;
	cout<<reb[0]<<" "<<reb[1]<<" "<<reb[2]<<endl;
	cout<<max(cnta)<<" ";
	cout<<max(cntb)<<endl;
	return 0;
}
