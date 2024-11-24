#include<stdio.h>
struct Users{
    char name[50];
    int id;
    int age;
};
void createFile(FILE *fptr){
    fptr=fopen("Users.txt","w");
    fclose(fptr);
}
void createUser(FILE* fptr){
    fptr=fopen("Users.txt","a");
    FILE *temp=fopen("Users.txt","r");
    int id;
    printf("Enter id:");
    scanf("%d",&id);
    Users user;
    int found=0;
     while(fscanf(temp,"%s %d %d \n",user.name,&user.id,&user.age)!=EOF){
          if(user.id==id){
            found=1;
            break;
          }
        }
        fclose(temp);
        if(found==1){
            printf("Id already exist\n");
        }
        else{
    printf("Enter User Name:");
    scanf("%s",user.name);
   user.id=id;
    printf("enter age:");
    scanf("%d",&user.age);
    fprintf(fptr,"%s %d %d \n",user.name,user.id,user.age);
    printf("User added \n");
        }
        fclose(fptr);
}
void dispayUser(FILE *fptr){
    Users user;
    fptr=fopen("Users.txt","r");
    if(fptr==NULL){
        printf("File not found \n");
    }
    else{
         printf("user data\n");
        //  char buf[100];
        while(fscanf(fptr,"%s %d %d \n",user.name,&user.id,&user.age)!=EOF){
            printf("username:%s\t userid:%d\t userage:%d\t",user.name,user.id,user.age);
           printf("\n");
        }
    }
    printf("\n");
    fclose(fptr);
}
void updateUser(FILE *fptr){
    fptr=fopen("Users.txt","r");
    FILE *temp=fopen("temp.txt","w");
    int id;
    printf("Enter Id:");
    scanf("%d",&id);
    int found=0;
    Users user;
    while(fscanf(fptr,"%s %d %d \n",user.name,&user.id,&user.age)!=EOF){
           if(user.id==id){
             found=1;
             printf("%s\t%d\t%d\t",user.name,user.id,user.age);
             printf("Enter User Name:");
            scanf("%s",user.name);
            // printf("Enter Id:");
            // scanf("%d",&user.id);
            printf("enter age:");
            scanf("%d",&user.age);
           }
           fprintf(temp,"%s %d %d \n",user.name,user.id,user.age);
    }
    
    fclose(fptr);
    fclose(temp);
    remove("Users.txt");
    rename("temp.txt","Users.txt");
    if(found==0){
        printf("Id not found\n");
    }
    else{
        printf("user updated\n");
    }
}
void deleteUser(FILE *fptr){
  Users user;
  fptr=fopen("Users.txt","r");
  FILE *temp=fopen("temp.txt","w");
  int found=0;
  int id;
  printf("enter id");
  scanf("%d",&id);
  while(fscanf(fptr,"%s %d %d",user.name,&user.id,&user.age)!=EOF){
      if(user.id==id){
        found=1;
        continue;
      }
      fprintf(temp,"%s %d %d \n",user.name,user.id,user.age);
  }
  fclose(fptr);
  fclose(temp);
  remove("Users.txt");
  rename("temp.txt","Users.txt");
  if(found==0){
    printf("id not found\n");
  }
  else{
    printf("id deleted\n");
  }
}
int main(){
    FILE *fptr;
    createFile(fptr);
    // printf("enter 1 for creating user\n");
    // printf("enter 2 for displaying users \n");
    // printf("enter 3 for updating User \n");
    // printf("enter 4 for deleting user \n");
    // printf("enter 5 for exit \n");
    int n=1;
    while(n!=-1){
    printf("enter 1 for creating user\n");
    printf("enter 2 for displaying users \n");
    printf("enter 3 for updating User \n");
    printf("enter 4 for deleting user \n");
    printf("enter -1 for exit \n");
     printf("enter choice \n");
    scanf("%d",&n);
    switch(n){
       case 1:createUser(fptr);
              break;
       case 2:dispayUser(fptr);
              break;
        case 3:updateUser(fptr);
        break;
        case 4:deleteUser(fptr);
        break;
        default: printf("enter correct number");
        break;
    }
    }
    return 0;
}