#include"Header.h"
string Name;
string namess;
string nameInTabels ;
string name2 ;
int counter=0;
customer::customer()
{
	name = "";
	gsize = status = 0;
	next = NULL;
}

customer::customer(string name1, int gsize1, int status1)
{
	name = name1;
	gsize = gsize1;
	status = status1;
	next = NULL;
}


waitinglist::waitinglist()
{
	chairnum =50 ;
	totalcustomers = tables = 0;
	head = tail = NULL;
}


waitinglist::waitinglist(int val) 
{
	chairnum = 50;
	totalcustomers = 0;
	tables = 0;
	head = tail = NULL;
}


void waitinglist::change()
{
	customer*temp ;
	temp = head;
	cout << "Enter the name: ";
	cin >> namess;

		while (temp != NULL)
		{
			if (namess == temp->name)
			{
				if (temp->status==2)
				{
					temp->status=1;
					cout << "Your changes have been successfully saved!" << endl ;
					break ;
				}
				else
				{
					temp->status=1;
					cout << "Your changes can't saved!" << endl ;
					break ;
				}
			}
			else if (namess != temp->name)
			{
				temp = temp->next;
			}
		}
	
		if (temp == NULL)
	{
		cout << "Can't found! " << endl;
	}
}      

void waitinglist::whobefore()
{
	string nam;
	customer*tmp;
	tmp = head;
	cout<<"Enter the name: ";
	cin>>nam;

	customer*tmpo;
	tmpo = head;
	bool x=true;

		while (tmpo != NULL)
		{
			if (nam == tmpo->name)
			{
				x=true;
				break;
			}
			else if (nam != tmpo->name)
			{
				tmpo = tmpo->next;
			}
		}
	
		if (tmpo == NULL)
	{
		x=false;
	}
	if (tmp->name == nam)
	{
		cout<<"None Before You!"<<endl;
	}

	else if(x==true)
	{
		do
	{
		cout<<"the name: "<<tmp->name<<endl;
		tmp = tmp->next;
	} while (tmp->name!=nam);

	}
	else if (x==false)
	{
		cout<<"The name doesn't Exist!"<<endl;
	}
	
}


void waitinglist::diplayonstatus()
{
	int status,c=0;
	customer*tmp;
	tmp = head;
	cout<<"Enter the status: ";
	cin>>status;
	if (status!=1 && status!=2)
	{
		cout<<"Please enter correct status!\n"<<endl;
	}
	else
	{
	if (tmp == NULL)
		{
			cout<<"Empty!"<<endl;
		}
	else
	{
		do
		{
			if (tmp->status == status)
			{
				cout<<"The name: "<<tmp->name<<endl;
				cout<<"The number of Group: "<<tmp->gsize<<endl;
			    tmp = tmp->next;
				c++;
			}
			 else
			{
				  tmp=tmp->next;
			 }

		}while (tmp->next!=NULL);
		
		if (tmp->status == status)
			{
				cout<<"The name: "<<tmp->name<<endl;
				cout<<"The number of Group: "<<tmp->gsize<<endl;
			    tmp = tmp->next;
				c++;
			}
			 else
			{
				  tmp=tmp->next;
			 }
		cout<<"Total Customers in this list: "<<c<<endl;
	}
	}

}



