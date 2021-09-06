# dll-inject

Native node addon for dll injection in windows.

Requires a working `node-gyp` setup to compile the native addon.
<br />
<br />

## Installation

Simply add `dll-inject` as a dependency in the package.json of your NodeJs Project:
```bash
npm install dll-inject
```
<br />

## Usage

### By process name

```javascript
const injector = require('dll-inject');

if (injector.isProcessRunning('notepad.exe')) {
    const error = injector.inject('notepad.exe', 'mydll.dll');

    if (!error) {
        console.log('Successfully injected!');
    } else {
        console.log('Injection failed. Error Code:', error);
    }
}
```

### By process id
```javascript
const injector = require('dll-inject');

if (injector.isProcessRunningPID(1234)) {
    const error = injector.injectPID(1234, 'mydll.dll');

    if (!error) {
        console.log('Successfully injected!');
    } else {
        console.log('Injection failed. Error Code:', error);
    }
}
```
<br />

## Error Codes
These codes are returned by the `inject()` and `injectPID()` functions as integer values

Int | Error
------------ | -------------
0 | Injection Successfull
1 | Process is not open
2 | Getting path name failed
3 | Buffer too small for path name
4 | Failed to allocate memory
5 | Failed to write memory
6 | Failed to create remote thread to load the DLL
<br />

## Testing
There is a testdll.dll in the package folder of this project which will just open a new window from the process it was injected in which tells you when the dll is loaded and unloaded. There is also already a test js file in the test folder that you can run with `npm test` (be aware that for this to work notepad needs to be running and you are inside the package folder when executing `npm test`)
<br />
<br />

## Inspiration
This package is inspired by the popular package [node-dll-injector](https://github.com/mcoot/node-dll-injector) from [mcoot](https://github.com/mcoot).
Since it looked like he discontinued working on the package in 2019 i basically rewrote the whole node native addon with the new v8 api that node-gyp and node js are using and with the new nan package changes. The core mechanic is the same as in the package from @mcoot. So thanks a lot to him ^-^.

<br />
Coded with ❤ by h110m