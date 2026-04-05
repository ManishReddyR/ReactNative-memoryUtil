# react-native-memory-utils

A lightweight React Native utility for accessing and monitoring memory usage on mobile devices.

## Overview

react-native-memory-utils provides a simple and efficient way to access device and app memory usage using native capabilities on both Android and iOS.

Built for performance-focused applications, debugging, and monitoring scenarios.

## Features

* Get real-time memory usage
* Monitor app memory consumption
* Lightweight and fast
* Easy integration with React Native

## Installation

```bash
npm install react-native-memory-utils
# or
yarn add react-native-memory-utils
```

## Linking

For React Native 0.60 and above, autolinking is supported.

For older versions:

```bash
react-native link react-native-memory-utils
```

## Usage

```javascript
import { getMemoryUsage } from 'react-native-memory-utils';

const memory = await getMemoryUsage();
console.log(memory);
```

### Example Response

```json
{
  "totalMemory": 4096,
  "usedMemory": 1024,
  "freeMemory": 3072
}
```

## API

### `getMemoryUsage()`

Returns:

| Field       | Type   | Description              |
| ----------- | ------ | ------------------------ |
| totalMemory | number | Total device memory (MB) |
| usedMemory  | number | Memory used by app (MB)  |
| freeMemory  | number | Available memory (MB)    |

## Platform Support

* ✅ Android
* ✅ iOS

## Example Use Cases

* Performance monitoring
* Debugging memory leaks
* Optimizing app performance

## Contributing

Contributions are welcome! Please open an issue or submit a pull request.

## Author

Manish Reddy Rakasi

---

⭐ If you find this useful, consider giving it a star!
