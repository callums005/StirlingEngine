# Window

## Member Objects

`x` stores the first integer value in the vector.
```cpp
int x;
```

---
`y` stores the second integer value in the vector.
```cpp
int y;
```


## Constructor
```cpp
Vector2i(int x_in, int y_in);
```

## Deconstructor
```cpp
~Vector2i();
```

## Member Functions
`operator+()` is used to add vectors togeather.

**Paramaters:** `const Vector2i&`

**Returns:** `Vector2i`

```cpp
Vector2i operator+(const Vector2i &rhs) const;
```

---
`operator-()` is used to subtract vectors togeather.

**Paramaters:** `const Vector2i&`

**Returns:** `Vector2i`

```cpp
Vector2i operator-(const Vector2i &rhs) const;
```

---
`operator*()` is used to scale the vector.

**Paramaters:** `const int`

**Returns:** `Vector2i`

```cpp
Vector2i operator*(const int scale) const;
```

---
`operator*()` is used to multiple Vectors togeather.

**Paramaters:** `const Vector2i&`

**Returns:** `Vector2i`

```cpp
Vector2i operator*(const Vector2i &rhs) const;
```

---
`operator+=()` is used to add to the vector.

**Paramaters:** `const Vector2i&`

**Returns:** `void`

```cpp
void operator+=(const Vector2i &rhs) const;
```

---
`operator-=()` is used to subtract to the vector.

**Paramaters:** `const Vector2i&`

**Returns:** `void`

```cpp
void operator-=(const Vector2i &rhs) const;
```

---