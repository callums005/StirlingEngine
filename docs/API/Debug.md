# Debug
The debug system allows you to easily debug your game.

You can print text to the console using the `Log` function:

```cpp
StirlingEngine::Debug::Log("Hello World!");
```

Expected output
```
[INFO] Hello World!
```

You can also specify how you want the application to display the message:

#### Info Level:

```cpp
StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Info, "Example Info Level");
```

Expected output
```
[INFO] Example Info Level
```

#### Debug Level:

```cpp
StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Debug, "Example Debug Level");
```

Expected output
```
[DEBUG] Example Debug Level
```

#### Warning Level:

```cpp
StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Warning, "Example Warning Level");
```

Expected output
```
[WARNING] Example Warning Level
```

#### Error Level:

```cpp
StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Error, "Example Error Level");
```

Expected output
```
[ERROR] Example Error Level
```

#### Critical Level:

```cpp
StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Critical, "Example Critical Level");
```

Expected output
```
[CRITICAL] Example Crittical Level
```

## Custom log messages

You can easily concatinate variables into the message string using format specifiers.

For example, to output 5 + 5, you would use the following code:

```cpp
StirlingEngine::Debug::Log("5 + 5 = %i", (5 + 5));
```

The output would be:
```
[INFO] 5 + 5 = 10
```

#### List of specifiers

| Specifier | Output | Example |
| --------- | ------ | ------- |
| d **or** i | Signed decimal integer | 392 |
| u | Unsigned decimal integer | 7235 |
| x | Unsigned hexadecimal integer, lowercase | 7fa |
| X | Unsigned hexadecimal integer, uppercase | 7FA |
| f | Decimal floating point | 392.65 |
| e | Scientific notation with mantissa and exponent, lowercase | 3.9265e+2 |
| E | Scientific notation with mantissa and exponent, uppercase | 3.9265E+2 |
| c | Character | a |
| s | String of characters (character array, not std::string) | example |
| p | Pointer address | b800000 |
| % | A % followed by another % (%%) will print a single percent sign (%) | % | 

You can find a full list of specifiers [here](https://cplusplus.com/reference/cstdio/printf/).