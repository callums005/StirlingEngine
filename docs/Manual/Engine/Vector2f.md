# Window

## Member Objects

`x` stores the first float value in the vector.
```cpp
float x;
```

---
`y` stores the second float value in the vector.
```cpp
float y;
```


## Constructor
```cpp
Vector2f(float x_in, float y_in);
```

## Deconstructor
```cpp
~Vector2f();
```

## Member Functions
`operator+()` is used to add vectors togeather.

**Paramaters:** `const Vector2f&`

**Returns:** `Vector2f`

```cpp
Vector2f operator+(const Vector2f &rhs) const;
```

---
`operator-()` is used to subtract vectors togeather.

**Paramaters:** `const Vector2f&`

**Returns:** `Vector2f`

```cpp
Vector2f operator-(const Vector2f &rhs) const;
```

---
`operator*()` is used to scale the vector.

**Paramaters:** `const float`

**Returns:** `Vector2f`

```cpp
Vector2f operator*(const float scale) const;
```

---
`operator*()` is used to multiple Vectors togeather.

**Paramaters:** `const Vector2f&`

**Returns:** `Vector2f`

```cpp
Vector2f operator*(const Vector2f &rhs) const;
```

---
`operator+=()` is used to add to the vector.

**Paramaters:** `const Vector2f&`

**Returns:** `void`

```cpp
void operator+=(const Vector2f &rhs) const;
```

---
`operator-=()` is used to subtract to the vector.

**Paramaters:** `const Vector2f&`

**Returns:** `void`

```cpp
void operator-=(const Vector2f &rhs) const;
```

---