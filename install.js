const os = require('os');
var spawn = require('cross-spawn');

if (os.platform() === 'win32') {
    spawn.sync('npm', ['run', 'compile'], {
        input: 'win32 detected. Build native module.',
        stdio: 'inherit'
    });
}