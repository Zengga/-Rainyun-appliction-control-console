#pragma once

#include <optional>
#include <stdexcept>
#include <regex>

class Header {
public:
	Header() = default;
	virtual ~Header() = default;

private:
	std::string x_api_key;

public:
	const std::string & get_x_api_key() const { return x_api_key; }
	std::string & get_mutable_x_api_key() { return x_api_key; }
	void set_x_api_key(const std::string & value) { this->x_api_key = value; }
};