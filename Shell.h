#pragma once
#include <string>
#include <vector>
#include "Storage.h"

class Shell
{
	public:
		void run();
		typedef std::vector<std::string> arg_array;
	protected:
		typedef std::string(Shell::* cmd_ptr)(arg_array);
		Storage storage;
		std::string getCommandPrompt();
		std::vector<std::string> inputCommand();
		std::vector<std::string> splitCommand(std::string cmd);
		cmd_ptr getCommand(std::string cmd);
		std::string _tree(arg_array args);
};

