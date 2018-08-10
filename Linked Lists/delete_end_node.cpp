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
void delete_end_node()
{
    struct node* ptr;
    struct node* x;
    x=start;
    if(start==NULL)
    {
     cout<<"the given linked list doesn't exist";
    }
    else{
        if(start->next==NULL)
        {
            ptr=start;
           start=NULL;
            free(ptr);
        }
        else{
                while(x!=NULL)
                {
                    ptr=x;
                    x=x->next;
                }
                ptr->next=NULL;
                free(x);
        }
    }



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
delete_end_node();

//updated linked list
for(int i=0;i<n-1;i++){
    cout<<start->data<<" ";
    start=start->next;
}
}
