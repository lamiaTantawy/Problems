#include <iostream>
using namespace std;
struct node
{
  int data;
  node* next;
};
bool Delete(node*& middle)
{
    if(middle==NULL || middle->next==NULL)
        return false;
    node* Next = middle->next;
    middle->data = Next->data;
    middle->next = Next->next;
    return true;
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
    cout<<Delete(head->next)<<endl;
    print(head);
    return 0;
}
