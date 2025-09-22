#include<stdio.h>
#include<stdio.h>
#include<string.h>
#define max 10
char stack[max];
int top=-1;
void push(char);
char pop();
char peek();
int precedence(char);
void infixtopostfix(char infix[]);
int main(){
    char infix[max];
    printf("Enter an infix expression:");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}
void push(char c){
    if(top==max-1){
        printf("stack over flow");
        return ;
    }
    stack[++top]=c;
}
char pop(){
    if(top==-1){
        printf("Stack is empty");
        return -1;
    }
    return stack[top--];
}
char peek(){
    if(top==-1){
        printf("Stack is empty");
        return -1;
    }
    return stack[top];
}
int precedence(char c){
    if(c=='^')
       return 3;
    else if(c=='*'||c=='/')
       return 2;
    else if(c=='+'||c=='-')
        return 1;
    else 
       return 0;   
}
void infixtopostfix(char infix[]){
    char postfix[max];
    int i,k=0;
    char ch;
    for(i=0;infix[i]!='\0';i++){
        ch=infix[i];
        if(isalnum(ch)){
            postfix[k++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(top!=-1&&peek()!='('){
                postfix[k++]=pop();
            }
            pop();
        }
        else 
        {
            while(top!=-1&&precedence(peek(ch))>=precedence(ch)){
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("postfix expression:%s",postfix);
}
