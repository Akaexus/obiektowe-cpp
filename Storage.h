#pragma once
#include <vector>
#include <map>
#include <string>
#include "Equipment.h"
class Storage
{
	protected:
		typedef Equipment<double>*(*class_fctry)(std::vector<std::string>);
		struct Node {
			Node* parent;
			std::string name;
			std::map<std::string, Equipment<double>*> objects;
			std::vector<Node*> children;
			//class_fctry create = nullptr;
		} Node;
		std::map<std::string, struct Node> classes;
		//typedef Equipment <double>(*)(Shell::arg_array) crt_fnct;
		//std::map<std::string, Equipment <double>(*)(std::vector<std::string>)> factories;
		std::string currentNode;
	public:
		Storage();
		bool changeNode(std::string nm);
		std::string getCurrentNode();
		std::string tree();
	private:
		std::string reccuringTree(struct Node* node, int level = 0);


		
};

