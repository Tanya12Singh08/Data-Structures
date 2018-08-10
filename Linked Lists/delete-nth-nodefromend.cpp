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


ListNode* removeNthFromEnd(ListNode* start, int n) {
    ListNode *temp=start;
    ListNode *ptr=NULL;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    if(start==NULL)
    return start;
    if(n>count||count==n)
    {
        ptr=start;
        start=start->next;
        ptr->next=NULL;
        free(ptr);
    }
    else
    {
        int p=count-n;
        temp=start;
        while(temp!=NULL&&p--)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=NULL;
        free(temp);
    }
    return start;
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
cout<<"Enter val to be deleted";
cin>>val;
ListNode * p=removeNthFromEnd(start, val);

while(p!=NULL)
{
	cout<<p->val<<endl;
	p=p->next;
}
return 0;
}
