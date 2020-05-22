<?php

$f = fopen('luac.out', 'rb');
$sign = fread($f, 4);
var_dump(unpack('a4sign', $sign));
$version = fread($f, 1);
var_dump(unpack('cversion', $version));

$format = fread($f, 1);
var_dump(unpack('cformat', $format));

$data = '';
for ($i = 0; $i < 6; $i++) {
    $data .= fgetc($f);
}

var_dump(unpack('c6item', $data));


$intSize = fread($f, 5);
var_dump(unpack('c5', $intSize));

$intSize = fread($f, 2);
var_dump(unpack('c2luacInt', $intSize));

$intSize = fread($f, 8);
var_dump(unpack('c8', $intSize));



fclose($f);