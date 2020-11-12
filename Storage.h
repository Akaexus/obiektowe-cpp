#pragma once
#include <vector>
#include <map>
#include <string>
#include "Equipment.h"
class Storage
{
	protected:
		struct Node {
			Node* up;
			std::string name;
			std::map<std::string, Equipment<double>> objects;
			Node* down;
		} Node;
		typedef struct Node Node;
		std::map<std::string, struct Node> classes;

	public:
		Storage();
		
};

