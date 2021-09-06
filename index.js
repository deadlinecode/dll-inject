if (process.platform !== 'win32') return;
var injector = require('bindings')('injector');
module.exports = injector;
