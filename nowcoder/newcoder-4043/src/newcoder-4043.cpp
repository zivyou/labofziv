//============================================================================
// Name        : newcoder-4043.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//https://www.nowcoder.com/pat/6/problem/4043
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char a[1001];
	int b = 0;
	cin>>a>>b;
	int i = 0;
	int len = 0;
	while (a[i++]){
		len++;
	}
	i = 0;
	int c=a[i]-'0';
	while (a[i] && a[i+1]){
		 if (c < b){
			if (c==0){
				if (a[i+1]-'0' < b) cout<<"0";
			}
			c = c*10+(a[i+1]-'0');
		}
		else{
			cout<<c/b;
			c = c%b;
			if (c==0){
				if (a[i+1]-'0' < b) cout<<"0";
			}
			c = c*10+(a[i+1]-'0');
		}
		i++;
	}
	if (c >= b)
		cout<<c/b;
	c = c%b;
	cout << " ";
	cout<<c<<endl;
	return 0;
}
