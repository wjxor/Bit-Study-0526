#include <iostream>
#include <stack>
using namespace std;

class Sample {
public:
	static void changestring(char* str, const char* src)
	{
		stack<char> stack;

		//1. �������ڿ��� �����ϳ��ϳ��� ���ÿ� ����
		while (*src)
		{
			stack.push(*src);
			src++;
		}

		//2. ���ÿ� �ִ� ��� �����͸� POP
		while (stack.empty() == false)
		{
			char value = stack.top(); //peek()
			stack.pop();
			*str = value;
			str++;
		}
		*str = '\0';
	}

};

int main() {
	char source[] = "ABCDE";
	char arr[20] = "";

	Sample::changestring(arr, source);

	cout << arr << endl;  //GFEDCBA

	return 0;
}