#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node node;
struct node{
    int key;
    int value;
    node *next;
};
int findIndex(int key1,int size){
    int value=(key1%size);
    // printf("value:%d",value);
    return value;
}
void display(node **map,int size){
  for(int i=0;i<size;i++){
      if(map[i]==NULL){
          continue;
      }
      else{
       printf("index:%d ",i);
       node *temp=map[i];
       while(temp->next!=NULL){
           printf("(%d, %d)->",temp->key,temp->value);
           temp=temp->next;
       }
       printf("(%d, %d)",temp->key,temp->value);
       printf("\n");
      }
  }
}
void insert(node **map,int key1,int value1,int size){
    // printf("(%d %d)\n",key1,value1);
    int index=findIndex(key1,size);
    // printf("index:%d",index);
    node *newNode=(node*)malloc(sizeof(node));
    newNode->key=key1;
    newNode->value=value1;
    newNode->next=NULL;
    if(map[index]==NULL){
        // printf("enter");
      map[index]=newNode;
    }
    else{
        node *temp=map[index];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void search(node **map,int key1,int size){
    int index=findIndex(key1,size);
    node *temp=map[index];
    bool isfound=false;
    while(temp!=NULL){
        if(temp->key==key1){
            printf("value:%d\n",temp->value);
            isfound=true;
            break;
        }
    }
    if(!isfound){
       printf("key do not exist\n");
    }
}
void Delete(node **map,int key1,int size){
    int index=findIndex(key1,size);
    if(map[index]==NULL){
        printf("key do not exist\n");
    }
    else{
        node *temp=map[index];
        node *prev=NULL;
        if(temp->key==key1){
            map[index]=temp->next;
            temp->next=NULL;
            printf("%d is deleted\n",key1);
            free(temp);
        }
        else{
            while(temp!=NULL && temp->key!=key1){
                prev=temp;
                temp=temp->next;
            }
            if(temp==NULL){
                printf("key do not exist\n");
            }
            else{
                prev->next=temp->next;
                temp->next=NULL;
                printf("%d is deleted\n",key1);
                free(temp);
            }
        }
    }
}
void initialize(node **map,int size){
    for(int i=0;i<size;i++){
        map[i]=(node*)malloc(sizeof(node));
    }
    for(int i=0;i<size;i++){
        map[i]=NULL;
    }
}
int main() {
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    node **map=(node**)malloc(size*sizeof(node*));
    initialize(map,size);
    int choice;
    while(1){
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice==1){
            int key;
            printf("Enter key:");
            scanf("%d",&key);
            int value;
            printf("Enter value:");
            scanf("%d",&value);
            if(key<0 || value<0){
                printf("Enter non negative integer\n");
            }
            else{
            // printf("Enter\n");
            insert(map,key,value,size);
            }
        }
        else if(choice==2){
            int key;
            printf("Enter key to search:");
            scanf("%d",&key);
            search(map,key,size);
        }
        else if(choice==3){
            int key;
            printf("Enter Key to delete:");
            scanf("%d",&key);
            Delete(map,key,size);
        }
        else if(choice==4){
            display(map,size);
        }
        else if(choice==5){
            printf("Exiting Program");
            break;
        }
    }

    return 0;
}
