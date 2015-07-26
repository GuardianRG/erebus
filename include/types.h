#pragma once

#include <vector>
#include <stdint.h>
#include <string>

/**
 * unsigned byte.
 */
typedef uint8_t	byte;
/**
 * signed byte.
 */
typedef int8_t	sbyte;

/**
 * vector to hold unsigned bytes.
 */
typedef std::vector<byte> binVec;

class BoolStr {
  public:
	static const std::string STRUE;
	static const std::string SFALSE;

	static bool toBool(std::string str);
	static std::string toStr(bool b);
};
