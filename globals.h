#pragma once
#include <unordered_map>
#include <string>

class c_globals {
public:
	bool active = true;
	char user_name[255];
	char pass_word[255];
	char license[255];
	std::string version = "v1.0";
};

inline c_globals globals;