#include <stdio.h> 
#include <stdlib.h> 
#include "calc.h" 
#define MAXOP 100

int main() {
	int type; 
	double op2; 
	char s[MAXOP];
	int op_st[100];//������ ���� ����
	int op_opr_size[100];//�����ڸ� ������ �� ���� ������ ����� �����ϴ� ����
	int op_sp = -1;//�� �� ������ ���� ������

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case '+':
			op_st[++op_sp] = '+';
			op_opr_size[op_sp] = size();
			break;
		case'-':
			op_st[++op_sp] = '-';
			op_opr_size[op_sp] = size();
			break;
		case'*':
			op_st[++op_sp] = '*';
			op_opr_size[op_sp] = size();
			break;
		case'/':
			op_st[++op_sp] = '/';
			op_opr_size[op_sp] = size();
			break;
		case NUMBER: 
				push(atof(s)); 
				while (op_sp > -1 && op_opr_size[op_sp] + 2 <= size()) {
					switch (op_st[op_sp]) {
					case '+':
						push(pop() + pop());
						op_sp--;
						break;
					case '*':
						push(pop() * pop());
						op_sp--;
						break;
					case '-':
						op2 = pop();
						push(pop() - op2);
						op_sp--;
						break;
					case '/':
						op2 = pop();
						if (op2 != 0.0)
							push(pop() / op2);
						else
							printf("error: zero divisor\n");
						op_sp--;
						break;

					}
				}
				break; 
			
			case '\n': 
				printf("\t%.8g\n",  pop()); 
				break; 
			default: 
				printf("error: unknown command %s\n", s); 
				break; 
		} 
	} 
	return 0;
}
