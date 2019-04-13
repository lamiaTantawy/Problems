#include <iostream>
#include <string>
using namespace std;

struct node
{
  int data;
  node* next;
};
node* add(node* head1,node* head2,int carry)
{
    if(head1==NULL || head2==NULL)
    {
        if(carry==1)
        {
            node* n = new node;
            n->data = carry;
            n->next = NULL;
            return n;
        }
        else
            return NULL;
    }
        
    node* n = new node;
    n->data = ((head1->data+head2->data)%10+carry);
    n->next = NULL;
    n->next = add(head1==NULL?NULL:head1->next , head2==NULL?NULL:head2->next, (head1->data+head2->data)/10);
    
    
    return n;
    
}
void print(node* head)
{
    node* cursor = head;
    while(cursor!=NULL)
    {
        cout<<cursor->data;
        cursor = cursor->next;
    }
    cout<<endl;
}
int main()
{
    int Size;
    cin>>Size;
    node* cursor=new node;
    node* head = cursor;
    for(int i=0;i<Size;i++)
    {
        int num;
        cin>>num;
        cursor->data = num;
        cursor->next = new node;
        if(i!=Size-1)
            cursor = cursor ->next;
    }
    cursor->next = NULL;
    node* cursor1=new node;
    node* head1 = cursor1;
    for(int i=0;i<Size;i++)
    {
        int num;
        cin>>num;
        cursor1->data = num;
        cursor1->next = new node;
        if(i!=Size-1)
            cursor1 = cursor1 ->next;
    }
    cursor1->next = NULL;
  //  print(head);
    node* result=add(head,head1,0);
    print(result);
    return 0;
}
