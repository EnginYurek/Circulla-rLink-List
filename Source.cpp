// Yürek, Engin
// 040100524
// Programming Assignment 2

#include <cstdlib>
#include <iostream>
#include "List.h"
#include<string>

using namespace std;

list::list(){			//constructor
	head = NULL;
	current = NULL;
	temp = NULL;	
}
void list::add(){							//ALFABETİK OLARAK EKLİCEKMİŞ DÜZENLEMEYİ UNUTMAAA!!!
	string addTask, addAssignee, addDate;
	NodePtr *newNode = new NodePtr;
	
	//entering the data of the tasks
	cout << "Enter the name of the task:\n"<<"<<";
	getline(cin, addTask);			// compailer doesnt detect the first getline function, ı dont understan why. ı had to put it twice
	getline(cin, addTask);
	cout << "Enter the assignee name for the task:\n" << "<<";
	getline(cin, addAssignee);
	cout << "Enter the deadline for the task:\n" << "<<";
	getline(cin, addDate);
	cout << "\n";

	//assignt data to the new node
	newNode->data = addTask;
	newNode->assignee = addAssignee;
	newNode->date = addDate;
	newNode->next = NULL;

	if (head != NULL){
		
		current = head;
		
		while (current->next != head){			//finding the last node
			current = current->next;
		}
		current->next = newNode;
		dummy = newNode;
		dummy->next = head;				//  we make the list, circular
	}
	else               //here will work if the list is empty
	{
		head = newNode;
		dummy = newNode;
		head->next=head;
	}


}
void list::printList(){
	int i = 1;
	current = head;
	if (head == NULL){
		cout << "List is empty\n\n";
	}
	else
	{
		do
		{
			cout << i << "-";
			cout << current->data << endl;
			cout << current->assignee << endl;
			cout << current->date << endl << endl;
			current = current->next;
			i++;
		} while (current != dummy->next);
	}
}

void list::del(){						//tüm liste silindikten sonra tekrar işlem(ekleme, listeleme etc.) yapılamıyor hata veriyor
	NodePtr *delPtr;
	delPtr = NULL;
	int ID;
	cout << "These tasks exist in the list:\n";
	printList();
	cout << "Choose the ID of the task you want to remove:\n";
	cin >> ID;
	if (head == NULL){
		cout << "List does not includes any task.\n";
	}
	else
	if (ID == 1){
		delPtr = head;
		head = head->next;
		delete delPtr;
		dummy->next = head;
	}
	else
	{
		current = head;
		
		for (int k = 1; k <= ID - 1; k++){
			temp = current;
			current = current->next;
		}
		if (current == dummy){
			dummy = temp;
			dummy->next = head;
		}
		delPtr = current;
		current = current->next;
		temp->next = current;

		delete delPtr;
	}
	cout << "The task has been removed from the list.\n\n";
}
void list::menu(){

	cout << "Choose an operation\n"
		<< "A: Add Task\n"
		<< "S: Search for Task\n"
		<< "L: List All Tasks\n"
		<< "R: Remove Task\n"
		<< "E: Exit\n\n"<<"<<";

}

void list::search(){
	string searchTask;
	NodePtr *search;
	search = head;

	cout << "To search for a task, enter its task name or assignee name:\n" << "<<";
	getline(cin, searchTask);
	getline(cin, searchTask);
	do{//bu satır problemli gibi gözüküyor

		if (search->data == searchTask || search->assignee == searchTask){
			cout << search->data << endl << endl
				<< search->assignee << endl<<endl
				<< search->date << endl << endl;
		}
		search = search->next;
	} while (search != dummy->next);
	

}

void list::exit(){
	node *delPtr;
	current = head;
	if (head != NULL){

		do{
			temp = current;
			delPtr = temp;
			current = current->next;

			delete delPtr;
		} while (current != dummy);
	}
}


