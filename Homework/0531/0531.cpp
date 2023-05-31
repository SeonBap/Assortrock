#include <iostream>
#include <vector>
#include "HVector.h"

// 숙제 => HVector의 leck을 없애와라
//         대입연산자를 사용하면 터지는걸 정상으로 돌려놔라.
//         이미 보여준 코드 이미 array에서 해결은 한거에요.


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

		// 릭을 해결하는 순간 터질겁니다.
		// 정상적인 복사가 이루어지게 하세요.
		Arr0 = Arr;

		for (size_t i = 0; i < Arr0.size(); i++)
		{
			std::cout << Arr0[i] << std::endl;
		}

	}



}
