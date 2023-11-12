# Vector2f
You can use the `Vector2f` class to store 2D float coordinates 

## Properties

| Variable | Description | Example |
|----------|-------------|---------|
| X | First float in the class | 0.0 |
| Y | Second float in the class | 0.0 |

## Methods

### <span style="color: #3498db">Vector2f</span> Vector2f()
Default Constructor

Example:
```cpp
StirlingEngine::Vector2f foo();
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2f</span> Vector2f(<span style="color: #3498db">float</span> <span style="color: #7f8c8d;">x_in</span>, <span style="color: #3498db">float</span> <span style="color: #7f8c8d;">y_in</span>)
Pass in two <span style="color: #3498db">float</span> values floato the constructor, `x_in` and `y_in`. 

Example:
```cpp
StirlingEngine::Vector2f foo(0, 0);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2f</span> operator+(<span style="color: #3498db">Vector2f</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2f</span> class to add them together, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2f foo = StirlingEngine::Vector2f(200, 200) + StirlingEngine::Vector2f(50, 50); // Will return result Vector2f(250, 250);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2f</span> operator-(<span style="color: #3498db">Vector2f</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2f</span> class to subtract `rhs` from `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2f foo = StirlingEngine::Vector2f(200, 200) - StirlingEngine::Vector2f(50, 50); // Will return result Vector2f(150, 150);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2f</span> operator*(<span style="color: #3498db">Vector2f</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2f</span> class to multiply `rhs` to `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2f foo = StirlingEngine::Vector2f(200, 200) * StirlingEngine::Vector2f(2, 2); // Will return result Vector2f(400, 400);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">Vector2f</span> operator*(<span style="color: #3498db">float</span> <span style="color: #7f8c8d;">scale</span>)
Pass in an <span style="color: #3498db">float</span> to scale the `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2f foo = StirlingEngine::Vector2f(200, 200) * 2; // Will return result Vector2f(400, 400);
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">void</span> operator+=(<span style="color: #3498db">Vector2f</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2f</span> class to add to `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2f foo(200, 200);
foo += StirlingEngine::Vector2f(100, 100);
// foo will now be Vector2f(300, 300)
```

<hr style="background: #e74c3c;">

### <span style="color: #3498db">void</span> operator-=(<span style="color: #3498db">Vector2f</span> <span style="color: #7f8c8d;">rhs</span>)
Pass in a <span style="color: #3498db">Vector2f</span> class to subract form `x` and `y`, returns the calculation result. 

Example:
```cpp
StirlingEngine::Vector2f foo(200, 200);
foo -= StirlingEngine::Vector2f(100, 100);
// foo will now be Vector2f(100, 100)
```

<hr style="background: #e74c3c;">