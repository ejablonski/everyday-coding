<?php
function isLeap(int $_n) : bool
{
	if($_n % 4 == 0 && $_n % 100 != 0) {
		return true;
	} else {
		if($_n % 400 == 0) {
			return true;
		} else {
			return false;
		}
	}
}
