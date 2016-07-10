#ifndef CPP_WARRIOR_UI_H
#define CPP_WARRIOR_UI_H

#include <regex>
#include <thread>
#include <string>
#include <iostream>

namespace CppWarrior
{
	using namespace std::chrono_literals;

	class UI
	{
	public:
		static void Puts(std::string msg)
		{
			std::cout << msg << std::endl;
		}

		static void PutsWithDelay(std::string msg)
		{
			std::this_thread::sleep_for(200ms);
			Puts(msg);
		}

		static std::string Gets()
		{
			std::string ret;
			getline(std::cin, ret);
			return ret;
		}

		static std::string Request(std::string msg)
		{
			std::cout << msg;
			std::string ret = Gets();
			return Trim(ret);
		}

		static bool Ask(std::string msg)
		{
			return Request(msg + "[yn] ") == "y";
		}

		// TODO: Implement Choose()

		static std::string Trim(std::string& str)
		{
			std::string ret = regex_replace(str, std::regex("^ +| +$|( ) +"), "$1");
			return ret;
		}
	};
}

#endif