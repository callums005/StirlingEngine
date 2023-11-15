# Stirling Engine : 2D
## Getting Started

### Preamble
This short tutorial will teach you the basic sets to setting up the engine for the first time, coverting:
1. [Requrements](#1-requirements)
2. [Downloading the engine](#2-downloading-the-engine)
3. [Using the initial class](#3-using-the-initial-class)
4. [Using the input system](#4-using-the-input-system)
5. [Printing text to the console using the input system](#5-printing-text-to-the-console-using-the-input-system)
6. [Building and compiling](#6-building-and-compiling)


### 1. Requirements

- Git (to download the engine source)
- CMake (to build the engine)
- Text Editor/IDE (to write your own code!)

### 2. Downloading the engine

You can clone the repository or download directly from github. In this tutorial we will clone the repository as it will make it easier to update the engine.

First, create a directory wherever you want, for me it will go in my `home/dev` directory (`~/dev` on linux, `C:\users\examp\dev`):
```bash
mkdir MyFirstSE2DProject
```

Next you should initalise a git folder:
```bash
git init
```

Next clone the repository to your local machine:
```bash
git clone https://github.com/callums005/StirlingEngine.git
```

Finally you should open the folder in any text editor or IDE you desire. For VS Code simply execute this command in the terminal:
```bash
code .
```

Now you have the most recent version of the engine.

### 3. Using the initial class

To write your own game, you can create your own class that derives from `StirlingEngine::Game`, we have a default class in the project already, simply open the `src/main.cpp` file, it should look like this:
```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}

	void OnStart()
	{
	}

	void OnUpdate()
	{
	}

	void OnExit() 
	{
	}
};

// Defined engine side
StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new Sandbox();
}
```

Lets break this down into 3 parts: Includes; Derived Class; External function.

#### Includes
```cpp
#include "StirlingEngine.h"
```

To gain access to the full engine API, you should include the `StirlingEngine.h` header file. You can also manually include files from the engine, for example, to include the `Game` class:
```cpp
#include "Game.h"
```

However we do not recommend this for first time users.

#### Derived Class
The dervied class can be called whatever you'd like, here we have called it `Sandbox` we recommend calling it the name of your project. You must ensure the class you create derives from the `StirlingEngine::Game` base class:
```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
};
```

Next the class must have a constructor and deconstructor, this is where you can set engine settings such as a custom window and enable debugging tools:
```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};
```

To set a custom window, you can use the `SetWindow` function inside the constructor:
```cpp
SetWindow(500, 500, "Sandbox");
```

```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
		SetWindow(500, 500, "Sandbox");
	}

	~Sandbox()
	{
	}
};
```

You can enable the debugging flag by setting `DebugUIFlag` to `true`:
```cpp
DebugUIFlag = true;
```

```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
		DebugUIFlag = true;
	}

	~Sandbox()
	{
	}
};
```


Next you must define 3 functions virtual functions `OnStart`, `OnUpdate` and `OnExit`. As the names suggest, `OnStart` is called at the start of the game loop, `OnUpdate` is called each frame and `OnExit` is called at the end of the game loop:

```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
		SetWindow(500, 500, "Sandbox");
	}

	~Sandbox()
	{
	}

	void OnStart()
	{
	}

	void OnUpdate()
	{
	}

	void OnExit() 
	{
	}	
};
```

#### External Function

To use this custom class with the game engine, we must define an extern function called `CreateGame()` that returns a new instance of the class you created:
```cpp
StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new Sandbox();
}
```

You must **MUST** make sure this is at the bottom of the file otherwise this will not work.

The final file should look like this:
```cpp
#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
		SetWindow(500, 500, "Sandbox");
	}
	~Sandbox()
	{
	}

	void OnStart()
	{
	}

	void OnUpdate()
	{
	}

	void OnExit() 
	{
	}
};

StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new Sandbox();
}
```

### 4. Using the input system

To get mouse and keyboard input you can use the `Input` class.

In this example we will check if the `space bar` is pressed down:
```cpp
void OnUpdate()
{
	if (StirlingEngine::Input::IsKeyDown(StirlingEngine::Key::KEY_SPACE))
		// Do stuff
}
```

### 5. Printing text to the console using the input system
One of the easiest ways to check if something is working is via the `Log` function in the `Debug` class, this will simply print text to the console, building on the use of the input system in the previous tutorial, we will now use the `Log` function to display `Hello World!` to the console when the space key is pressed:
```cpp
void OnUpdate()
{
	if (StirlingEngine::Input::IsKeyDown(StirlingEngine::Key::KEY_SPACE))
		StirlingEngine::Debug::Log("Hello World!");
}
```

### 6. Building and compiling

Now we have something to build and run we can head back to the terminal.

To create the `CMake` build files run this command in the terminal:
```bash
cmake -B build/
```

Once the build files have been made, we can run the build command to create the executable:
```bash
cmake --build build/
```

Once this has completed we can run the executable inside `build/bin/`.

### Now test the game!
When the window is focused, pressing the `spacebar` should print `Hello World!` out to the console, you might need to move the console to the side so it is not under the game window.