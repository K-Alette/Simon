#pragma once
#ifndef __GameObjectFactory__
#define __GameObjectFactory__

#include <string>
#include <map>
#include <iostream>

#include "GameObjects.h"

class BaseCreator //only purpose is to create specific object
{
public:
	virtual GameObjects* createGameObject() const = 0;
	virtual ~BaseCreator() {}
};

class GOFactory
{

private:

	static GOFactory* pInstance;

	//map holds important GOFactory elements, functions of this class will add/remove from this map
	std::map<std::string, BaseCreator*> m_creators;

public:

	static GOFactory* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new GOFactory();
		}

		return pInstance;
	}

	//function that takes ID associate to object type, and then finds the type 
	bool registerType(std::string typeID, BaseCreator* pCreator)
	{
		std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID); //find type using type ID

		// if the type is already registered, do nothing
		if (it != m_creators.end())
		{
			delete pCreator;
			return false;
		}

		m_creators[typeID] = pCreator; //if type not registered, register to map

		return true;
	}

	GameObjects* create(std::string typeID)
	{
		std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);

		if (it == m_creators.end())
		{
			std::cout << "could not find type: " << typeID << std::endl;
			return NULL;
		}

		BaseCreator* pCreator = (*it).second;
		return pCreator->createGameObject();
	}

};

typedef GOFactory TheGameObjectFactory;

#endif // __GameObjectFactory__