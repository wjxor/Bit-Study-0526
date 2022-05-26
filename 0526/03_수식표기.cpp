//03_수식표기
#include <iostream>
#include <stack>
using namespace std;

class Cal
{
public:
	//피연산자가 1의 자리!
	//"( 1 + ( 2 * 3 ) ) "
	static void postfix1(char* str, const char* src)
	{
		stack<char> stack;

		char ch;
		while (*src)
		{
			ch = *src;
			if (ch >= '0' && ch <= '9')	//피연산자
			{
				*str = ch;	 str++;
				*str = ' ';	 str++;
				//cout << ch << " ";
			}
			else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')//연산자
			{
				stack.push(ch);
			}
			else if (ch == ')')
			{
				ch = stack.top();
				stack.pop();
				*str = ch;	 str++;
				*str = ' ';	 str++;
				//cout << ch << " ";
			}
			src++;
		}

	}

	//피연산자가 1의 자리 이상!
	//"(12+(2*312))"
	static void postfix2(char* dst, const char* src)
	{
		stack<char> stack;

		while (*src)
		{
			if (*src == ')') //postfix1과 동일!
			{
				char oper = stack.top();
				stack.pop();

				*dst = oper;	dst++;
				*dst = ' ';		dst++;
				src++;
			}
			else if (*src == '+' || *src == '-' || *src == '/' || *src == '*')
			{
				stack.push(*src);
				src++;
			}
			else if (*src >= '0' && *src <= '9')
			{
				do
				{
					*dst++ = *src++;
				} while (*src >= '0' && *src <= '9');
				*dst++ = ' ';
			}
			else
				src++;
		}
		// 후위 표기법의 문자열의 뒤에 NULL 문자 추가 
		*dst = 0;
	}

	//후위표기법->연산결과 반환(1의 자리만 가능)
	static int cal1(const char* src)
	{
		stack<int> stack;

		while (*src)
		{
			char ch = *src;

			if (ch >= '0' && ch <= '9')
			{
				stack.push(ch - '0');
			}
			else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				int num1 = stack.top();		stack.pop();
				int num2 = stack.top();		stack.pop();

				switch (ch)
				{
				case '+':	stack.push(num2 + num1);   break;
				case '-':	stack.push(num2 - num1);   break;
				case '*':	stack.push(num2 * num1);   break;
				case '/':	stack.push(num2 / num1);   break;
				}
			}

			src++;
		}

		return stack.top();
	}

	//후위표기법->연산결과 반환(1의 자리 이상)
	static int cal2(const char* p)
	{
		stack<int> stack;

		while (*p)
		{
			if (*p >= '0' && *p <= '9')
			{
				int temp = 0;
				do
				{
					temp = temp * 10 + *p - '0';  //<-----
					p++;
				} while (*p >= '0' && *p <= '9');
				stack.push(temp);
			}
			else if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
			{
				int num1 = stack.top();  stack.pop();
				int num2 = stack.top();  stack.pop();
				switch (*p)
				{
				case '+': stack.push(num2 + num1);  break;
				case '-': stack.push(num2 - num1);  break;
				case '*': stack.push(num2 * num1);  break;
				case '/': stack.push(num2 / num1);  break;
				}
				p++;
			}
			else
				p++;
		}
		return stack.top();
	}
};

//1의 자리만 
void exam1()
{
	char src[20] = "( 1 + ( 2 * 3 ) ) ";
	char str[20] = "";

	Cal::postfix1(str, src);
	cout << str << endl;

	int value = Cal::cal1(str);
	cout << value << endl;		// 7
}

//1의 자리 이상
void exam2()
{
	char src[20] = "(12+(2*312))";
	char str[20] = "";

	Cal::postfix2(str, src);
	cout << str << endl;

	int value = Cal::cal2(str);
	cout << value << endl;		//636
}


int main()
{
	exam2();

	return 0;
}