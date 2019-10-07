#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int c=0;
struct Node{
    int rollNo;
    char name[50];
    struct Node *next;
    struct Node *prev;
};
struct Node* head;
struct Node* GetNewNode(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf(" Enter the Roll number.: ");
    scanf("%d",&newNode->rollNo);
    printf(" Enter the Name of Student.: ");
    scanf("%s",&newNode->name);
    newNode->prev = NULL;
    newNode->next = NULL;
    c++;
    return newNode;
}
void InsertAtHead(){
    struct Node* newNode = GetNewNode();
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void InsertAtNth(int n){
    struct Node* newNode = GetNewNode();
    int i;
    struct Node* temp = head;
    for(i=0; i<n-2; i++){
        temp=temp->next;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    (newNode->next)->prev = newNode;
}
void InsertAtEnd(int n){
    struct Node* newNode = GetNewNode();
    int i;
    struct Node* temp = head;
    for(i=0; i<n-2; i++){
        temp=temp->next;
    }
    newNode->prev = temp;
    temp->next=newNode;
}
int Search(int n){
    struct Node* temp = head;
    int flag = -1;
    int pos = 0;
    while(temp != NULL){
        pos++;
        if(temp->rollNo == n){
            printf(" %d \t\t %s\n",temp->rollNo,temp->name);
            flag = 0;
            break;
        }
        if(temp->next != NULL)
         temp = temp->next;
        else
            break;
    }
    if(flag != 0){
        printf(" Not Found.\n");
        return -1;
    }
    return pos;
}
void Delete(n){
    int pos = Search(n);
    int i;
    if(pos == -1){
        printf(" Roll Number is Not in list.\n");
        return;
    }
    struct Node* temp = head;
    for(i=0; i<pos-1; i++){
        temp = temp->next;
    }
    if(head == temp){
        head = temp->next;
    }
    if(temp->next != NULL){
    (temp->next)->prev = temp->prev;
    }
    if(temp->prev!=NULL){
    (temp->prev)->next = temp->next;
    }
    c--;
    free(temp);
}
void Print(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    printf("\n Roll No. \t Student Name\n\n");
    while(temp!=NULL){
        printf(" %d \t\t %s",temp->rollNo,temp->name);
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int n,i,ch;
    bool v = true;
    while(v){
        printf(" 1. Insert at head.\n 2. Insert at nth position.\n 3. Search.\n 4. Delete.\n 5. Print.\n 6. Exit.\n");
        printf(" Enter the choice.: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                InsertAtHead();
                break;
            }
            case 2:{
                printf(" Enter the Position where you want to Insert new Element.: ");
                scanf("%d",&n);
                if(n>c+1){
                    printf(" Invalid Position. Enter Again.\n");
                }
                else if(n == 1){
                    InsertAtHead();
                }
                else if(n == c+1){
                    InsertAtEnd(n);
                }
                else if(n > 1){
                    InsertAtNth(n);
                }
                break;
            }
            case 3:{
                printf(" Enter the Roll number you want to Search.: ");
                scanf("%d",&n);
                Search(n);
                break;
            }
            case 4:{
                printf(" Enter the Roll Number you want to Delete.: ");
                scanf("%d", &n);
                Delete(n);
                break;
            }
            case 5:{
                Print();
                break;
            }
            case 6:{
                v = false;
                break;
            }
            default:{
                printf(" Invalid Choice. Enter Again.\n");
                break;
            }
        }
    }
}
