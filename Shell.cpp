#include "Shell.h"
#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>

void Shell::run()
{
	std::string output;
	while (true) {
		std::vector<std::string> args = this->inputCommand();
		Shell::cmd_ptr cmd = this->getCommand(args[0]);
		if (cmd == nullptr) {
			std::cout << args[0] << ": command not found\n";
		}
		else {
			args.erase(args.begin());
			output = (this->*cmd)(args);
			std::cout << (this->*cmd)(args) << (output.length() ? "\n": "");
		}
	}
}

std::string Shell::getCommandPrompt()
{
	std::string prompt =
		"\u001b[32m" // green
		+ this->storage.getCurrentNode()
		+ ":~"
		+ "\u001b[37m" // white
		+ "$ ";
	return prompt;
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

std::string Shell::_cd(arg_array args)
{
	if (args.size() < 1) {
		this->storage.changeNode(""); // back to root
		return "";
	}
	if (!this->storage.changeNode(args[0])) {
		return "cd: " + args[0] + ": No such node";
	}
	return "";
}

Shell::cmd_ptr Shell::getCommand(std::string cmd)
{
	std::transform(cmd.begin(), cmd.end(), cmd.begin(), std::tolower);
	std::map<std::string, cmd_ptr> commands	= {
		{
			"tree",
			&Shell::_tree
		},
		{
			"cd",
			&Shell::_cd
		},
		{
			"show",
			&Shell::_show
		},
		{
			"dir",
			&Shell::_dir
		},
		{
			"mo",
			&Shell::_makeObject
		},
		{
			"exit",
			&Shell::_exit
		},

	};
	// commands.insert({"testFunction", 5});
	if (commands.count(cmd)) {
		return commands.at(cmd);
	}
	return nullptr;
}

std::string Shell::_makeObject(arg_array args)
{
	if (args.size() < 1) {
		return "MO: object name not provided";
	}
	std::string currentNode = this->storage.getCurrentNode();
	if (this->storage.classes[currentNode].create) {
		Equipment<double>* object = (*this->storage.classes[currentNode].create)(args);
		this->storage.classes[currentNode].objects[args[0]] = object;
		return "Successfully create object of class " + currentNode;
	}
	else {
		return "MO: Can't create object of class " + currentNode;
	}
}

std::string Shell::_dir(arg_array args)
{
	return this->storage.tree(this->storage.getCurrentNode(), true);
}

std::string Shell::_show(arg_array args)
{
	if (args.size() < 1) {
		return "SHOW: Object name not provided";
	}
	if ((*this->storage.getObjects()).count(args[0]) == 0) {
		return "SHOW: Object " + args[0] + " not found";
	}
	return "===Object " + args[0] + "===\n" + (*this->storage.getObjects())[args[0]]->about();
}

std::string Shell::_exit(arg_array args)
{
	exit(0);
}
