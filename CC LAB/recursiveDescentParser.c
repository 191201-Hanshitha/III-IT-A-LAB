#include<stdio.h>
#include<string.h>
char input[100];
int i,l;
int E();
int EP();
int T();
int TP();
int F();
int main(){
	printf("Recursive descent parsing for the following grammer\n");
	printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");
	printf("Enter the string to be checked:");
	scanf("%s",input);
	E();
	if(input[i+1]=='\0'){
		printf("\n string is accepted\n");
	}
	else{
		printf("\n string is not accepted\n");
	}
}
int E(){
	T();
	EP();
}
int EP(){
	if(input[i]=='+'){
		i++;
		T();
		EP();
	}
	else
		return (0);
}
int T(){
	F();
	TP();
}
int TP(){
	if(input[i]=='*'){
                i++;
                F();
                TP();
        }
}
int F(){
	if(input[i]=='('){
		i++;
		E();
		if(input[i]==')'){
			i++;
			return (1);
		}
		else
			return(0);
	}
	else if(input[i]>='a' && input[i]<='z' || input[i]>='A'&&input[i]<='Z'){
		i++;
		return(1);
	}
	else
		return(0);
}


