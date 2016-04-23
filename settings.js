var app=require('app')
var BrowserWindow=require('browser-window')
var ipc=require('ipc')
const ipcRenderer=require('electron').ipcRenderer;

app.on('ready',function() {
  var mainWindow=new BrowserWindow({
    width: 1400,
    height: 900
  })
  mainWindow.loadURL('file://' + ___dirname + '/index.html')

  var settingsWindow=new BrowserWindow ({
    width: 700,
    height: 900,
    show: false
  })
  settingsWindow.loadURL('file://' + __dirname + '/Settings.html')
  });

var settingsWindow = new BrowserWindow({width: 700, height: 900,
                                          show: false});
settingsWindow.loadURL('file://'+ __dirname + '/Settings.html');

ipc.on('show-settings', function() {
  settingsWindow.show();
});

function submitSettings(form)
{
  alert("THIS HAPPENS");
  var numOfNodes=form.numOfNodes.value;
  var weightIncrease=form.weightIncrease.value;
  var multiplierIncrease=form.weightIncrease.value;

  ipcRenderer.send('settingsSubmission',{func: 'changeSettings',
                                         params: [numOfNodes,weightIncrease,multiplierIncrease]});
  //close window
  settingsWindow.close();
}
