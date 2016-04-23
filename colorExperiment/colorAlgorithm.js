function colors(val)
{
  var color=val;
  color*=255;
  color=color | 0;
  retVal="000000"+color;
  return retVal;
}
