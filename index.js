var remote=require('remote')
var Menu=remote.require('menu')

var menu=Menu.buildFromTemplate([
  {
    label: 'ASMSim',
    submenu: [
      label: 'Settings',
      click: function() {
        
      }
    ]
  }
])
Menu.setApplicationMenu(menu)
