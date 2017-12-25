#!/usr/bin/env php
<?php

$map = file_get_contents('build/firmware.map');

$at_flash = strpos($map, '.isr_vector     0x0000000008000000');//''.text           0x0000000008000000');
$at_ram   = strpos($map, '.data           0x0000000020000000');
$at_dbg   = strpos($map, '/DISCARD/');//.memory_b1_text

$discard = substr($map, 0, $at_flash);
$flash = substr($map, $at_flash, $at_ram - $at_flash);
$ram = substr($map, $at_ram, $at_dbg - $at_ram);

$flash = str_replace("lib/gcc/arm-none-eabi/5.3.0/../../../../", "", $flash);

file_put_contents("main.flash.map", $flash);
file_put_contents("main.ram.map", $ram);

$flash = preg_replace('/(\.(text|rodata)\.[^ ]*?)\n/', '$1', $flash);
$lines = explode("\n", $flash);

$sections = [];

foreach($lines as $l) {
  if ((false !== strpos($l, '0x0000000008')) && (false !== strpos($l, '.text.') || false !== strpos($l, '.rodata.'))) {
    //echo "$l\n";
    preg_match('/\s*.(text|rodata).([^ ]+)\s+0x00000000(08[\da-f]+)\s+0x([\da-f]+)\s+(.*)/', $l, $m);
    //print_r($m);
    $sec = new stdClass;
    $sec->type = $m[1]=='rodata'?'DATA':'CODE';
    $sec->name = $m[2];
    $sec->addr = "0x".$m[3];
    $sec->size = hexdec($m[4]);
    $sec->file = $m[5];

    if (($p=strrpos($sec->file, 'arm-none-eabi/')) !== false) {
      $sec->file = "\033[90m".substr($sec->file, $p)."\033[0m";
    } else {
      $sec->file = "\033[35m".str_replace("build/","",$sec->file)."\033[0m";
    }

    //print_r($sec);
    $sections[] = $sec;
  }
}

usort($sections, function($a,$b) {
  return -($a->size - $b->size);
});

echo "--- FLASH ---\n";
$limit = 40;
foreach($sections as $s) {
  if ($s->type=='DATA')echo "\033[33m";else echo "\033[32m";
  echo "{$s->type}\033[0m  {$s->addr}  \033[96m{$s->size}\033[0m\t".
    "\033[36m{$s->name}\033[0m";

  for($i=0;$i<36-strlen($s->name);$i++) echo " ";

  echo "{$s->file}\n";

  if($limit--==0) break;
}



$ram = preg_replace('/(\.(bss|data)\.[^ ]*?)\n/', '$1', $ram);
$lines = explode("\n", $ram);

$sections = [];
foreach($lines as $l) {
  if ((false !== strpos($l, '0x0000000020')) && (false !== strpos($l, '.bss.') || false !== strpos($l, '.data.'))) {
    //echo "$l\n";
    preg_match('/\s*.(bss|data).([^ ]+)\s+0x00000000(20[\da-f]+)\s+0x([\da-f]+)\s+(.*)/', $l, $m);
    //print_r($m);
    $sec = new stdClass;
    $sec->type = $m[1]=='bss'?'BSS ':'DATA';
    $sec->name = $m[2];
    $sec->addr = "0x".$m[3];
    $sec->size = hexdec($m[4]);
    $sec->file = $m[5];

    if (($p=strrpos($sec->file, 'arm-none-eabi/')) !== false) {
      $sec->file = "\033[90m".substr($sec->file, $p)."\033[0m";
    } else {
      $sec->file = "\033[35m".str_replace("build/","",$sec->file)."\033[0m";
    }

    //print_r($sec);
    $sections[] = $sec;
  }
}

usort($sections, function($a,$b) {
  return -($a->size - $b->size);
});

echo "\n--- RAM ---\n";
$limit = 20;
foreach($sections as $s) {
  if ($s->type=='DATA')echo "\033[33m";else echo "\033[32m";
  echo "{$s->type}\033[0m  {$s->addr}  \033[96m{$s->size}\033[0m\t".
    "\033[36m{$s->name}\033[0m";

  for($i=0;$i<36-strlen($s->name);$i++) echo " ";

  echo "{$s->file}\n";

  if($limit--==0) break;
}
