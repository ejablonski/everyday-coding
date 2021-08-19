<?php
function detectAnagrams(string $_word, array $_array) : array
{
	$array = [];
	foreach ($_array as $word) {
		if (count_chars(mb_strtolower($_word), 1) == count_chars(mb_strtolower($word), 1) 
			&& mb_strtolower($_word) != mb_strtolower($word)) {
			array_push($array, $word);
		}
	}
	return $array;
}
