#include <iostream>
using namespace std;
struct node
{
  int data;
  node* next;
};
int findnthElement(node* head,int n)
{
    if(head==NULL || n<=0)
        return -1;
    node* p1 = head;
    node* p2 = head;
    for(int i=0;i<n-1;i++)
    {
        p2  = p2->next;
    }
    while(p2->next!=NULL)
    {
        p2=p2->next;
        p1=p1->next;
    }
    return p1->data;
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
    print(head);
    int n;
    cin>>n;
    if(n>Size)
        cout<<-1<<endl;
    else
    cout<<findnthElement(head,n)<<endl;
    return 0;
}
