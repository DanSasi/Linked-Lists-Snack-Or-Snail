
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct list
{
	int Key;
	struct list* next;
}typedef list_t;

list_t* head = NULL;
struct list* current = NULL;

void insertFirst(int key) {
	//create a link
	list_t* t = (list_t*)malloc(sizeof(list_t));
	t->Key = key;
	//point it to old first node
	t->next = head;
	//point first to new first node
	head = t;
}
void AddList(list_t* head, int key) {
	list_t* list = head;
	if (list == NULL)
		return;
	while (list->next != NULL) {
		list = list->next;
	}
	/* now we can add a new variable */
	list->next = (list_t*)malloc(sizeof(list_t));
	list->next->Key = key;
	list->next->next = NULL;
}
void creatsnakeorsnail(list_t* list)
{
	list_t* head = NULL;
	list_t* savenodesnail = NULL;
	int flag = 1, flag2 = 1;
	int s1, s2, s3, s4;
	s1 = rand() % 10 + 1;
	if (s1 > 5) // if thats a snake 
	{
		while (flag)
		{
			s2 = rand() % 100 + 1;
			if (s2 > 1)
			{
				if (head == NULL)
				{
					insertFirst(s2);
				}
				AddList(head, s2);

			}
			else {
				flag = 0;
				head = NULL;
				return;
			}
		}

	}
	else if (s1 < 5) // if thats a snail 
	{
		while (flag)
		{
			s3 = rand() % 100 + 1;
			if (s3 < 15)
			{
				if (head == NULL)
				{
					insertFirst(s3);
				}
				savenodesnail = head;
				while (flag2)
				{
					s4 = rand() % 100 + 1;
					if (s4 > 2)
						AddList(head, s4);
					else {
						head = NULL;
						flag = 0;
						flag2 = 0;
						break;
					}

				}
			}
			else if (s3 >= 15)
			{
				if (head == NULL)
				{
					insertFirst(s3);
				}
				AddList(head, s3);
			}
		}
	}
}
list_t* SnackorSnail(list_t* list)
{
	list_t* ptr = NULL;
	if (list == NULL) // about snacke
	{
		return NULL;
	}
	else
		ptr = list->next;
	while (ptr != NULL && list != ptr)// about snail 
	{
		ptr = ptr->next;
		list = list->next;
		if (ptr == NULL)
		{
			return NULL;
		}
		else
			ptr = ptr->next;
	}
	return ptr;
}

void printList(list_t* l) {
	struct list* ptr = head;
	int count = 0;
	//start from the beginning
	list_t* x = SnackorSnail(l);
	if (!x) {                    //snake
		printf("\n[ ");
		while (ptr != NULL) {
			printf("(%d)-> ", ptr->Key);
			count++;
			ptr = ptr->next;
		}
		printf("NULL    ");

		printf("the count is: %d ", count);

		printf("]");
	}
	else
	{
		printf("\n[ ");
		while (ptr != x) {
			printf("(%d) ", ptr->Key);
			count++;
			ptr = ptr->next;
		}
		printf("\n->(%d)", x->Key);
		ptr = ptr->next;
		while (ptr != x) {
			printf("(%d) ", ptr->Key);
			count++;
			ptr = ptr->next;
		}
		printf(" ]");
	}
}


void main()
{
	list_t* h1 = NULL;
	list_t* h2 = NULL;
	list_t* h3 = NULL;
	list_t* h4 = NULL;
	creatsnakeorsnail(h1);
	printList(h1);
	creatsnakeorsnail(h2);
	printList(h2);
	creatsnakeorsnail(h3);
	printList(h3);
	creatsnakeorsnail(h4);
	printList(h4);
}