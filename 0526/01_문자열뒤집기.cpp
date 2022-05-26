#include <iostream>
#include <stack>
using namespace std;

class Sample {
public:
	static void changestring(char* str, const char* src)
	{
		stack<char> stack;

		//1. 원본문자열의 문자하나하나를 스택에 저장
		while (*src)
		{
			stack.push(*src);
			src++;
		}

		//2. 스택에 있는 모든 데이터를 POP
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