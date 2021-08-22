<?php
function twoFer(string $_s = '') : string {
	if(strlen($_s) == 0) {
		return 'One for you, one for me.';
	} else {
		return 'One for ' . $_s . ', one for me.';
	}
}
