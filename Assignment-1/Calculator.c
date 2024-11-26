#include <stdio.h>
#include<string.h>
#include<math.h>
struct stack{
    int values[100];
    char operate[100];
    int top1;
    int top2;
};
int isdigit1(char ch){
    int x=ch-'0';
    if(x>=0 && x<=9){
       return 1;
    }
    return 0;
}
int apply(int x,int y, char ch){
    if(ch=='+'){
        return x+y;
    }
    else if(ch=='-'){
        return y-x;
    }
    else if(ch=='*'){
        return x*y;
    }
    else if(ch=='/'){
        if(x==0){
            printf("Error: Division by Zero");
            return -2;
        }
        float z= y/x;
        return floor(z);
    }
    else{
        return -1;
    }
}
int precedence(char ch){
   
    if(ch=='*'|| ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    return 0;
}
int check(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='('||ch==')' || ch-'0'>=0 && ch-'0'<=9){
        return 1;
    }
    return 0;
}
int main() {
    // Write C code here
    // printf("Try programiz.pro");
    struct stack op;
    struct stack value;
    // int n;
    char s[100];
    printf("enter string");
    // scanf("%s",&s);
    fgets(s,100,stdin);
    printf("%s \n",s);
     op.top1=-1;
     value.top2=-1;
     int l=strlen(s);
     printf("string length-%d",l);
     int isvalid=1;
     for(int i=0;i<l-1;i++){
        if(s[i]==' '){
            continue;
        }
       int y=check(s[i]);
       printf("%c-%d \n",s[i],y);
        if(y==0){
            isvalid=0;
            break;
        }
     }
     if(!isvalid){
            printf("Error: Invalid Expression");
     }
     else{
        int isvalid=1;
        int iszero=0;
     for(int i=0;i<l;i++){
        if(s[i]==' '){
            continue;
        }
         else if(s[i]=='('){
            // printf(" Entered in %d",i);
             op.top1=op.top1+1;
             op.operate[op.top1]=s[i];
             printf("%d-%c \n",op.top1,op.operate[op.top1]);
         }
         else if(isdigit1(s[i])){
            // printf("entered in isdigit %d",i);
             // to check whether values are of 1 digit or more tahn that
             int val=0;
             while(i<l && isdigit1(s[i])){
                 val=val*10+(s[i]-'0');
                 i++;
             }
             value.top2=value.top2+1;
             value.values[value.top2]=val;
             printf("%d-%d \n",value.top2,value.values[value.top2]);
             i--;
         }
         else if(s[i]==')'){
            // printf("entered in  %d",i);
            while(op.top1!=-1 && op.operate[op.top1]!='('){
                int x=value.values[value.top2];
                value.top2=value.top2-1;
                int y=value.values[value.top2];
                value.top2=value.top2-1;
                char ch=op.operate[op.top1];
                op.top1=op.top1-1;
                value.top2=value.top2+1;
                int m=apply(x,y,ch);
                if(m==-1){
                    isvalid=0;
                    break;
                }
                 if(m==-2){
                    iszero=1;
                    break;
                }
                else{
                value.values[value.top2]=m;
                printf("%d-%d\n",value.top2,value.values[value.top2]);
                }
            }
            op.top1=op.top1-1;
         }
         else{
            //  printf("entered in else %d",i);
            while(op.top1!=-1 && precedence(op.operate[op.top1])>=precedence(s[i])){
                 int x=value.values[value.top2];
                value.top2=value.top2-1;
                int y=value.values[value.top2];
                value.top2=value.top2-1;
                char ch=op.operate[op.top1];
                printf("%c \n",ch);
                op.top1=op.top1-1;
                value.top2=value.top2+1;
                int m=apply(x,y,ch);
                if(m==-1){
                    isvalid=0;
                    break;
                }
                if(m==-2){
                    iszero=1;
                    break;
                }
                else{
                value.values[value.top2]=m;
                 printf("%d-%d\n",value.top2,value.values[value.top2]);
                }
            } 
              op.top1=op.top1+1;
              op.operate[op.top1]=s[i];
             printf("%c-%c\n",op.top1,s[i]);
           
            }

         }
         
     if(isvalid){
     while(op.top1!=-1 ){
         int x=value.values[value.top2];
                value.top2=value.top2-1;
                int y=value.values[value.top2];
                value.top2=value.top2-1;
                char ch=op.operate[op.top1];
                printf("%c \n",ch);
                op.top1=op.top1-1;
                value.top2=value.top2+1;
                int m=apply(x,y,ch);
                if(m==-1){
                    isvalid=0;
                    break;
                }
                 if(m==-2){
                    iszero=1;
                    break;
                }
                else{
                value.values[value.top2]=m;
                printf("%d-%d\n",value.top2,value.values[value.top2]);
                }
     }
     if(iszero){
        return 0;
     }
     else{
     if(op.top1!=-1){
        printf("Error:Invalid Expression");
     }
     else{
     printf("\n");
    printf("%d\n",value.values[0]);
     }
     }
     }
     else{
        printf("Error:Invalid Expression");
     }
     }
    return 0;
}