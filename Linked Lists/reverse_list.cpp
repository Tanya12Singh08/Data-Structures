#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insert_end(node **start,int number,node **tail)
{
    node *temp=new node();
    temp->data=number;
    temp->next=NULL;
    if(*start==NULL)
    {
        *start=temp;
        *tail=temp;
    }
    else
    {
        (*tail)->next=temp;
        *tail=temp;
    }

}
void reverse(node * start,node *tail)
{

node *temp=start;
    node *prev=NULL,*next=NULL;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    start=prev;

  //displaying the reversed linked list
    node *temp2=start;
    while(temp2!=NULL)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }

}
int main() {
    node *start=NULL;
    node *tail=NULL;
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        insert_end(&start,num,&tail);
    }
    reverse(start,tail);
    return 0;
}
