#include<iostream>
using namespace std;

class Node
{
	int data;
	Node *left, *right;
public:
	//Getters
	int getData(){return data;}
	Node* getLeft(){return left;}
	Node* getRight(){return right;}
	//Setters
	void setData(int data){this->data = data;}
	void setLeft(Node *left){this->left = left;}
	void setRight(Node *right){this->right = right;}
	//Insert
	void Insert(Node **head, Node* newNode);
	//Print
	void Print_Inorder(Node* head);
};

void Node::Insert(Node **head, Node* newNode)
{
	Node *parent = *head;
	Node *start = *head;

	if((*head)==NULL)
	{
		(*head) = newNode;
		return;
	}
	else
	{
		while((*head)!=NULL)
		{
			if(newNode->getData() > (*head)->getData())
			{
				parent = *head;
				*head = (*head)->getRight();
			}
			else if(newNode->getData() < (*head)->getData())
			{
				parent = *head;
				*head = (*head)->getLeft();
			}
			else
			{
				*head = start;
				return;
			}
		}
		if(newNode->getData() < parent->getData())
			parent->setLeft(newNode);
		else
			parent->setRight(newNode);
	}
	*head = start;
}

void Node::Print_Inorder(Node* head)
{
	if(head)
	{
		Print_Inorder(head->getLeft());
		cout<<head->getData()<<" ";
		Print_Inorder(head->getRight());
	}
}

int main()
{
	Node *head = NULL;
	Node *newNode=NULL;
	Node *start= new Node;
	int choice=0;
	int data;
	do
	{
		cout<<"1. Insert data\n2. Quit\n"; 
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1: 
			cout<<"Enter data to insert : ";
			cin>>data;
			newNode = new Node;
			newNode->setData(data);
			newNode->setLeft(NULL);
			newNode->setRight(NULL);
			start->Insert(&head, newNode);
			break;
		case 2:
			break;
		default:
			cout<<"Wrong choice. Enter value 1 or 2\n";
			break;
		}
		
	}while(choice != 2);
	
	cout<<"\nData in sorted order: ";
	start->Print_Inorder(head);
	return 0;
}