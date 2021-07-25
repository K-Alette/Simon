#pragma once
#ifndef __StateParser__
#define __StateParser__

#include <iostream>
#include <vector>
#include "tinyxml.h"

class GameObjects;

class StateParser
{
private:
	void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObjects*>* pObjects);
	void parseTextures(TiXmlElement* psStateRoot, std::vector<std::string>* pTextureIDs);

public:
	bool parseState(const char* stateFile, std::string stateID, std::vector<GameObjects*>* pObjects, std::vector<std::string>* pTextureIDs);
};

#endif /* defined(__StateParser__) */