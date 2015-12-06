#pragma once

#include <map>
#include "CommandMap.h"

class MinecraftClient;

class SimpleCommandMap : public CommandMap
{
protected:
	std::map<std::string, Command *> knownCommands;

public:
	SimpleCommandMap();

	virtual ~SimpleCommandMap();

	virtual bool registerCommand(Command *command, std::string const &label = "");
	virtual bool dispatch(SMPlayer *sender, std::string const &cmdLine);
	bool registerAlias(Command *command, bool isAlias, std::string const &label);

	void setDefaultCommands();

	void clearCommand();
	Command *getCommand(std::string const &name);
	std::map<std::string, Command *> getCommands();
};