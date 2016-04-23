const ipcRenderer=require('electron').ipcRenderer;


function showSettings()
{
  const BrowserWindow=require('electron').remote.BrowserWindow;
  var win=new BrowserWindow({width:700, height:900, show:false});
  win.on('closed',function() {
    win=null;
  });
  win.loadURL('file://' + __dirname + '/Settings.html');
  win.show();
}


ipcRenderer.on('settingsSubmission',function(event,data) {
  
}
