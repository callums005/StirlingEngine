# Game

## Member Objects

`m_Window` stores a pointer to the Window class.
```cpp
Window* m_Window;
```

---

## Constructor
```cpp
Game();
```

## Deconstructor
```cpp
~Game();
```

## Member Functions
`Run()` is called when the application starts.

**Paramaters:** `None`

**Returns:** `void` 

```cpp
bool Run();
```
---
`SetWindow()` is called by the entry point to create the window.

**Paramaters:** `None`

**Returns:** `void` 

```cpp
void SetWindow();
```
---
`OnStart()` is called on the client side when the engine starts.

**Paramaters:** `None`

**Returns:** `void` 

```cpp
virtual void OnStart() = 0;
```

---
`OnUpdate()` is called each frame of the engine on the client side.

**Paramaters:** `None`

**Returns:** `void` 

```cpp
virtual void OnStart() = 0;
```

---
`OnExit()` is called when the window closes.

**Paramaters:** `None`

**Returns:** `void` 

```cpp
virtual void OnExit() = 0;
```

---
`CreateGame()` is defined externally on the game side allowing you to create custom game classes.

**Paramaters:** `None`

**Returns:** `Game*` 

```cpp
Game* CreateGame(); // Defined on the game side
```

Defining `CreateGame()` on the game side:
```cpp
StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new NewGame();
}
```

## Extending the `Game` class

First, create a directory in the root directory called `src`

```bash
mkdir src
```

Second, create a file called `main.cpp` inside the `src` directory
```bash
touch src/main.cpp
```

Open the file and include `StirlingEngine.h`, this will give you access to all the functions and classes within the engine

```cpp
#include "StirlingEngine.h"
```

Create a class with another name than `Game`, in this example we will use `Sandbox`. Make sure to inherit from the `StirlingEngine::Game` class with a constructor and deconstructor
```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox() {}
	~Sandbox() {}
};
```

Define the `OnStart`, `OnUpdate`, `OnExit` virtual functions
```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox() {}
	~Sandbox() {}

	// OnStart called when the game starts
	void OnStart() {}
	// OnUpdate is called each frame
	void OnUpdate() {}
	// OnExit is called when the game closes
	void OnExit() {}
};
```

Finally, define the `CreateGame` function **OUTSIDE** of the class you created
```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox() {}
	~Sandbox() {}

	// OnStart called when the game starts
	void OnStart() {}
	// OnUpdate is called each frame
	void OnUpdate() {}
	// OnExit is called when the game closes
	void OnExit() {}
};

// Declared on the engine side
StirlingEngine::Game* StirlingEngine::CreateGame()
{
	return new Sandbox();
}
```