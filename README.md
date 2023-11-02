# StirlingEngine

## Purpose
This is a 2 Dimentional Game Engine programmed in C++ using the Simple and Fast Multimedia Platform ([SFML](https://www.sfml-dev.org/)).

## Roadmap
```mermaid
graph TD;
  Merge("Migrate Pre-existing C# engine code to C++");
  Merge --> Docs1("Write Documentation for existing code");
  Docs1 --> Texture("2D Texture Rendering");
  Texture --> Physics("Physics Engine - Box2D");
  Physics --> Scenes("Scene System");
  Scenes --> UI("UI Library");
  UI --> Sound("Sound System");
  Sound --> Particle("Particle System");
  Particle -->  Network("Networking Support");
```
## Getting Started
### [Compiling Documentation](docs/COMPILING.md)
A step-by-step documentation on compiling the Stirling Engine
### [Documentation](docs/Manual/Documentation.md)
Full documentation for the engine and API

## Contributing
The Stirling Engine project would love your contribution, please read the [CONTRIBUTING.md](docs/CONTRIBUTING.md)