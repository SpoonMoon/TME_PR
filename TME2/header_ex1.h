#pragma once

#include "List.h"
#include "Vector.h"


template< template<typename> class Container, typename T>
void show_const (const Container<T> & vec);

template< template<typename> class Container, typename T>
void show (Container<T> & vec);

template< template<typename> class Container, typename T>
int test (Container<T> & vec);

int main_t ();
