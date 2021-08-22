<?php
function encode(string $str) : string
{
	return preg_replace_callback('/(.)\1+/', function ($match) { return strlen($match[0]) . $match[1]; }, $str);
}

function decode(string $str) : string
{
	return preg_replace_callback('/(\d+)(\D)/', function ($match) { return str_repeat($match[2], $match[1]); }, $str);
}
