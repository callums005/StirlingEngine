# Window

## Member Objects

`m_Window` stores a pointer to the SFML graphics window.
```cpp
sf::RenderWindow* m_Window;
```

---

`m_Width` stores an unsigned integer of the window's width.
```cpp
uint m_Width;
```

---

`m_Height` stores an unsigned integer of the window's height.
```cpp
uint m_Height;
```

`m_Title` stores a string of the window's title.
```cpp
std::string m_Width;
```

## Constructor
```cpp
Window(uint width, uint height, std::string title);
```

## Deconstructor
```cpp
~Window();
```

## Member Functions
`IsOpen()` is used to check if the window is still open.

**Paramaters:** `None`

**Returns:** `bool` 

```cpp
bool IsOpen();
```

---

`Render()` is called each frame to render entities to the screen.

**Paramaters:** `None`

**Returns:** `void`

```cpp
void Render();
```

---

`PollEvent()` is used to poll SFML events.

**Paramaters:** `sf::Event&`

**Returns:** `bool` 

```cpp
bool PollEvent(sf::Event& event);
```

---
`Close()` is used to close the window.

**Paramaters:** `None`

**Returns:** `void` 

```cpp
void Close();
```

---

`GetSize()` is used to get the width and height of the window.

**Paramaters:** `None`

**Returns:** `std::pair<uint, uint>`

```cpp
std::pair<uint, uint> GetSize();
```

---

`GetTitle()` is used to get the title of the window.

**Paramaters:** `None`

**Returns:** `std::string`

```cpp
std::string GetTitle();
```

