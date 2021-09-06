
const injector = require('dll-injector');

if (injector.isProcessRunning('notepad.exe')) {
    const error = injector.inject('notepad.exe', 'testdll.dll');

    if (!error) {
        console.log('Successfully injected!');
    } else {
        console.log('Injection failed. Error Code:', error);
    }
}