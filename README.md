# matn.h

A small header only compile time Matrix object for use with OpenGL.

## Data Representation

OpenGL matrices are 16-value arrays with base vectors laid out contiguously in memory. The translation components occupy the 12th, 13th, and 14th elements of the 16-element matrix.

## Compile template functions

All matrix template functions are expanded during compile time.

To add a new matrix type and size, simply add a type definition to the bottom of `matn.h`. This will compile the template functions for a specific size and type.

```
typedef matn<float, 4> mat4f;
```

To add additional functionality create an object that inherits from matn. To see a full example check out `mat4.h`.

```
#include "matn.h"

template <typename T>
class mat4 : public matn<T, 4> {
// constructors
public:
	inline mat4() = default;
	inline mat4(const matn<T, 4>& m) : matn<T, 4>(m) {}

}; // mat4

// compile template functions
typedef mat4<float> mat4f;
```

## Constructors

### matn

Creates a new identity Matrix (default).

### matn(const matn& v)

Creates a new Matrix from another Matrix (copy constructor).

## Operators

# operator const T* ()

Points to the Matrix data.

# operator []

Access an element in the Matrix.

# operator =

Assign a Matrix to another Matrix.

# operator *

Multiply this Matrix by another Matrix to form a new Matrix.

# operator *=

Multiply this Matrix by another Matrix.

## Static Functions

### identity

Creates a new Identity Matrix;
