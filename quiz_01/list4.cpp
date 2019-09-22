#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode* link;
};
int top = 0;

void PrintMenu(){
	printf("menu)\n");
	printf("1. Data register\n");
	printf("2. Data delete\n");
	printf("3. Data list\n");
	printf("4. Data search\n");
	printf("5. Data count\n");
	printf("6. exit\n");
	printf("input) ");
}

void DisplayList(ListNode** head){
	ListNode* temp = *head;
	if(temp == NULL){
		printf("empty\n");
	}
	else{
		printf("List = ");
		for(;temp != NULL; temp = temp->link){
			printf("%d ",temp->data);
		}
	}
	printf("\n");
}

void AddList(ListNode** head){
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = *head;
	int num;
	printf("Data register) ");
	scanf("%d",&num);
	temp->data = num;
	temp->link = NULL;
	top++;

	
	if(*head == NULL){	
		*head = temp;
	}
	else{
		for(;tmp->link != NULL; tmp = tmp->link){}	
		tmp->link = temp;
	}
	DisplayList(head);
}

void RemoveList(ListNode** head){
	ListNode* temp = *head;
	ListNode* tmp;
	ListNode* tp;
	int input;
	printf("Data delete: ");
	scanf("%d",&input);

	if(temp == NULL){
		printf("not data\n");
	}	
	else if(temp->data == input){
		tmp = temp->link;
		free(temp);
		*head = tmp;
		top--;
		if(top == 0){
			*head = NULL;
		}
	}
	else{
		while(temp->link!=NULL){
			if(temp->data == input){
				break;
			}	
			if(temp->link->data == input){
				tp = temp;	
			}
			temp = temp->link;
		}
		if(temp->data != input){
			printf("not data\n");
		}
		else{
			tmp = temp->link;
			tp->link = tmp;
			free(temp);
			top--;

			if(top == 0){
				*head = NULL;
			}
		}
	}
	DisplayList(head);
}

void FindList(ListNode** head){
	ListNode* temp = *head;
	int input;
	printf("data search: ");
	scanf("%d",&input);

	if(temp == NULL){
		printf("false\n");
	}
	else{
		while(temp != NULL){
			if(temp->data == input){
				printf("true\n");
				break;
			}	
			temp = temp->link;
		}
		if(temp==NULL){
			printf("false\n");
		}
	}	
}

void GetSize(ListNode** head){
	ListNode* temp = *head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp = temp->link;
	}
	printf("Data %d\n",count);
}	

void FreeList(ListNode** head){
	ListNode* temp = *head;
	ListNode* tmp;
	while(temp != NULL){
		tmp = temp;
		temp = temp->link;
		free(tmp);
	}
	*head = NULL;
}
		
int main(int argc, char* argv[]){
	ListNode* head = NULL;
	int input = 0, loop = 1;

	while(loop){
		PrintMenu();
		scanf("%d",&input);
		switch(input){
			case 1: AddList(&head); break;
			case 2: RemoveList(&head); break;
			case 3: DisplayList(&head); break;
			case 4: FindList(&head); break;
			case 5: GetSize(&head); break;
			case 6: loop=0; break;
			default: printf("Wrong input..\n");
		}
	}
	FreeList(&head);
	return 0;
}
