#include<stdio.h>
#include<stdlib.h>
void del(char x);

struct node
{
  char name;
  int tm;
  int rt;
  node *next;
};

typedef struct node node;
node *Head=NULL;
int j=65;

void insert (int n)
{
    node *nn;
	nn = (node*)malloc(sizeof(node));
    nn->name = j++;
    nn->tm = n;
    nn->rt = nn->tm;

    if (Head == NULL)
    {
    	Head = nn;
    	Head->next = Head;
    }
	else
    {
    	node *temp = Head;
    	while (temp->next != Head)
      	temp = temp->next;
    	nn->next = temp->next;
    	temp->next = nn;
    }
}
  
   void del(char x)
  {
    node *p = NULL;
    node *temp = Head;

    if (Head->name == x)
      {
    while (temp->next != Head)
      temp = temp->next;
    p = Head;
    temp->next = Head->next;
    Head = Head->next;
    free(p);
      }
    else
      {
    while (temp->name != x)
      {
        p = temp;
        temp = temp->next;
      }
    p->next = temp->next;
    free(temp);
      }
  }
void quantum (int t)
{
    node *temp;
	temp = Head;
    int c = 0, i = 0;

    while (Head != NULL)  
    {
      temp->rt=temp->rt-t;
      c=c+t;
      if (temp->rt <= 0)
    	{

          c = c + temp->rt;
          printf("%c",temp->name);
          printf("%d\n",c);
         del(temp->name);
         if (temp->next == temp)
	     {
	         exit(0);
	        }

        }

      temp = temp->next;
    }
      
  }
  
  

int main()
{
	int y,t,a[10],i;
	printf("Enter the no of processes:");
	scanf("%d",&y);
	printf("\n Enter the time quantum:");
	scanf("%d",&t);
	printf("Enter the execution time of each processes in order:");
	for (i = 0; i < y; i++)
    {
     	scanf("%d",&a[i]);
        insert (a[i]);

    }
    quantum (t);
	return 0;

}
