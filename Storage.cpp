
#include <iostream>
#include <sstream>
#include "Storage.h"
#include "Shell.h"
#include "Equipment.h"
#include "Audio.h"
#include "Visual.h"
#include "TapeRecorder.h"
#include "CDPlayer.h"
#include "Radio.h"
#include "TV.h"
#include "PortableTV.h"
#include "StationaryTV.h"
#include "Camera.h"
#include "VideocasetteRecorder.h"

Storage::Storage()
{
	this->classes.insert({
		"Equipment", // key
		{
			nullptr, // parent
			"Equipment", // name
			{}, // objects
			{} // children 
		}
	});
	this->classes.insert({
		"Audio", // key
		{
			&this->classes["Equipment"], // parent
			"Audio", // name
			{}, // objects
			{}, // children
		}
	});

	this->classes.insert({
	"Visual", // key
	{
		&this->classes["Equipment"], // parent
		"Visual", // name
		{}, // objects
		{}, // children
	}
		});

	this->classes.insert({
		"TapeRecorder", // key
		{
			&this->classes["Audio"], // parent
			"TapeRecorder", // name
			{}, // objects
			{}, // children
			&TapeRecorder::create
		}
	});

	this->classes.insert({
		"CDPlayer", // key
		{
			&this->classes["Audio"], // parent
			"CDPlayer", // name
			{}, // objects
			{}, // children
			&CDPlayer::create
		}
	});

	this->classes.insert({
		"Radio", // key
		{
			&this->classes["Audio"], // parent
			"Radio", // name
			{}, // objects
			{}, // children
			&Radio::create
		}
	});

	this->classes.insert({
		"TV", // key
		{
			&this->classes["Visual"], // parent
			"TV", // name
			{}, // objects
			{}, // children
		}
	});

	this->classes.insert({
		"PortableTV", // key
		{
			&this->classes["TV"], // parent
			"PortableTV", // name
			{}, // objects
			{}, // children
			&PortableTV::create
		}
	});

	this->classes.insert({
		"StationaryTV", // key
		{
			&this->classes["TV"], // parent
			"StationaryTV", // name
			{}, // objects
			{}, // children
			&StationaryTV::create
		}
	});

	this->classes.insert({
		"Camera", // key
		{
			&this->classes["Visual"], // parent
			"Camera", // name
			{}, // objects
			{}, // children
			&Camera::create
		}
	});

	this->classes.insert({
		"VideocasetteRecorder", // key
		{
			&this->classes["Visual"], // parent
			"VideocasetteRecorder", // name
			{}, // objects
			{}, // children
			&VideocasetteRecorder::create
		}
	});
	this->classes["Equipment"].children.push_back(&this->classes["Audio"]);
	this->classes["Equipment"].children.push_back(&this->classes["Visual"]);

	this->classes["Audio"].children.push_back(&this->classes["TapeRecorder"]);
	this->classes["Audio"].children.push_back(&this->classes["CDPlayer"]);
	this->classes["Audio"].children.push_back(&this->classes["Radio"]);
	this->classes["Audio"].children.push_back(&this->classes["TV"]);

	this->classes["Visual"].children.push_back(&this->classes["TV"]);
	this->classes["Visual"].children.push_back(&this->classes["Camera"]);
	this->classes["Visual"].children.push_back(&this->classes["VideocasetteRecorder"]);

	this->classes["TV"].children.push_back(&this->classes["PortableTV"]);
	this->classes["TV"].children.push_back(&this->classes["StationaryTV"]);

	// set current node to root node
	this->rootNode = this->classes.begin()->first;
	while (this->classes[rootNode].parent != nullptr) {
		this->rootNode = this->classes[rootNode].parent->name;
	}
	this->changeNode(this->rootNode);
}

bool Storage::changeNode(std::string nm)
{
	if (this->classes.count(nm)) {
		this->currentNode = nm;
		return true;
	}
	else if (nm == "") {
		this->changeNode(this->rootNode);
	}
	return false;
}

std::string Storage::getCurrentNode()
{
	return this->currentNode;
}

std::string Storage::tree(std::string base, bool includeObjects)
{
	if (base == "") {
		base = this->rootNode;
	}
	return this->reccuringTree(&this->classes[base], includeObjects);
}

std::map<std::string, Equipment<double>*>* Storage::getObjects()
{
	return &this->classes[this->getCurrentNode()].objects;
}



std::string Storage::reccuringTree(struct Node* node, bool includeObjects, int level)
{
	std::stringstream s;
	if (!includeObjects) {
		for (int i = 0; i < (level * 3); i++) {
			s << " ";
		}
	}
	s << node->name << "\n";
	if (includeObjects) {
		if (this->classes[node->name].objects.size()) {
			for (std::map<std::string, Equipment<double>*>::iterator it = this->classes[node->name].objects.begin();
				it != this->classes[node->name].objects.end(); it++) {
				s << "  * " << it->first << "\n";
			}
		}
		else {
			s << "  No objects found!\n";
		}
	}
	for (int i = 0; i < node->children.size(); i++) {
		s << this->reccuringTree(node->children[i], includeObjects, level + 1);
	}
	return s.str();
}
