#pragma once

#include "entity.h"

class Builder {
public:
	virtual Entity* build();
};