#include "uuid.hpp"
uuid::UUID::UUID(const uint32_t a, const uint32_t b, const uint32_t c, const uint32_t d)
{
	this->value = new uint32_t[4];
	this->value[0] = a;
	this->value[1] = b;
	this->value[2] = c;
	this->value[3] = d;
};

uuid::UUID& uuid::UUID::operator=(const uuid::UUID& x)
{
	this->value[0] = x.value[0];
	this->value[1] = x.value[1];
	this->value[2] = x.value[2];
	this->value[3] = x.value[3];

	return *this;
};
