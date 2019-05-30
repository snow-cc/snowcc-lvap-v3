// Project1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<locale>
#include"momoLibrary.hxx"
enum rv{success=1,errorvalue};

int bitxlinux()
{
	std::wcout.imbue(std::locale("chs"));
	std::wcout << "This is not Linux Version v3.00" << std::endl;
	return static_cast<int>(errorvalue);
}
int bitxwindows()
{
	SetConsoleTitleA("猜词游戏");
	auto status = MessageBoxA(nullptr, "来玩猜词吧", "提示", MB_YESNO);
	if (status = 1)
	{
		;
	}
	else
	{
		exit(0);
	}
	const std::string wordlist2[26] =
	{
		"apiary","beetle","cereal","danger","ensign","florid",
		"garage","healthy","insult","jackal","keeper","loaner",
		"manage","nonce","onset","plaid","quilt","remote",
		"stolid","train","useful","valid","whence","xenon",
		"yearn","zippy"
	};

	std::default_random_engine a = std::default_random_engine(std::time(nullptr));
	std::uniform_int_distribution<int> e = std::uniform_int_distribution<int>(0, 25);
		std::string target = wordlist2[e(a)];
		int len = target.size();
		std::string att(len, '-');
		std::string badchars;
		int guess = 6;
		std::cout << "猜词。它由 " << len << " 个字母组成" << ",\n 一次猜一个字母，你有 " << guess << "次机会.\n";
		std::cout << "词语:" << att << std::endl;
		while (guess > 0 && att != target)
		{
			char letter;
			std::cout << "猜一个字母！ ";
			std::cin >> letter;
			if (badchars.find(letter) != std::string::npos || att.find(letter) != std::string::npos)
			{
				std::cout << "孩子，你不是猜过这个了吗？\n"
					;
				continue;
				/////////
			}
			int loc = target.find(letter);
			if (loc == std::string::npos)
			{
				std::cout << "错了。\n";
				--guess;
				badchars += letter;
			}
			else {
				std::cout << "对！" << std::endl;
				att[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != std::string::npos)
				{
					att[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			std::cout << "猜出来了: " << att << std::endl;
			if (att != target)
			{
				if (badchars.size())
					std::cout << "错误的字母" << badchars << std::endl;
				std::cout <<" 还能猜"  <<guess<<"次\n" ;



			}

		}
		if (guess > 0)
			std::cout << "对"  << std::endl;
		else
			std::cout << "错了，是 " << '\'' << target << "" << '\'' << ".\n";
		std::cin.get();
		return 0;
	}
int main()
{
	bitxwindows();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