void waitinglist::newcustomer()
{

	customer*tmp = new customer;
	cout << "Enter the name: ";  cin >> tmp->name;
	customer*tmpo=new customer;
	tmpo=head ;
	while (tmpo != NULL)
		{
			
			if (tmp->name != tmpo->name)
			{
				tmpo = tmpo->next;
			}
			else if (tmp->name == tmpo->name)
			{
				cout<<"The name already exist!\n " << endl ;
				cout <<"Enter the name: ";  cin >> tmp->name;
				tmpo=head;
			}
			
	}
	
	cout << "Enter The Number of members: ";  cin >> tmp->gsize;
	cout << "Enter the status: ";  cin >> tmp->status;
	while (tmp->status!=1 && tmp->status!=2)
	{
		cout<<"Please enter correct Status! \n";
		cout << "Enter the status: ";  cin >> tmp->status;
	}
	if (head == NULL)            // linkedlist is empty
	{
		head = tail = tmp;
		totalcustomers++;
	}
	else
	{
		tail->next = tmp;
		tail=tail->next;
		totalcustomers++;
	}

}
void waitinglist::removecustomer(string name1)    // IMPREFECTION ---- INCOMPLETE
{
	
	customer *tmpo, *tmp;
	tmpo = head;
	tmp = tmpo->next;
	

		if (tmpo == NULL)
		{
		cout << "Can't found!" << endl;
		}
		else if (tmpo->name == name1)
		{
			head=tmpo->next;
			cout << "Your changes have been successfully saved!" << endl ;
			delete tmpo;
		}
		else{
		do
		{
			if (name1 == tmp->name)
			{
				tmpo->next=tmp->next;
				delete tmp;
				cout << "Your changes have been successfully saved!" << endl ;
				break;
			}
			else if (name1 != tmp->name)
			{
				tmp = tmp->next;
				tmpo = tmpo->next;
			}
		}
		while (tmp != NULL);
		}
		
}
void waitinglist::checktables()	
{
		float c=5.00;                 // Number of chairs
		customer*temp=head;
			cout << "Enter the available tables: "; 
			cin>>tables;
		while (tables>=1 && temp!=NULL)
		{
			int x;
			float y;
			
			
			y=((temp->gsize)/c);
			x=(temp->gsize)/c;
			
			if (tables<y)
			{
				temp=temp->next;
			}
			else if (tables>=y)
		{
				if (x==y)
				{
					tables=tables-x ;			//	 Correct Table!
					cout<<"The name is: ";
					cout<<temp->name<<endl;
					nameInTabels=temp->name ;
					removecustomer(temp->name);
				break ;
				}
				else if (x!=y)
				{
					tables=tables-(x+1);
					cout<<temp->name<<endl;
					removecustomer(temp->name);
		         break ;
				}
		 }
	}
		if (temp==NULL)
		{
			cout << "Empty!" << endl ;
		}
}

void waitinglist::displayall()
{
	int c=0;
	customer *tmp;
	tmp = head;
	if (tmp == NULL)
	{
		cout << "Empty!";
	}
	while (tmp != NULL)
	{
		cout << "The Name: " << tmp->name <<endl; 
		cout << "The Number of members: " << tmp->gsize << endl;
		cout << "The status:  " << tmp->status<<endl;
		c++;
		tmp = tmp->next;
	}
	cout<<"Total Customers: "<<c<<endl;
	cout << endl;
}



void waitinglist::diplaycustomer()

{
	
	customer*tmp;
	tmp = head;
	cout << "Enter the name: ";
	cin >> Name;

		while (tmp != NULL)
		{
			if (Name == tmp->name)
			{
				cout << "The name: " << tmp->name << endl;
				cout << "The Number of members : " << tmp->gsize << endl;
				cout << "The status: " << tmp->status << endl;
				break;
			}
			else if (Name != tmp->name)
			{
				tmp = tmp->next;
			}
		}
	
		if (tmp == NULL)
	{
		cout << "Can't found!" << endl;
	}
}


int main()
{
	int choice;
	string name1 = "";
	int gsize1 = 0;
	int status1 = 0;
	waitinglist mylist;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 );

	cout<<"----------------------------------------------------------\n";
	cout<<"->           Project Restaurant Waiting List            <-\n";
	cout<<"->           *******************************            <-\n";
	cout<<"----------------------------------------------------------\n"<<endl;
	cout << "Note in status:"<<endl<<"1 --> the customer is here."<<endl<<"2 --> the customer not here.\n\n";
	cout << "Select your option.                        \n";
	cout << "-------------------                        \n";
	cout << "(1) Add a new Customer.                    \n";
	cout << "(2) Display information based on Name.     \n";
	cout << "(3) List all Names.                        \n";
	cout << "(4) Change the status.                     \n";
	cout << "(5) Check tables by name.                  \n";
	cout << "(6) Display the List Based on the status.  \n";
	cout << "(7) Who is before? based on name.          \n";
	cout << "(8) Remove Customer Based on name.         \n";
	cout << "(9) Exit.                                  \n";
	
	do
	{
		cout << "\n";
		cout << "Enter your choice --> ";
		cin >> choice;
		if (1 <= choice && choice <= 8)
		{
			switch (choice)
			{
			case 1:
				mylist.newcustomer();
				break;
			case 2:
				mylist.diplaycustomer();
				break;
			case 3:
				mylist.displayall();
				break;
			case 4:
				mylist.change() ;
				break;
			case 5 :
				mylist.checktables();
				break;
			case 6:
				mylist.diplayonstatus();
				break;
			case 7:
				mylist.whobefore();
				break;
			case 8:
				cout<<"Enter the name: ";
				cin>>name2;
				mylist.removecustomer(name2);
				break;
			default:
				cout << "Invalid choice. \n\n";
				break;
			}
		}
		else
		{
			cout << "Invalid choice. \n\n";
		}
		
	}while (choice != 9);


	system("pause");
	return 0;
}
