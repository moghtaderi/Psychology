/* Jonathan Sekela
 * 4/14/2016
 * javascripts for backendExperiments with c++ and nodeJS
 */

function execute()
{
  $("#outMsg").html("what do i put here lol");
}


const spawn = require('child_process').spawn;
const ls = spawn('hello.exe', ['-lh', '/usr']);//changed 'ls' to 'hello.exe'

ls.stdout.on('data', (data) => {
  console.log(`stdout: ${data}`);
});

ls.stderr.on('data', (data) => {
  console.log(`stderr: ${data}`);
});

ls.on('close', (code) => {
  console.log(`child process exited with code ${code}`);
});
