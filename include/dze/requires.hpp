#pragma once

#include <type_traits>

// Could be used in template prototypes to match the signature without the default value.
#define DZE_REQUIRES_PROTO(...) std::enable_if_t<__VA_ARGS__, int>

// Variadic macro needed because of potential commas in the macro argument.
#define DZE_REQUIRES(...) DZE_REQUIRES_PROTO(__VA_ARGS__) = 0
