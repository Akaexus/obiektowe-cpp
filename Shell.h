#pragma once
#include <string>
#include <vector>

class Shell
{
	public:
		void run();
	protected:
		typedef std::vector<std::string> arg_array;
		typedef std::string(Shell::*cmd_ptr)(arg_array);
		std::string getCommandPrompt();
		std::vector<std::string> inputCommand();
		std::vector<std::string> splitCommand(std::string cmd);
		std::string testFunction(arg_array args);
		cmd_ptr getCommand(std::string cmd);
};

