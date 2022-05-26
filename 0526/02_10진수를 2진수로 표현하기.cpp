#include <iostream>
#include <stack>
using namespace std;

class Sample {
public:
	// 10���� 
	// 8����
	// 16����
	static void Example() {
		int num1 = 10;
		printf("%d, 0%o, 0x%x\n", num1, num1, num1);

		int num2 = 012;
		printf("%d, 0%o, 0x%x\n", num2, num2, num2);

		cout << std::dec << num1 << ", ";
		cout << std::oct << "0" << num1 << ", ";
		cout << std::hex << "0x" << num1 << endl;
	}

	static void changenumber(char* str, int number) {
		stack<int> stack;

		// 1. number�� 2�� �����鼭 �������� stack�� push
		while (number > 2)
		{
			stack.push(number % 2);
			number = number / 2;
		}

		stack.push(number);

		// 2. ���ÿ��� ���� ���ڿ��� ����
		while (stack.empty() == false) {
			int value = stack.top();
			stack.pop();
			*str = value + '0';
			str++;
		}
		*str = '\0';
	}
};

int main() {
	// Sample::Example();
	char arr[20] = "";
	Sample::changenumber(arr, 26);
	cout << arr << endl;


	return 0;
}