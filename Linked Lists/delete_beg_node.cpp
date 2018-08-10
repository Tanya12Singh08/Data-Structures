#include<bits/stdc++.h>
using namespace std;

//deletion at the beg
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
void delete_beg_node()
{
    struct node* ptr;
    struct node* x;
    if(start==NULL)
    {
     cout<<"the given linked list doesn't exist";
    }
    else{
        if(start->next==NULL)
        {
            start=NULL;
        }
        else{
                ptr=start;
            start=start->next;
            free(ptr);
        }
    }
x=start;


}
int main()
{
    int n,num,val;
    struct node* x;
    struct node* p;
    start=NULL;
    tail=NULL;
    cout<<"Enter number of elements in list"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        create_node(val);

    }
delete_beg_node();

//displaying the updated linked list
for(int i=0;i<n-1;i++){
    cout<<start->data<<endl;
    start=start->next;
}
}
