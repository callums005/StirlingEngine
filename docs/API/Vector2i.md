# Vector2i
You can use the `Vector2i` class to store 2D integer coordinates 

## Properties

| Variable | Description | Example |
|----------|-------------|---------|
| X | First integer in the class | 0 |
| Y | Second integer in the class | 0 |

## Methods

### <span style="color: #3498db">Vector2i</span> Vector2i()
Default Constructor

Example:
```cpp
StirlingEngine::Vector2i foo();
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2i</span> Vector2i(<span style="color: #3498db">int</span> <span style="color: #7f8c8d;">x_in</span>, <span style="color: #3498db">int</span> <span style="color: #7f8c8d;">y_in</span>)
Pass in two <span style="color: #3498db">integer</span> values into the constructor, `x_in` and `y_in`. 

Example:
```cpp
StirlingEngine::Vector2i foo(0, 0);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2i</span> operator+(<span style="color: #3498db">Vector2i</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2i</span> class to add them together, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2i foo = StirlingEngine::Vector2i(200, 200) + StirlingEngine::Vector2i(50, 50); // Will return result Vector2i(250, 250);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2i</span> operator-(<span style="color: #3498db">Vector2i</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2i</span> class to subtract `rhs` from `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2i foo = StirlingEngine::Vector2i(200, 200) - StirlingEngine::Vector2i(50, 50); // Will return result Vector2i(150, 150);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2i</span> operator*(<span style="color: #3498db">Vector2i</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2i</span> class to multiply `rhs` to `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2i foo = StirlingEngine::Vector2i(200, 200) * StirlingEngine::Vector2i(2, 2); // Will return result Vector2i(400, 400);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2i</span> operator*(<span style="color: #3498db">int</span> <span style="color: #7f8c8d;">scale</span>)
Pass in an <span style="color: #3498db">int</span> to scale the `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2i foo = StirlingEngine::Vector2i(200, 200) * 2; // Will return result Vector2i(400, 400);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">void</span> operator+=(<span style="color: #3498db">Vector2i</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2i</span> class to add to `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2i foo(200, 200);
foo += StirlingEngine::Vector2i(100, 100);
// foo will now be Vector2i(300, 300)
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">void</span> operator-=(<span style="color: #3498db">Vector2i</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2i</span> class to subract form `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2i foo(200, 200);
foo -= StirlingEngine::Vector2i(100, 100);
// foo will now be Vector2i(100, 100)
```

<hr style="background: #e74c3c;">