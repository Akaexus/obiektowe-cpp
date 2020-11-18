#include "Shell.h"
#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>
#include <fstream>

void Shell::run()
{
	while (true) {
		std::vector<std::string> args = this->inputCommand();
		std::cout << this->runCommand(args);
	}
}

std::string Shell::runCommand(std::vector<std::string> args)
{
	std::string output;
	Shell::cmd_ptr cmd = this->getCommand(args[0]);
	if (cmd == nullptr) {
		return args[0] + ": command not found\n";
	}
	else {
		args.erase(args.begin());
		output = (this->*cmd)(args);
		if (output.length()) {
			output += "\n";
		}
	}
	return output;
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
			"do",
			&Shell::_deleteObject
		},
		{
			"mo",
			&Shell::_makeObject
		},
		{
			"mdo",
			&Shell::_modifyObject
		},
		{
			"save",
			&Shell::_save
		},
		{
			"read",
			&Shell::_read
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
		args.erase(args.begin());
		object->importData(args);
		return "Successfully create object of class " + currentNode;
	}
	else {
		return "MO: Can't create object of class " + currentNode;
	}
}

std::string Shell::_modifyObject(arg_array args)
{
	if (args.size() < 1) {
		return "MDO: Object name not provided";
	}
	std::map<std::string, Equipment<double>*>* objects = this->storage.getObjects();
	if ((*objects).count(args[0]) == 0) {
		return "MDO: Object " + args[0] + " not found";
	}
	std::vector<std::string> data = (*objects)[args[0]]->exportData();
	std::vector<std::string> attribNames = (*objects)[args[0]]->getAttribNames();
	std::string input;
	for (int i = 0; i < data.size(); i++) {
		std::cout << attribNames[i] << " [" << data[i] << "]: ";
		getline(std::cin, input);
		if (!input.empty()) {
			data[i] = input;
		}
	}
	(*objects)[args[0]]->importData(data);
	return "";
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

std::string Shell::_save(arg_array args)
{
	if (args.size() < 1) {
		return "SAVE: Filename not provided";
	}
	std::string dump = this->storage.dump();
	std::ofstream f;
	f.open(args[0]);
	f << dump;
	f.close();
	return "Database successfully dumped";
}

std::string Shell::_read(arg_array args)
{
	if (args.size() < 1) {
		return "READ: Filename not provided";
	}
	std::string line;
	std::ifstream f;
	f.open(args[0]);
	while (std::getline(f, line)) {
		std::vector<std::string> args = this->splitCommand(line);
		std::cout << this->runCommand(args);
	}
	return "";
}

std::string Shell::_deleteObject(arg_array args)
{
	if (args.size() < 1) {
		return "DO: Object name not provided";
	}
	std::string objName = args[0];
	std::map<std::string, Equipment<double>*>* objects = this->storage.getObjects();
	if ((*objects).count(args[0]) == 0) {
		return "DO: Object " + args[0] + " not found";
	}
	Equipment<double>* obj = (*objects)[args[0]];
	free(obj);
	(*objects).erase(args[0]);
	return "Object " + args[0] + " succesfully deleted";
	
}

std::string Shell::_exit(arg_array args)
{
	exit(0);
}
