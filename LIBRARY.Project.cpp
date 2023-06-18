// Library Management System
#include<iostream>
#include<conio.h>
using namespace std;

class Library
{
private:
    struct Node
    {
        int id;
        string name,author, publisher;
        Node *next_add;
    };
public:
    Node *head;
    Library()
    {
        head = NULL;
    }
    void menu();
    void insert_record();
    void search();
    void update();
    void del_record();
    void show();
};



void Library::menu()
{
p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t==============================================================";
    cout<<"\n\n\t\t\t=================LIBRARY MANAGEMENT SYSTEM====================";
    cout<<"\n\n\t\t\t==============================================================";
    cout<<"\n\n 1. Insert New Record ";
    cout<<"\n\n 2. Search Record ";
    cout<<"\n\n 3. Update Record ";
    cout<<"\n\n 4. Delete Record ";
    cout<<"\n\n 5.Show all Record ";
    cout<<"\n\n 6.Exit ";
    cout<<"\n\n Enter your choice :";
    cin>>choice;


    switch(choice)
    {
    case 1:
        insert_record();
        break;
    case 2:
        search();
        break;
    case 3:
        update();
    case 4:
        del_record();
        break;
    case 5:
        show();
        break;
    case 6:
        cout<<"\n\n\n===========THANK YOU===============";
        exit(0);
        break;
    default:
        cout<<"\n\n Invalid Choice..Please Try Again....";
    }
    getch();
    goto p;
}




void Library::insert_record()
{
    system("cls");
    cout<<"\n\n\t\t\t==============================================================";
    cout<<"\n\n\t\t\t=================LIBRARY MANAGEMENT SYSTEM====================";
    cout<<"\n\n\t\t\t==============================================================";
    Node *new_node = new Node;
    cout<<"\n\n Book ID : ";
    cin>> new_node-> id;
    cout<<"\n\n Book Name: ";
    cin>> new_node->name;
    cout<<"\n\n Book Author Name: ";
    cin>> new_node->author;
    cout<<"\n\n Book Publisher Name:";
    cin>> new_node->publisher;

    new_node->next_add= NULL;

    if(head==NULL)
    {
        head=new_node;
    }


    else
    {
        Node *ptr= head;
        while(ptr->next_add!=NULL)
        {
            ptr=ptr->next_add;
        }
        ptr->next_add= new_node;
    }
    cout<<"\n\n\t\t\t New book inserted Succesfully!";
}



void Library::search()
{
    system("cls");
    int t_id, found=0;
    cout<<"\n\n\t\t\t==============================================================";
    cout<<"\n\n\t\t\t=================LIBRARY MANAGEMENT SYSTEM====================";
    cout<<"\n\n\t\t\t==============================================================";
    if(head==NULL)
    {
        cout<<"\n\n Linklist is Empty.....";
    }
    else
    {
        cout<<"\n\n Book ID:";
        cin>>t_id;
        Node *ptr=head;

        while(ptr!=NULL)
        {
            if (t_id==ptr->id)
            {
                system("cls");
                cout<<"\n\n\t\t\t==============================================================";
                cout<<"\n\n\t\t\t=================LIBRARY MANAGEMENT SYSTEM====================";
                cout<<"\n\n\t\t\t==============================================================";
                cout<<"\n\n Book ID: "<<ptr->id;
                cout<<"\n\n Book Name:"<<ptr->name;
                cout<<"\n\n Author Name: "<<ptr->author;
                cout<<"\n\n Book Publisher Name:"<<ptr->publisher;
                found++;
            }
            ptr=ptr->next_add;
        }
        if(found==0)
        {
            cout<<"Book ID is invalid....!";
        }
    }
}




void Library::update()
{
    system("cls");
    int t_id, found=0;
    cout<<"\n\n\t\t\t==============================================================";
    cout<<"\n\n\t\t\t=================LIBRARY MANAGEMENT SYSTEM====================";
    cout<<"\n\n\t\t\t==============================================================";


    if(head==NULL)
    {
        cout<<"\n\n Linklist is Empty.....";
    }
    else
    {
        cout<<"\n\n Book ID:";
        cin>>t_id;
        Node *ptr=head;
        while(ptr!=NULL)
        {
            if (t_id==ptr->id)
            {
                system("cls");
                cout<<"\n\n\t\t\t==============================================================";
                cout<<"\n\n\t\t\t=================LIBRARY MANAGEMENT SYSTEM====================";
                cout<<"\n\n\t\t\t==============================================================";
                cout<<"\n\n Book ID: ";
                cin>>ptr->id;
                cout<<"\n\n Book Name:";
                cin>>ptr->name;
                cout<<"\n\n Author Name: ";
                cin>>ptr->author;
                cout<<"\n\n Book Publisher Name:";
                cin>>ptr->publisher;
                found++;
                cout<<"\n\n\t\t\tUpdate Book Succesfully.....!";
            }
            ptr=ptr->next_add;
        }
        if(found==0)
        {
            cout<<"Book ID is invalid....!";
        }
    }

}



void Library::del_record()
{
    system("cls");
    int t_id, found=0;
    cout<<"\n\n\t\t\t==============================================================";
    cout<<"\n\n\t\t\t=================LIBRARY MANAGEMENT SYSTEM====================";
    cout<<"\n\n\t\t\t==============================================================";
    if(head==NULL)
    {
        cout<<"\n\n Linklist is Empty.....";
    }
    else
    {
        cout<<"\n\n Book ID:";
        cin>>t_id;
        if(t_id==head->id)
        {
            Node *ptr=head;
            head=head->next_add;
            delete ptr;
            cout<<"\n\n Delete Book record Succesfully.....!";
            found++;
        }
        else
        {
            Node *prev=head;
            Node *ptr=head;
            while(ptr!=NULL)
            {
                if(t_id==ptr->id)
                {
                    prev->next_add= ptr->next_add;
                    delete ptr;
                    cout<<"\n\n Delete Book record Succesfully.....!";
                    found++;
                    break;
                }
                prev=ptr;
                ptr=ptr->next_add;
            }
        }
        if(found==0)
        {
            cout<<"Book ID is invalid....!";
        }
    }
}



void Library::show()
{
    system("cls");
    cout<<"\n\n\t\t\t==============================================================";
    cout<<"\n\n\t\t\t=================LIBRARY MANAGEMENT SYSTEM====================";
    cout<<"\n\n\t\t\t==============================================================";
    Node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<"\n\n Book ID: "<<ptr->id;
        cout<<"\n\n Book Name:"<<ptr->name;
        cout<<"\n\n Author Name: "<<ptr->author;
        cout<<"\n\n Book Publisher Name:"<<ptr->publisher;
        cout<<"\n\n\n ==========================================================";
        ptr=ptr->next_add;
    }
}




int main()
{
    Library lib;
    lib.menu();
}
