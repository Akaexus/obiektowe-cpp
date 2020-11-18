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
			class_fctry create = nullptr;
		} Node;
		//typedef Equipment <double>(*)(Shell::arg_array) crt_fnct;
		//std::map<std::string, Equipment <double>(*)(std::vector<std::string>)> factories;
		std::string currentNode;
		std::string rootNode;
		static std::string join(std::vector<std::string> v);
	public:
		Storage();
		bool changeNode(std::string nm);
		std::string getCurrentNode();
		std::string tree(std::string base = "", bool includeObjects = false);
		std::map<std::string, struct Node> classes;
		std::map<std::string, Equipment<double>*>* getObjects();
		std::string dump();
	private:
		std::string reccuringTree(struct Node* node, bool includeObjects = false, int level = 0);



		
};

