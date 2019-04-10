#include <iostream>
#include <string>
using namespace std;
struct node
{
  char data;
  node* next;
};
void RemoveDuplicate(node*& head)
{
    node* cursor = head;
    while(cursor!=NULL)
    {
        node* pre = cursor;
        node* second = cursor->next;
        while(second!=NULL)
        {
            if(cursor->data==second->data)
            {
                //delete the second
                pre->next = second->next;
                second->next = NULL;
                second = pre->next;
            }
            else
            {
                pre = second;
                second=second->next;
            }
        }
        cursor=cursor->next;
    }
}
void print(node* head)
{
    node* cursor = head;
    while(cursor!=NULL)
    {
        cout<<cursor->data;
        cursor=cursor->next;
    }
    cout<<endl;
}
int main()
{
    node* cursor = new node;
    node* head = cursor;
    int n;
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++)
    {
        cursor->data = str[i];
        cursor->next = new node;
        if(i!=str.length()-1)
            cursor = cursor->next;
    }
    cursor->next = NULL;
   // print(head);
    RemoveDuplicate(head);
    print(head);
    return 0;
}
