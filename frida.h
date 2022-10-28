/**
 * based on code by Niel Cameron
 * this page forms the text for the HTML
 * Now it is one continous piece because there are no variables
 * Store array (page) data in flash (program) memory instead of SRAM, 
 * qualifeid by the PROGMEM modifier.
 * R"()" is a raw literal string.
 * 
 * This page is returned to client, on the client side, the javascript will
 * execute. THe JS/AJAX code is at end of the file
 */



char page[] PROGMEM = R"(
  
  <!DOCTYPE html><html><head>
  <title>Local network</title>
  <style>
  body {margin-top:50px; font-family:Arial}
  body {font-size:20px; text-align:center}
  .btn {display:block; width:280px; margin:auto; padding:30px}
  .btn {font-size:30px; color:black; text-decoration:none}
  .on {background-color:SkyBlue}
  .off {background-color:LightSteelBlue}
  .values {background-color:Thistle}
  td {font-size:30px; margin-top:50px; margin-bottom:5px}
  p {font-size:30px; margin-top:50px; margin-bottom:5px}
  </style></head>
  <body>
  <h1>Jude and Emmy local area network</h1>
  <table style='width:100%'><tr>
  <td>Motor is <span id='MANUAL'>OFF</span> now</td>
  <td>Manual State is <span id='MOTOR'>OFF</span> now</td>
  </tr></table>
  <table style='width:100%'><tr>
  <td><button class = 'btn off' id='Motor'
       onclick = 'sendData(id)'>Press to turn Motor ON
       </button></td>
       <td><button class = 'btn off' id='Manual State'
     onclick = 'sendData(id)'>Press to turn Manual State ON
     </button></td>
</tr></table>
<p>Water level <span id='counter'>0</span> now</p>
<button class = 'btn values' id = 'values'
     onclick = 'sendData(id)'>Press to see values</button>
<script>
function sendData(butn)
{
  var URL, variab, text;
  if(butn == 'Manual State') //change to Manual Mode
  {
    URL = 'Manualurl';
    variab = 'MOTOR';
  }
  else if(butn == 'Motor')  // turn Motor on or off
  {
    URL = 'Motorurl';
    variab = 'MANUAL';
  }
  else if(butn == 'values')  // Probably use it to display current water level reading
  {
    URL = 'valuesurl';
    variab = 'counter';
  }
  if(butn == 'Manual State' || butn == 'Motor')  // we might change this to find the state of the motor and automatic mode
{ // change button class and text 
  var state = document.getElementById(butn).className;
  state = (state == 'btn on' ? 'btn off' : 'btn on');
  text = (state == 'btn on' ? butn + ' OFF' : butn + ' ON');
    document.getElementById(butn).className = state;
    document.getElementById(butn).innerHTML = 'Press to turn ' + text;
  }
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function(butn)
  {
    if (this.readyState == 4 && this.status == 200)
    document.getElementById(variab).innerHTML = this.
    responseText;
  };
  xhr.open('GET', URL, true);
  xhr.send();
}
 
</script>
</body></html>
  
  
)";
