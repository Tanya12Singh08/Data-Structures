#include<bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
}*start,*tail;
void create_node(int valu)
{
    ListNode* temp;
    temp=new(struct ListNode);
    temp->val=valu;
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
int lPalin(ListNode* start) {
    ListNode *list=NULL;
    int count=0;
    ListNode * temp=start;
    if(temp==NULL)
    return 0;
    else if(temp->next==NULL)
    return 1;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    temp=start;
    for(int i=1;i<count/2;i++)
    {
        temp=temp->next;
    }
    list=temp->next;
    ListNode *prev=NULL,*nextptr=NULL;
    while(list!=NULL)
    {
        nextptr=list->next;
        list->next=prev;
        prev=list;
        list=nextptr;
    }
    list=prev;
    temp=start;
   while(list!=NULL)
    {
        if(temp->val!=list->val)
        {
        	   return 0;
		}
        temp=temp->next;
        list=list->next;
    }
  return 1;
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
int a=lPalin(start);
if(a==1)
{
	cout<<"Yes the given linked list is a palindrome";
}
else
{
	cout<<"No the given linked list is not a palindrome";
}
return 0;
}
