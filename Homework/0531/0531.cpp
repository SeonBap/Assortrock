#include <iostream>
#include <vector>
#include "HVector.h"

// ����0 => HVector�� leck�� ���ֿͶ�
//         ���Կ����ڸ� ����ϸ� �����°� �������� ��������.
//         �̹� ������ �ڵ� �̹� array���� �ذ��� �Ѱſ���.
// ����1 => ���ø����� �ٲټ���.

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		HVector Arr;

		for (size_t i = 0; i < 10; i++)
		{
			Arr.push_back(i);
		}

		for (size_t i = 0; i < Arr.size(); i++)
		{
			std::cout << Arr[i] << std::endl;
		}


		HVector Arr0;

		// ���� �ذ��ϴ� ���� �����̴ϴ�.
		// �������� ���簡 �̷������ �ϼ���.
		Arr0 = Arr;

		for (size_t i = 0; i < Arr0.size(); i++)
		{
			std::cout << Arr0[i] << std::endl;
		}

	}



}
