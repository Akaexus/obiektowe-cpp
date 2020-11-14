#include "Shell.h"
#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>

void Shell::run()
{
	while (true) {
		std::vector<std::string> args = this->inputCommand();
		Shell::cmd_ptr cmd = this->getCommand(args[0]);
		if (cmd == nullptr) {
			std::cout << args[0] << ": nie znaleziono polecenia\n";
		}
		else {
			args.erase(args.begin());
			std::cout << (this->*cmd)(args) << "\n";
		}
	}
}

std::string Shell::getCommandPrompt()
{
	std::cout << this->storage.getCurrentNode();
	return ":~$ ";
}

std::vector<std::string> Shell::inputCommand()
{
	std::string commandString;
	do {
		std::cout << getCommandPrompt();
		std::getline(std::cin, commandString);
	} while (commandString == "");
	return this->splitCommand(commandString);
}

std::vector<std::string> Shell::splitCommand(std::string cmd)
{
	std::vector<std::string> cmds;
	std::string buffer;
	for (int i = 0; i < cmd.length(); i++) {
		if (cmd[i] == ' ' && buffer.size() > 0) {
			cmds.push_back(buffer);
			buffer = "";
		}
		else {
			buffer += cmd[i];
		}
	}
	if (buffer.size() > 0) {
		cmds.push_back(buffer);
	}
	return cmds;
}

std::string Shell::_tree(arg_array args)
{
	return this->storage.tree();
}

Shell::cmd_ptr Shell::getCommand(std::string cmd)
{
	std::transform(cmd.begin(), cmd.end(), cmd.begin(), std::tolower);
	std::map<std::string, cmd_ptr> commands	= {
		{
			"tree",
			&Shell::_tree
		}
	};
	// commands.insert({"testFunction", 5});
	if (commands.count(cmd)) {
		return commands.at(cmd);
	}
	return nullptr;
}

