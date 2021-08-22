<?php
function isPangram(string $_s) : bool
{
	$alphabet = range('a', 'z');
	$_s = str_split(strtolower($_s));

	if (array_diff($alphabet, $_s)) {
		return false;
	} else {
		return true;
	}
}
