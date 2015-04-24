// Yürek, Engin
// 040100524
// Programming Assignment 2


#include <cstdlib>
#include <iostream>
#include "List.h"
#include<string>
using namespace std;

int main(){

	
	char operation;
	list tasks;
	tasks.menu();
	

	cin >> operation;

	while (operation!='E' && operation!='e'){
		
		switch (operation)
		{
		case 'A':case'a':
			tasks.add();
			break;
		case 'S': case's':
			tasks.search();
			break;
		case 'L': case 'l': 
			cout << "All tasks are listed below:\n";
			tasks.printList();
			break;
		case 'R': case 'r':
			tasks.del();
			break;
		default:
			cout << "Please choose an appropriate operation\n\n";
			break;
		}
		tasks.menu();
		cin >> operation;

		
		
	}

	tasks.exit();
	return 0;
}


