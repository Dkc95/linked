
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
}*p;


void InsAtBeg(int num)
{
    struct node *temp;
  temp=new node;
  temp->data=num;

  if(p==NULL)
  {
      temp->next=NULL;
      p=temp;
  }
  else{

           temp->next=p;
           p=temp;
  }

  }

  void InsAtEnd(int num)
  {
 struct node *temp,*r;
  temp=new node;
  temp->data=num;
  r=p;

  if(p==NULL)
  {
      temp->next=NULL;
      p=temp;
  }
  else{

           while(r->next!=NULL)
           {
               r=r->next;
           }
           temp->next=NULL;
           r->next=temp;
  }

  }
  void InsAfterPos(int num,int pos)
  {
struct node *temp,*r;
  temp=new node;
  temp->data=num;
  r=p;

  if(p==NULL)
  {
      temp->next=NULL;
      p=temp;
  }
  else{

           while(r->data!=pos)
           {
               r=r->next;
           }
           temp->next=r->next;
           r->next=temp;
  }
  }

  void DelAtBeg()
  {
     struct node *r;
      r=p;
      if(r==NULL)
      {
          cout<<"\nLinked list is empty.";
          return;
      }
      else{
       p=r->next;
       delete(r);
        }
  }

 void DelAtEnd()
  {
      struct node *r1,*r2;
      r1=p;
      r2=p->next;
      if(p==NULL)
      {
          cout<<"\nLinked list is empty.";
          return;
      }
      else if(p->next==NULL)
         {
          p=r1->next;
          delete(r1);
          }
      else{
       while(r2->next!=NULL)
       {
           r1=r2;
           r2=r2->next;
       }
       r1->next=NULL;
       delete(r2);
        }

  }

  void DelAtPos(int num)
  {
struct node *r1,*r2;
      r1=p;
      r2=p->next;
      if(r1==NULL)
      {
          cout<<"\nLinked list is empty.";
          return;
      }
      else if(r2->data==num)
         {
          r1->next=r2->next;
           delete(r2);
          }
      else{
       while(r2->next!=NULL)
       {
           r1=r2;
           r2=r2->next;
       }

        }


  }
  void SearchEle(int value)
  {
       struct node *r;
       int flag=0;
       r=p;
       if(r==NULL)
      {
          cout<<"\nLinked list is empty.";
          return;
      }
      else{
        while(r!=NULL)
        {
            if(r->data==value)
            {
                flag=1;
                break;

            }
            else{

            r=r->next;
            }
        }

      }
      if(flag==1)
      {
         cout<<"\nElement is available in Linked list .";
      }
      else{
        cout<<"\nElement is not available in Linked list .";
      }
  }

  void Display()
  {
      int size=0;
      struct node *r;
      r=p;
      if(r==NULL)
      {
          cout<<"\nLinked list is empty.";
          return;
      }
      else{
        while(r!=NULL)
        {
            cout<<r->data<<"\n";
            size++;
            r=r->next;
        }
        cout<<"The size of Linked list="<<size;
      }
  }


int main()
{
    int choice;
    while(1){
    cout<<"\nMenu:";
    cout<<"\n 1.Insertion at beginning";
    cout<<"\n 2.Insertion at End";
    cout<<"\n 3. Insertion at given position";
    cout<<"\n 4. Deletion at beginning";
    cout<<"\n 5. Deletion at End";
    cout<<"\n 6. Deletion of Given value";
    cout<<"\n 7. Search an element in Linked list-";
    cout<<"\n 8. Display";
    cout<<"\n Enter Choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            int num;
            cout<<"Enter Number:";
            cin>>num;
            InsAtBeg(num);
            break;
        }
        case 2:
        {
            int num;
            cout<<"Enter Number:";
              cin>>num;
            InsAtEnd(num);
            break;
        }
        case 3:
        {
            int num,pos;
            cout<<"Enter Number:";
              cin>>num;
              cout<<"Enter Position:";
              cin>>pos;
            InsAfterPos(num,pos);
            break;
        }
        case 4:
        {
            DelAtBeg();
            break;
        }
        case 5:
        {
            DelAtEnd();
            break;
        }
        case 6:
        {
            int num;
      cout<<"Enter the value u want to delete:";
              cin>>num;
            DelAtPos(num);
            break;
        }
         case 7:
        {
            int value;
            cout<<"Enter the value u want to Search:";
              cin>>value;
            SearchEle(value);
            break;
        }
        case 8:
        {
            Display();
            break;
        }
    }
}

}
