<?php

function isIsogram(string $_s) : bool
{
	$_s = mb_strtolower($_s, 'UTF-8');

	for($i = 0; $i < mb_strlen($_s); $i++) {
		for($j = $i + 1; $j < mb_strlen($_s); $j++) {
			if(mb_substr($_s, $i, 1) == mb_substr($_s, $j, 1) && $_s[$i] != ' ' && $_s[$i] != '-') {
				return false;
			}
		}
	}

	return true;
}
