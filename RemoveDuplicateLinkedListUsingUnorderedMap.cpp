#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
struct node
{
    char data;
    node* next;
};
void RemoveDuplicate(node*& head)
{
    unordered_map<char,int> map;
    node* cursor = head;
    node* pre = head;
    while(cursor!=NULL)
    {
        if(map.count(cursor->data)>0)
        {
            pre->next=cursor->next;
            cursor->next = NULL;
            cursor=pre;
        }
        else
        {
            if(map.count(cursor->data)==0)
                map[cursor->data]=1;
            else
                map[cursor->data]=map[cursor->data]+1;
            
        }
        pre = cursor;
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
    string str;
    cin>>str;
    node* cursor = new node;
    node* head = cursor;
    if(str.length()>0){
    for(int i=0;i<str.length();i++)
    {
        cursor->data = str[i];
        cursor->next = new node;
        cursor = cursor->next;
    }
    cursor->next = NULL;
    RemoveDuplicate(head);
    print(head);
    }
    return 0;
}
