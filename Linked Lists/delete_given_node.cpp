#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    node* next;
}*start,*tail;
void create_node(int val)
{
    struct node* temp;
    temp=new(struct node);
    temp->data=val;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        tail=temp;
        temp=NULL;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }


}
void delete_given_node(int val)
{
    struct node* ptr;
    struct node* x;
    x=start;
    if(start==NULL)
    {
     cout<<"the given linked list doesn't exist";
    }
    else{
      while(x->data!=val&&x->next!=NULL)
      {
          ptr=x;
          x=x->next;
      }
      if(x->data==val){
      ptr->next=x->next;
      free(x);}
      else{
        cout<<"\nElement not found"<<endl;
      }
    }



}
void printlist(node *start)
{
	if(start==NULL)
	{
		cout<<"The given linked list is empty";
	}
	else
	{
		while(start!=NULL)
		{
			cout<<start->data<<" ";
			start=start->next;
		}
	}
}
int main()
{
    int n,val;
    start=NULL;
    tail=NULL;
    cout<<"Enter number of elements in list"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        create_node(val);

    }

    cout<<"Enter the value you want to delete"<<endl;
    cin>>val;
delete_given_node(val);
printlist(start);
return 0;
}
