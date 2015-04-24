// Yürek, Engin
// 040100524
// Programming Assignment 2

#ifndef LIST_H
#define LIST_H

using namespace std;

class list{
public:
	struct node {
		
		string data, assignee, date;
		node *next;
	};
	typedef struct node NodePtr;


	NodePtr *head, *current, *temp, *dummy;

	list();
	void add();
	void del();
	void printList();
	void menu();
	void exit();
	void search();

};

#endif
