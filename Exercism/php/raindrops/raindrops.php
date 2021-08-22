<?php

function raindrops(int $_n) : string
{
	$rain = '';
	if ($_n % 3 == 0) {
		$rain .= 'Pling';
	}

	if ($_n % 5 == 0) {
		$rain .= 'Plang';
	}

	if ($_n % 7 == 0) {
		$rain .= 'Plong';
	}

	if ($rain == '') {
		return $_n;
	} else {
		return $rain;
	}
}
