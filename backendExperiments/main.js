/* Jonathan Sekela
 * 4/22/2016
 * javascripts for backendExperiments with c++ and nodeJS
 */


'use strict';

const electron = require('electron');
const app = electron.app;  // Module to control application life.
const BrowserWindow = electron.BrowserWindow;  // Module to create native browser window.
const ipcMain=require('electron').ipcMain;  //I THINK this handles comms between windows


// Keep a global reference of the window object, if you don't, the window will
// be closed automatically when the JavaScript object is garbage collected.
var mainWindow = null;

// Quit when all windows are closed.
app.on('window-all-closed', function() {
  // On OS X it is common for applications and their menu bar
  // to stay active until the user quits explicitly with Cmd + Q
  if (process.platform != 'darwin') {
    app.quit();
  }
});

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
app.on('ready', function() {
  // Create the browser window.
  mainWindow = new BrowserWindow({width: 1400, height: 900});

  // and load the index.html of the app.
  mainWindow.loadURL('file://' + __dirname + '/index.html');

  // Open the DevTools.
  //mainWindow.webContents.openDevTools();

  // Emitted when the window is closed.
  mainWindow.on('closed', function() {
    // Dereference the window object, usually you would store windows
    // in an array if your app supports multi windows, this is the time
    // when you should delete the corresponding element.
    mainWindow = null;
  });
});

function hello()
{
  const spawn = require('child_process').spawn;
  const hello = spawn('c++/hello.exe', ['-lh', '/usr']);

  hello.stdout.on('data', (data) => {
    alert('stdout: '+data);
  });

  hello.stderr.on('data', (data) => {
    alert('stderr: '+data);
  });

  hello.on('close', (code) => {
    alert('child process exited with code '+code);
  });
}
